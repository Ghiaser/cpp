#include "card.hpp"
#include <iostream>
namespace ariel
{
    Card::Card(string cName,int cValue):cardName(cName),cardValue(cValue){}
    void Card::setNewCard(string cn,int cv){
        cardName = cn;
        cardValue = cv;
    }
    int Card::isEqual(Card c){
        if(this->cardValue > c.cardValue){
            return 1;
        }else{
            if(this->cardValue < c.cardValue){
                return 2;
            }
            return 0;
        }
    }
    string Card::getCardName(){
        return cardName;
    }
    int Card::getCardValue(){
        return cardValue;
    }
}
