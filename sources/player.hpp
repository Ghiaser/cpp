#pragma once

#include "card.hpp"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

namespace ariel
{

class Player {                    // The class

private:                          //private Access specifier
    string playerName;            // Attribute
    int winCounter=0;               // Win Counter to count number of wins this player had
    vector<Card> cardsOwn;        //cards player have from begin of the game updated during the game
    vector<Card> cardsWon;        //cards players won from other player

public:                           // Access specifier
    Player(string pName);         // Constructor with parameters
    
    int stacksize();              // Cards amount left
    int cardesTaken();            // Cards player have won

    void setplayerName(string n); // Setter Name
    string getplayerName();       // Getter Name

    void addCard(Card c);         // add card to the player

    void addWinCard(Card c);      // add card that won from player 2 
    void addWinCount();           // increase win counter
    int getWinCount();            // get Win Counter

    Card removeCard();            // remove card from the player

    void showcards();             // print all cards player have (used for validation)

};

}