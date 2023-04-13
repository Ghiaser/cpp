#include "game.hpp"
#include <iostream>
#include <random>
namespace ariel
{
    Game::Game(Player& p1,Player& p2):playerNum_1(p1),playerNum_2(p2){
        /*  13 clubs ♣ | 13 diamonds ♦ | 13 hearts ♥ | 13 spades ♠ 
         each contain : ace, 2, 3, 4, 5, 6, 7, 8, 9, 10, jack, queen, and king */
        this->playerNum_1 = p1;
        this->playerNum_2 = p2;
        vector<Card> cards;
        this->draws=0;
        this->turns=0;
        int i;
        /* Set and insert all cards */
        // -----------      Set Clubs   -----------------------------
        cards.push_back(Card("Ace of Clubs",1));
        for (i = 2; i <= 10; i++) {
            cards.push_back(Card(to_string(i) + " of Clubs",i));
        }
        cards.push_back(Card("Jack of Clubs",11));
        cards.push_back(Card("Queen of Clubs",12));
        cards.push_back(Card("King of Clubs",13));

        // -----------      Set Diamonds   -----------------------------
        cards.push_back(Card("Ace of Diamonds",1));
        for (i = 2; i <= 10; i++) {
            cards.push_back(Card(to_string(i) + " of Diamonds",i));
        }
        cards.push_back(Card("Jack of Diamonds",11));
        cards.push_back(Card("Queen of Diamonds",12));
        cards.push_back(Card("King of Diamonds",13));

        // -----------      Set hearts   -----------------------------
        cards.push_back(Card("Ace of Hearts",1));
        for (i = 2; i <= 10; i++) {
            cards.push_back(Card(to_string(i) + " of Hearts",i));
        }
        cards.push_back(Card("Jack of Hearts",11));
        cards.push_back(Card("Queen of Hearts",12));
        cards.push_back(Card("King of Hearts",13));

        // -----------      Set Spades   -----------------------------
        cards.push_back(Card("Ace of Spades",1));
        for (i = 2; i <= 10; i++) {
            cards.push_back(Card(to_string(i) + " of Spades",i));
        }
        cards.push_back(Card("Jack of Spades",11));
        cards.push_back(Card("Queen of Spades",12));
        cards.push_back(Card("King of Spades",13));


        /* Shuffle the Cards */
        auto rng = std::default_random_engine {};
        std::shuffle(std::begin(cards), std::end(cards), rng);

        /* Add The Cards */
        for(unsigned int j = 0; j < 26; j++)
        {
            this->playerNum_1.addCard(cards[j]);
        }
        for(unsigned int j = 26; j < 52; j++)
        {
            this->playerNum_2.addCard(cards[j]);
        }
    }


