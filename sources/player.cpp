#include "player.hpp"

using namespace std;
namespace ariel
{
    //constructor
    Player::Player(string pName):playerName(pName){}
    int Player::stacksize(){ return cardsOwn.size();}
    int Player::cardesTaken(){ return cardsWon.size();}
    void Player::setplayerName(string n) {playerName = n;}
    string Player::getplayerName() {return playerName;}
    void Player::addCard(Card c){cardsOwn.push_back(c);}
    void Player::addWinCard(Card c){cardsWon.push_back(c);}

    void Player::addWinCount(){winCounter++;}
    int Player::getWinCount(){return winCounter;}

    Card Player::removeCard(){
        Card c(cardsOwn[cardsOwn.size()-1]);
        cardsOwn.pop_back();
        return c;
    }

    void Player::showcards(){
        for(unsigned int j = 0; j < cardsOwn.size(); j++)
        {
            cout << this->cardsOwn[j].getCardName() << " - " + to_string(cardsOwn[j].getCardValue()) << endl;
        }
    }

}
