#pragma once
#include <string>

using namespace std;

namespace ariel{
    class Card    // the class card
    {
    private: 
        int value; // A card should have a value to compare with the other card.
        string card; //The Card
    public:  //prametric constructor , we don't need another constructor 
        Card(string card ,int value);
        int getvalue();
        string getcard();
    //This is the function that check who win the current round ,
    //win   : return  1
    //equals: return  0
    //lose  : return -1
    int isGreater(Card Another); 
    };
}