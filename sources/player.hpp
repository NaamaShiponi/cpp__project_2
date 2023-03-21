#include <iostream>
using namespace std;

namespace ariel {

    class Player {
        string name;

    public:
        Player() { this->name = "anonimo"; }    // inline constructor
        Player(string name);  // constructor

        int stacksize();
        int cardesTaken();
    };
};