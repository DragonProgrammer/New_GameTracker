This is a rewrite of my first major project, submited as a final for my first Comp. Sci. class.

Old program did not transfer over all the way and say that it was a done almost entirely in Main(), I just started rewriting it from scratch.

Abamdon once i got a smart phone and relized there were several apps that did about the same thing.
_________________________________________________________________________________________________________________________________

Program would of asked for the type of game from the following options:

Type of Game: 1) Commander  2) 2-headed Giant 3) 60-card formats

Then it would ask how many players, or teams in the case of 2-headed, and check to make sure greater then 1.

It would then ask for each player, or team, to put in a set of initials for ID; checking that they did not put in the same as another or more then 3 letters.

It would then print out at table header with the ID of each player and the starting life total, gained from the type of game. For referance they are: Commander has 40, 2-headed has 30, and all other formats covered have 20.

During each players turn they would input the amount of life each player gained or lost. In the origanal this had been done with the inputs being put in in order of the table entering in zero for no change. The new one would steamline this by having a few commands to bypass entering, for NO CHANGE and PLAYER [id here] WINS, and using the id to change specific values. There would of been input checks at this point.

Each turn the changed life totals would be added to the table print out and anyone reaching 0 would be marked with a "L" for lose. When one or less players remained the winner would be printed out and the program would ask if you want to go again. If they did it would ask if it was the same format and sasme players. This would loop till someone said no more games.
_________________________________________________________________________________________________________________________________

A version of this will be added to the bigger MTG program I am doing once i get to implementing multiplayer.
