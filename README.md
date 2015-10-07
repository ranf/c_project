
WELCOME to our CHESS Game[!](https://github.com/ranf/c_project)
===============================================================

In the main window you can choose between 3 options:

1. `New Game` - creates a new game.
2. `Load Game` - loads a game that was saved.
3. `Quit`


## New Game Settings

After you click on new game, you choose its mode, `Player vs Player` or `Player vs Computer`.

If you choose `Player vs Player` you need to choose the next player (who starts) and then you can move to the game window.

If you choose `Player vs Computer`, you need to choose the next player as well, but also to choose your color (White/Black) and the difficulty (the depth minimax algorithm that calculates the best move, or `best` which will perform various optimizations and select the best depth to suit both difficulty and performance). After that, you can move to the game window.


## Game Window

In the game window, before the game starts you can change the board (as long as it is a legal change) by clicking each time "set board" button and then selecting the piece that you want to change. After you are done, you can click the `Start Game` button and the game starts, remember you can NOT change the board after the game has started.

During the game, you may ask for a hint, by clicking the `Hint` button, the hint will highlight the piece you should move, and then highlight its target. If you play against other player (`Player vs Player` mode), you need to choose the difficulty of the minimax algorithm that will calculate your best move, and then the move will be shown on the board. If you choose `Player vs Computer` mode, the move will be shown on the board immediately after you clicked the `Hint` using the difficulty of the AI you are playing against.

When the game will end (Mate/Tie) an appropriate message will be displayed, and afterwards you will return back to the main window.
You can also click the `Main Menu` button to return to it, or use the `Quit` button to exit the program.


## Save / Load
At any stage at the game you can save the game (using the `Save` button), if there was a game in the slot that you choose, the current game will overwrite it. 

From the main window you can select the `Load Game` button, which will ask you to choose a game to load, and play from the point the game was saved. You will be able to modify the game settings and its board like you did for the new game.
