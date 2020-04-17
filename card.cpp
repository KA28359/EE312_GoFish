//
// Created by Kevin Aguilar on 4/15/20.
//

#include "card.h"
#include <string>

using namespace std;

Card::Card() {

    mySuit = spades; //makes the standard card the A of spades
    myRank = 1;

}

Card::Card(int rank, Card::Suit s) {

    myRank = rank;
    mySuit = s;

}

string Card::toString() const {

    string output;
    output = rankString(myRank);
    output = output + suitString(mySuit); //convert the card to string
    return output;

}

bool Card::sameSuitAs(const Card &c) const {

    return mySuit == c.mySuit;

}

int Card::getRank() const {

    return myRank;


}

string Card::suitString(Card::Suit s) const {

    string output = " ";
    if(s == clubs)
        return output = "c";
    else if(s == spades)
        return output = "s"; //convert suit to abbreviation
    else if(s == hearts)
        return output = "h";
    else output = "d";
    return output;
}

bool Card::operator==(const Card &rhs) const {

    return(this->myRank == rhs.myRank && this->mySuit == rhs.mySuit);

}

string Card::rankString(int r) const {

    string output = " ";
    if(r == 1)
        return "A";
    else if(r == 2)
        return "2";
    else if(r == 3)
        return "3";
    else if(r == 4)
        return "4"; //convert number to string
    else if(r == 5)
        return "5";
    else if(r == 6)
        return "6";
    else if(r == 7)
        return "7";
    else if(r == 8)
        return "8";
    else if(r == 9)
        return "9";
    else if(r == 10)
        return "10";
    else if(r == 11)
        return "J";
    else if(r == 12)
        return "Q";
    else if(r == 13)
        return "K";
    return output;

}

bool Card::operator!=(const Card &rhs) const {

    return(this->myRank == rhs.myRank && mySuit != rhs.mySuit);

}

