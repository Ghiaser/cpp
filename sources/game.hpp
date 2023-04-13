#pragma once

#include <stack>
#include "player.hpp"
#include "card.hpp"

using namespace std;


namespace ariel
{
class Game {                    // The class
private:                        //private Access specifier
    Player& playerNum_1;         // Attribute
    Player& playerNum_2;         // Attribute
    string gameLog;             // all turns stats
    string lastTurnLog;         // last turn stats
    int draws;                  // Count number of draws happened
    string winnerName;          // Winner name
    int turns;          // Winner name

    /*  13 clubs ♣ | 13 diamonds ♦ | 13 hearts ♥ | 13 spades ♠ 
         each contain : ace, 2, 3, 4, 5, 6, 7, 8, 9, 10, jack, queen, and king */

    stack<Card> stack;

public:                         // Access specifier
    Game(Player& p1,Player& p2);  // Constructor with parameters

    void playTurn();
    void printLastTurn();       // print the last turn stats
    void playAll();             // playes the game untill the end
    void printWiner();          // Winner Player's name
    void printLog();            // prints all the turns played one line per turn
    void printStats();          // player basic statistics
    void draw();                // Increase draws counter by 1
    int getDrawsCount();        // getter for counter of draws variable
    void setwinName(string wn); // setter for winner name variable
    string getwinName();        // getter for winner name variable
    string getgameLog();        // getter for gamelog
    string getlastTurnLog();        // getter for last turn log   

};
}