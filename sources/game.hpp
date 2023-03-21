#include <iostream>

using namespace std;

namespace ariel {
    class Game {
        Player* player1;
        Player* player2;


    public:
        Game() { this->player1 = new Player(); this->player2 = new Player(); }    // inline constructor
        ~Game();
        Game(Player player1,Player player2);  // constructor

        void playTurn();
        void printLastTurn();
        void playAll();
        void printWiner(); 
        void printLog(); 
        void printStats();
        

    };
};