#include "card.hpp"

namespace ariel{
    Card::Card(string card, int value){
        this->card=card;
        this->value=value;
    } //parametric constructor
    int Card::getvalue(){return this->value;}
    string Card::getcard(){return this->card;}
    int Card::isGreater(Card Another){
        if (this->getvalue() > Another.getvalue()){
            return 1;
        }
        else if(this->getvalue() < Another.getvalue()){
            return -1;
        }
        else return 0;
        }
    } //The Function That compare the cards