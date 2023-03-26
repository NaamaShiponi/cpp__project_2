#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
using namespace std;

namespace ariel {

    class Player {
        string name;

    public:
        Player() { this->name = "anonimo"; }    // inline constructor
        Player(string name);// constructor
        ~Player();

        int stacksize();
        int cardesTaken();


    };
};
#endif