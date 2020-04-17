//
// Created by Kevin Aguilar on 4/15/20.
//

#include "deck.h"
#include <iostream>
#include <cstdlib>

Deck::Deck() {

    int counter = 0;
    myIndex = 0;
    for(int currentSuit = 0; currentSuit < 4; currentSuit++){ //put the deck in new deck order
        for(int currentRank = 1; currentRank < 14; currentRank++){
            myCards[counter] = Card(currentRank, Card::Suit(currentSuit));
                    counter++;
        }
    }

}

void Deck::shuffle() {

    srand(time(0)); //random number generator
    if (myIndex == 0) {
        int i1;
        int i2;
        int randNum = rand() % 50 + 104;
        for (int i = 0; i < randNum; i++) {
            i1 = rand() % 52;
            i2 = rand() % 52;
            Card temp = myCards[i1]; //switch location of two cards
            myCards[i1] = myCards[i2];
            myCards[i2] = temp;
        }
    }


}

Card Deck::dealCard() {

    Card card(0, static_cast<Card::Suit>(0));
    if(size() >= 1){
        card = myCards[myIndex];
        myIndex++;
    }
    return card;
}

int Deck::size() const {
    return SIZE - myIndex;
}

