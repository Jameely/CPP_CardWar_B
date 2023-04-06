#include "player.hpp"

using namespace std;

namespace ariel
{
    Player::Player(string Name){
        this->Name=Name;
        this->win=false;
        this->size = 0;
        this->vectories=0;
    }
    int Player::stacksize(){return this->size;}

    void Player::SetStackSize(int size){this->size=size;}

    void Player::addCard(Card c){ 
        player_Cards.push(c);
        size++;
        } // to distribute the cards

    Card Player::Playcard(){
        size--;
        return this->player_Cards.top();
    }

    int Player::cardesTaken(){return PlayerWinningCards.size();}

    string Player::getname(){return Name;}

    void Player::WinCard(Card win , Card my){
        PlayerWinningCards.push_back(win);
        PlayerWinningCards.push_back(my);
        vectories++;
        this->player_Cards.pop();
        }
    void Player::LoseCard(){
        this->player_Cards.pop();
    }
    bool Player::iswin(){return this->win;}
    int Player::getvectories(){return vectories;}

}