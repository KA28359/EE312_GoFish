//
// Created by Kevin Aguilar on 4/15/20.
//

#include "player.h"
#include <iostream>
#include <cstdlib>

Player::Player() {

    myName = ""; //create blank player

}

void Player::addCard(Card c) {

    myHand.push_back(c); //add to vector

}

void Player::bookCards(Card c1, Card c2) {

    removeCardFromHand(c1);
    removeCardFromHand(c2);
    myBook.push_back(c1); //add to vector
    myBook.push_back(c2);


}

bool Player::checkHandForBook(Card &c1, Card &c2) {

    Card card1;
    Card card2;
    for(int i = 0; i < myHand.size(); i++){
        card1 = myHand[i];
        for(int j = i + 1; j < myHand.size(); j++){ //goes through the deck and checks if two cards match
            card2 = myHand[j];
            if(card1.getRank()==card2.getRank()){
                c1 = card1;
                c2 = card2;
                return true;
            }
        }
    }

    return false;

}

bool Player::rankInHand(Card c) const {

    for(int i=0; i<myHand.size(); i++){
        if(myHand[i].getRank() == c.getRank()) { //checks to see if given rank matches rank in a hand
            return true;
        }
    }
    return false;


}

Card Player::chooseCardFromHand() const {

    srand(time(0));
    int randCard = rand() % myHand.size(); //randomly choose a card from current hand
    return myHand[randCard];
}

bool Player::cardInHand(Card c) const {

    for(int i=0; i<myHand.size(); i++){
        if(myHand[i] == c)
            return true;
    }
    return false;
}

Card Player::removeCardFromHand(Card c) {

    Card temp;
    for (int i = 0; i < myHand.size(); i++) {
        if (myHand[i].getRank() == c.getRank()) { //finds card to remove and deletes it from the vector
            temp = myHand[i];
            myHand.erase(myHand.begin() + i);
            return temp;
        }
    }
}

string Player::showHand() const {

    string currentHand;
    for(int i=0; i<myHand.size(); i++){
        currentHand += myHand[i].toString() + " "; //goes through myHand vector and prints out the cards
    }
    return currentHand;
}

string Player::showBooks() const {

    vector<Card>::const_iterator i;
    string currentBooks;
    for(i=myBook.end() - 2; i!=myBook.end(); i++){ //goes through books vector and prints books
        currentBooks += (*i).toString() + " ";
    }
    return currentBooks;


}

int Player::getHandSize() const {

    return myHand.size();

}

int Player::getBookSize() const {

    return myBook.size();

}


