#include "doctest.h"
#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"
#include <stdexcept>
#include <iostream>


using namespace std;
using namespace ariel;

TEST_CASE("Player tests before a game")
{
    Player p1("Alice");
    Player p2("Alice");
    CHECK_THROWS(p1.cardesTaken()); 
    CHECK_THROWS(p1.stacksize());

    CHECK(&p1!= &p2); //Although they have the same they are different
    
  








}


TEST_CASE("Game tests before a game"){
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);
    CHECK_THROWS(game.printLastTurn());// Print the last turn and the game hasn't started yet
    CHECK_THROWS(game.printWiner()); // Print the winner and the game is not over yet
    CHECK_THROWS(game.printLog()); // Print a log and the game hasn't started yet

}


TEST_CASE("Game tests during the game"){
    Player p1("Alice");
    Player p2("Bob");
    Game game1(p1, p2);
    game1.playAll();
    CHECK_THROWS(game1.playTurn());
    CHECK_THROWS(game1.playAll());



    Player p3("Arad");
    Player p4("Ben");
    Game game2(p3, p4);
    game2.playTurn();
    CHECK(p3.stacksize()<26);
    CHECK(p4.stacksize()<26);
    bool cardesTakenNot0= p3.cardesTaken()>0 || p4.cardesTaken()>0;
    CHECK(cardesTakenNot0);
    CHECK((p3.stacksize()+p3.cardesTaken())+(p4.cardesTaken()+p4.stacksize())==52);
    CHECK_THROWS(game2.printWiner()); //There is no winner yet because the game is never over
    
    while (p3.stacksize()!=0 && p4.stacksize() != 0)
    {
        game2.playTurn();
        CHECK_THROWS(game2.printWiner()); //There is no winner yet because the game is never over
    }



}


TEST_CASE("Player tests during the game"){

    Player p1("Naama");
    Player p2("Tomer");
    Game game(p1, p2);
    CHECK(p1.cardesTaken()==0); 
    CHECK(p2.cardesTaken()==0); 
    CHECK(p1.stacksize()== 26);
    CHECK(p2.stacksize()== 26);
    while (p1.stacksize()!=0 && p2.stacksize() != 0)
    {
        game.playTurn();
        CHECK((p1.stacksize()+p1.cardesTaken())+(p2.cardesTaken()+p2.stacksize())==52);
    }

    Player p3("Arad");
    Player p4("Ben");
    Game game1(p3, p4);
    game1.playAll();
    CHECK((p3.cardesTaken()+p4.cardesTaken())==52);
    CHECK(p3.stacksize()==0);
    CHECK(p4.stacksize()==0);


 
}

