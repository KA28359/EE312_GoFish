// FILE: card_demo.cpp
// This is a small demonstration program showing how the Card and Deck classes are used.
#include <iostream>    // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include "card.h"
#include "player.h"
#include "deck.h"

using namespace std;


// PROTOTYPES for functions used by this demonstration program:
void dealHand(Deck &d, Player &p, int numCards);




int main( )
{
    int numCards = 7; //dependent upon number of players

    Player p1("Joe");
    Player p2("Jane"); //edit player names

    Deck d;  //create a deck of cards
    d.shuffle();

    dealHand(d, p1, numCards);
    dealHand(d, p2, numCards);

    cout<<endl;

    cout << p1.getName() <<" has : " << p1.showHand() << endl;
    cout << p2.getName() <<" has : " << p2.showHand() << endl;

    cout<<endl;

    // ////////////////////////////////////////////////////////////////////////////
    Card firstCard;
    Card secondCard;
    Card newCard;
    Card p1Card;
    Card p2Card;
    Card bookedCard;

    while(p1.checkHandForBook(firstCard, secondCard) == true){ //get rid of initial pairs
        p1.bookCards(firstCard, secondCard);
        cout<<p1.getName()<<" books the "<<p1.showBooks()<<endl;
    }

    cout<<endl;


    while(p2.checkHandForBook(firstCard, secondCard) == true){
        p2.bookCards(firstCard, secondCard);
        cout<<p2.getName()<<" books the "<<p2.showBooks()<<endl;
    }

    while (d.size() >= 0) { //keep going until we run out of cards

        int p1turn = 1;
        int p2turn = 0;

        while(p1turn == 1) {    //player 1 goes first
            cout<<endl;
            if((p1.getHandSize() == 0) && (d.size() != 0)){ //player one gets a new card from pile after they run out
            newCard = d.dealCard();
            p1.addCard(newCard);
            cout<<p1.getName()<<" draws "<<newCard.toString()<<endl;
        }


        if((p1.getHandSize() == 0) && (d.size() == 0)){ // player 1 has no cards and no more left on deck thus game is over

            int p1NumOfBooks = p1.getBookSize()/2;
            int p2NumOfBooks = p2.getBookSize()/2;      //calculate both players final books
            cout<<"Game Over"<<endl;
            cout<<p1.getName()<<" got "<< p1NumOfBooks<<" books"<<endl;
            cout<<p2.getName()<<" got "<< p2NumOfBooks<<" books"<<endl;
            if (p1NumOfBooks < p2NumOfBooks) {
                cout<<p2.getName()<<" wins"<<endl;
            }
            if (p1NumOfBooks > p2NumOfBooks) {
                cout<<p1.getName()<<" wins"<<endl;
            }
            if (p1NumOfBooks == p2NumOfBooks) {
                cout<<"Both players tied"<<endl;
            }

            return 0;

        }


            p1Card = p1.chooseCardFromHand();   //pick a random card from player 1 current hand
            cout << p1.getName() << " asks - Do you have a " << p1Card.rankString(p1Card.getRank()) << "?" << endl;
            if (p2.rankInHand(p1Card)) {
                int counter = 0;
                while (p2.rankInHand(p1Card)) {
                    bookedCard = p2.removeCardFromHand(p1Card); //if player 2 has card called, get it and book it
                    p1.addCard(bookedCard);
                    counter = counter + 1;
                }
                if (counter == 1) {
                    cout << p2.getName() << " says - Yes. I have a " << p1Card.rankString(p1Card.getRank()) << endl;
                }
                if (counter > 1) {
                    cout << p2.getName() << " says - Yes. I have " << counter << " "
                         << p1Card.rankString(p1Card.getRank()) << "'s" << endl;
                }
                while (p1.checkHandForBook(firstCard, secondCard)) { //book the pair
                    p1.bookCards(firstCard, secondCard);
                    cout << p1.getName() << " books the " << p1.showBooks() << endl;
                }
            }

            if ((p2.rankInHand(p1Card) == false) && (p1.rankInHand(p1Card) == true)) { //go fish code

                cout << p2.getName() << " says - Go FIsh" << endl;
                newCard = d.dealCard();
                p1.addCard(newCard);
                cout << p1.getName() << " draws " << newCard.toString() << endl;
                while(p1.checkHandForBook(firstCard, secondCard) == true){ //if card gotten on go fish gives a pair book it
                    p1.bookCards(firstCard, secondCard);
                    cout<<p1.getName()<<" books the "<<p1.showBooks()<<endl;
                }
                p1turn = 0;
                p2turn = 1;//change turns
            }
        }


        while(p2turn == 1) { //player 2 turn
            cout<<endl;
            if((p2.getHandSize() == 0) && (d.size() != 0)){ //if player 2 ran out of cards, get another from pile
                newCard = d.dealCard();
                p2.addCard(newCard);
                cout<<p2.getName()<<" draws "<<newCard.toString()<<endl;
            }


            if((p2.getHandSize() == 0) && (d.size() == 0)){ //if player 2 ran out of cards and no more in deck game over

                int p1NumOfBooks = p1.getBookSize()/2;
                int p2NumOfBooks = p2.getBookSize()/2;
                cout<<"Game Over"<<endl;
                cout<<p1.getName()<<" got "<< p1NumOfBooks<<" books"<<endl;
                cout<<p2.getName()<<" got "<< p2NumOfBooks<<" books"<<endl;
                if (p1NumOfBooks < p2NumOfBooks) {
                    cout<<p2.getName()<<" wins"<<endl;
                }
                if (p1NumOfBooks > p2NumOfBooks) {
                    cout<<p1.getName()<<" wins"<<endl;
                }
                if (p1NumOfBooks == p2NumOfBooks) {
                    cout<<"Both players tied"<<endl;
                }

                return 0;

            }


            p2Card = p2.chooseCardFromHand(); //pick a random card from player 2 current pile
            cout << p2.getName() << " asks - Do you have a " << p2Card.rankString(p2Card.getRank()) << "?" << endl;
            if (p1.rankInHand(p2Card)) {
                int counter = 0;
                while (p1.rankInHand(p2Card)) {
                    bookedCard = p1.removeCardFromHand(p2Card); //take card from player 1
                    p2.addCard(bookedCard);
                    counter = counter + 1;
                }
                if (counter == 1) {
                    cout << p1.getName() << " says - Yes. I have a " << p2Card.rankString(p2Card.getRank()) << endl;
                }
                if (counter > 1) {
                    cout << p1.getName() << " says - Yes. I have " << counter << " "<< p2Card.rankString(p2Card.getRank()) << "'s" << endl;
                }
                while (p2.checkHandForBook(firstCard, secondCard)) { //book the card received
                    p2.bookCards(firstCard, secondCard);
                    cout << p2.getName() << " books the " << p2.showBooks() << endl;
                }
            }

            if ((p1.rankInHand(p2Card) == false) && (p2.rankInHand(p2Card) == true)) { //go fish for player 2

                cout << p1.getName() << " says - Go Fish" << endl;
                newCard = d.dealCard();
                p2.addCard(newCard);
                cout << p2.getName() << " draws " << newCard.toString() << endl;
                while(p2.checkHandForBook(firstCard, secondCard) == true){ //if drawn card is makes a pair, book it
                    p2.bookCards(firstCard, secondCard);
                    cout<<p2.getName()<<" books the "<<p2.showBooks()<<endl;
                }
                p1turn = 1;
                p2turn = 0;//change turns
            }
        }




    }



    return EXIT_SUCCESS;
}



void dealHand(Deck &d, Player &p, int numCards)
{
    for (int i=0; i < numCards; i++)
        p.addCard(d.dealCard());
}