    void Game::playTurn(){
        if(playerNum_1.getplayerName().empty() || playerNum_2.getplayerName().empty()){

            /* check if one or the two player has no initial name */
            throw invalid_argument("one or more player name is empty");
        }
        else if(playerNum_1.getplayerName() == playerNum_2.getplayerName()){

            /* check if the two players have the same name */
            throw invalid_argument("number players lower than two");
        }

        if(playerNum_1.stacksize() > 0 && playerNum_2.stacksize() > 0 ){
                vector<Card> player1Cards; // container to save all the cards of player1 he will win
                vector<Card> player2Cards; // container to save all the cards of player2 he will win
                bool draw = false;         // flag to warn there was a draw 

                /* start the turn with 2 cards and check for result -> save it to parameter ans*/
                player1Cards.push_back(playerNum_1.removeCard());
                player2Cards.push_back(playerNum_2.removeCard());
                int ans = player1Cards[player1Cards.size()-1].isEqual(player2Cards[player2Cards.size()-1]);

                /* ans = 1 means that player 1 win this turn and he should have the two cards */
                if(ans == 1){
                    /* add the two cards into the winning player container */
                    playerNum_1.addWinCard(player1Cards[player1Cards.size()-1]);
                    playerNum_1.addWinCard(player2Cards[player2Cards.size()-1]);
                    /* update the lastturnLog and also gamelog */
                    this->lastTurnLog = playerNum_1.getplayerName() + " played " + player1Cards[player1Cards.size()-1].getCardName() + " " + playerNum_2.getplayerName() + " played " + player2Cards[player2Cards.size()-1].getCardName() + ". " + playerNum_1.getplayerName() + " wins.\n";
                    this->gameLog += this->lastTurnLog;
                    this->gameLog += "\n";

                    /* take out the two cards from there lists */
                    player1Cards.pop_back();
                    player2Cards.pop_back();
                    playerNum_1.addWinCount();
                }

                /* ans = 2 means that player 2 win this turn and he should have the two cards */
                if(ans == 2){
                    /* add the two cards into the winning player container */
                    playerNum_2.addWinCard(player1Cards[player1Cards.size()-1]);
                    playerNum_2.addWinCard(player2Cards[player2Cards.size()-1]);
                    /* update the lastturnLog and also gamelog */
                    this->lastTurnLog = playerNum_1.getplayerName() + " played " + player1Cards[player1Cards.size()-1].getCardName() + " " + playerNum_2.getplayerName() + " played " + player2Cards[player2Cards.size()-1].getCardName() + ". " + playerNum_2.getplayerName() + " wins.\n";
                    this->gameLog += this->lastTurnLog;
                    this->gameLog += "\n";
                    
                    /* take out the two cards from there lists */
                    player1Cards.pop_back();
                    player2Cards.pop_back();
                    playerNum_2.addWinCount();
                }

                /* ans = 0 means the a draw happened so it will goes into a loop until we had a winner or cards out */
                if(ans == 0){
                    draw = true;  // turn on draw flag alert
                    this->lastTurnLog = "";
                }

                while (draw)
                {
                    this->draws++;  // Increase draws counter
                    /* update the lastturnLog and also gamelog */
                    this->lastTurnLog += playerNum_1.getplayerName() + " played " + player1Cards[player1Cards.size()-1].getCardName() + " " + playerNum_2.getplayerName() + " played " + player2Cards[player2Cards.size()-1].getCardName() + ". Draw. ";
                    this->gameLog += this->lastTurnLog;
                    
                    if(playerNum_1.stacksize() > 0 && playerNum_2.stacksize() > 0){
                            /* put two cards on side */
                            player1Cards.push_back(playerNum_1.removeCard());
                            player2Cards.push_back(playerNum_2.removeCard());

                            /* compare another two*/
                            player1Cards.push_back(playerNum_1.removeCard());
                            player2Cards.push_back(playerNum_2.removeCard());
                            ans = player1Cards[player1Cards.size()-1].isEqual(player2Cards[player2Cards.size()-1]);
                            if(ans != 0){ draw = false;}  // we got a winner draw flag turn off alert to exit the loop
                    }else{
                            /* we got a draw until we used all cards so return all cards to his owner */
                            for (unsigned i=0; i<player1Cards.size(); ++i){
                                playerNum_1.addCard(player1Cards[i]);
                                ans= -1;
                            }
                            for (unsigned j=0; j<player2Cards.size(); ++j){
                                playerNum_2.addCard(player2Cards[j]);
                                ans= -1;
                            }
                    }
                }

                /* after a draw loop finished check for the player that got the cards */
                if(ans == 1){
                    playerNum_1.addWinCount();
                    for (unsigned i=0; i<player1Cards.size(); ++i){
                        playerNum_1.addWinCard(player1Cards[i]);
                    }
                    for (unsigned j=0; j<player2Cards.size(); ++j){
                        playerNum_1.addWinCard(player2Cards[j]);
                    }
                }

                if(ans == 2){
                    playerNum_2.addWinCount();
                    for (unsigned i=0; i<player1Cards.size(); ++i){
                        playerNum_2.addWinCard(player1Cards[i]);
                    }
                    for (unsigned j=0; j<player2Cards.size(); ++j){
                        playerNum_2.addWinCard(player2Cards[j]);
                    }
                }
            this->turns++;
        }else{
            throw invalid_argument("Out of Cards");
        }
        
        

    }
    void Game::printLastTurn(){ cout << this->lastTurnLog << endl;}
    void Game::playAll(){
        /* play all the cards */
        while(playerNum_1.stacksize() > 0 && playerNum_2.stacksize() > 0){
            playTurn();
        }
    }
    void Game::printWiner(){
        if(playerNum_1.cardesTaken() > playerNum_2.cardesTaken()){
            this->winnerName = playerNum_1.getplayerName();
            cout << "Winner is: "<< this->winnerName<<endl;
        }
        else if(playerNum_2.cardesTaken() > playerNum_1.cardesTaken()){
            this->winnerName = playerNum_2.getplayerName();
            cout << "Winner is: "<< this->winnerName<<endl;
        }
        else
            throw invalid_argument("Draw !");
    }
    void Game::printLog(){cout << this->gameLog << endl;}
    void Game::printStats(){
        cout << playerNum_1.getplayerName() << ": \n" << "  Cards won: " << playerNum_1.cardesTaken() << "\n"<< "  Win rate: " << (static_cast<double>(playerNum_1.getWinCount())/this->turns) << endl;
        cout << playerNum_2.getplayerName() << ": \n" << "  Cards won: " << playerNum_2.cardesTaken() << "\n"<< "  Win rate: " << (static_cast<double>(playerNum_2.getWinCount())/this->turns) << endl;
        cout << "Number of draws: " << this->draws << "\n"<< ", Draw rate: " << static_cast<double>(this->draws)/static_cast<double>(this->turns) << endl;
    }
    void Game::draw(){draws++;}
    int Game::getDrawsCount(){return draws;}
    void Game::setwinName(string wn){this->winnerName=wn;}
    string Game::getwinName(){return this->winnerName;}
    string Game::getgameLog(){return gameLog;}
    string Game::getlastTurnLog(){return lastTurnLog;}

    bool generator()
    {
        int g = std::rand();
        return (g % 2); // 1 is converted to (player 1) and 0 to the second player
    }

}
