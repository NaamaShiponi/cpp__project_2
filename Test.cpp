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
    CHECK_THROWS(p1.cardesTaken()); //A man without a game should have no result in a function
    CHECK_THROWS(p1.stacksize()); //A man without a game should have no result in a function

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
    CHECK_THROWS(game1.playTurn()); // After the game is over we cannot play another turn
    CHECK_THROWS(game1.playAll()); // After the game is over we cannot play it again

    Player p3("Arad");
    Player p4("Ben");
    Game game2(p3, p4);
    game2.playTurn();
    CHECK(p3.stacksize()<26); //After a turn is played in a game, the amount of cards in his pile should decrease
    CHECK(p4.stacksize()<26); //After a turn is played in a game, the amount of cards in his pile should decrease
    bool cardesTakenNot0= p3.cardesTaken()>0 || p4.cardesTaken()>0;
    CHECK(cardesTakenNot0); //After playing one turn in the game one of the players should have more than 0 cards in the cardesTaken column
    CHECK((p3.stacksize()+p3.cardesTaken())+(p4.cardesTaken()+p4.stacksize())==52);
    CHECK_THROWS(game2.printWiner()); //There is still no winner because the game is not over
    
    while (p3.stacksize()!=0 && p4.stacksize() != 0)//Loop until the game is over
    {
        game2.playTurn();
        CHECK_THROWS(game2.printWiner()); //There is still no winner because the game is not over
    }

}



TEST_CASE("Player tests during the game"){

    Player p1("Naama");
    Player p2("Tomer");
    Game game(p1, p2);
    CHECK(p1.cardesTaken()==0); // At the beginning of the game there are no cards taken
    CHECK(p2.cardesTaken()==0); // At the beginning of the game there are no cards taken
    CHECK(p1.stacksize()== 26); // At the beginning of the game the cards were divided half and half
    CHECK(p2.stacksize()== 26); // At the beginning of the game the cards were divided half and half
    while (p1.stacksize()!=0 && p2.stacksize() != 0)//Loop until the game is over
    {
        game.playTurn();
        CHECK((p1.stacksize()+p1.cardesTaken())+(p2.cardesTaken()+p2.stacksize())==52); //Throughout the game there are 52 cards in the pack
    }

    Player p3("Arad");
    Player p4("Ben");
    Game game1(p3, p4);
    game1.playAll();
    CHECK((p3.cardesTaken()+p4.cardesTaken())==52);// At the end of the game, the sum of the two piles of cards taken is 52
    CHECK(p3.stacksize()==0); // At the end of the game there are no cards in the pile
    CHECK(p4.stacksize()==0); // At the end of the game there are no cards in the pile

}

