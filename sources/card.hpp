#pragma once

#include <string>

using namespace std;

namespace ariel
{

class Card {                             // The class

private:                                 //private Access specifier
    int cardValue;                       // Attribute
    string cardName;                     // Attribute

public:                                  // Access specifier
    Card(string cardName,int cardValue); // Constructor with parameters
    
    void setNewCard(string cn,int cv);   // change Card name and value
    int isEqual(Card c);                 // function that compare two Cards return {0} if equals else return {1} if the card bigger than c else {2} 
    string getCardName();                // getter for card name
    int getCardValue();                  // getter for card value
};

}