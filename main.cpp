#include <iostream>
#include "Game.h"

//My previous class based approach is not helping and is causing more trouble than it's worth.
//Squirreling my functions away into subfunctions (Update -> smaller function)
//is causing more trouble than it's ever solving. So I'll be fusing OOP with a more functional style.
//Functions should seek to be code re-use only isntead of just abstracting/encapsulating for the sake
//of it. 

//I initially thought that these this statements would help me organize what was where in scope but
//now I'm not so sure this is working. It seems like things are getting less clear.
//Maybe. I'll have to reread my code about a month out from now.

int main() {
    
    Game game;

    while (game.IsRunning()) {
        game.Update();
        game.Render();
    }
    return 0;
}
