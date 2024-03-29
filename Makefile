XX         = g++
LIBARYFLAGS = 
CXXFLAGS    = -std=c++1z -Wall -Wextra -Wparentheses -g $(SANS)

.PHONY:all seg msan
all: format TAGS deps mains
seg: clean msan
msan:
	make --no-print-directory all SANS=-fsanitize=address

# generate the etags file
TAGS:
	@rm -f TAGS
	@ls|grep "pp$$"|xargs -r etags -a
	@echo "Generated Tags"

# use the etags file to find all excicutables
.PHONY:mains
mains:
	@for f in `ls *.c*` ; do \
		if etags $$f -o - | grep "int main(" - > /dev/null; \
			then echo $$f | sed -e 's/[.][^.]*$$/.bin/' -e 's/.*/make --no-print-directory &/' |sh; \
		fi ; \
	done

.PHONY:deps
deps:
	-@for f in `ls *.cpp` ; do \
		echo $$f | sed -e 's,cpp$$,d,' -e 's/.*/make -s .d\/&/'|sh; \
	done

# dependancy making
DEPDIR      = .d
$(shell mkdir -p $(DEPDIR) > /dev/null)
.PRECIOUS: $(DEPDIR)/%.d
$(DEPDIR)/%.d: %.cpp
	@set -e; rm -f $@; \
	 $(CXX) -MM $(CXXFLAGS) $< > $@.$$$$; \
	 sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	 sed -e 's,[.]o\([ :]\),.bin\1,g' -e 's,[.][hc]pp\>,.o,g' -e 's,\<[a-zA-Z]*[.]tpp\>,,g' < $@.$$$$ >> $@; \
	 printf '\t$$(CXX) $$(CXXFLAGS) $$(LIBARYFLAGS) -o $$@ $$^' >> $@; \
	 echo >> $@; \
	 rm -f $@.$$$$
	@echo "remade $@"

# emacs flycheck-mode
.PHONY:check-syntax csyntax
check-syntax: csyntax
csyntax:
	$(CXX) $(CXXFLAGS) -c ${CHK_SOURCES} -o /dev/null

.PHONY: clean
clean:
	rm -f *.o *.bin .d/*.d
	rmdir .d

.PHONY: format
format:
	@find|egrep '.*[.](cpp|cxx|cc|c++|c|tpp|txx)$$'|sed 's/[] ()'\''\\[&;]/\\&/g'|xargs clang-format-6.0 -i
	@echo "reformatted code"

.PHONY: tidy
tidy:
	clang-tidy-6.0 *.cpp -checks="*" -- $(CXXFLAGS)

include $(wildcard $(DEPDIR)/*.d)
include $(wildcard *.d)
