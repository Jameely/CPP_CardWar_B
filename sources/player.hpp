#pragma once

#include "card.hpp"
#include <string>
#include <stack>
#include <list>

using namespace std;

namespace ariel{
    class Player
    {
    private:
        string Name;
        bool win; //at the end of the game every playet should know if he is the winner or not.
        stack <Card> player_Cards;//The players Cards
        list <Card> PlayerWinningCards; //The Cards that the player win
        int size; //stack size
        int vectories; // number of the vectories (should update during the game)
    public:
        Player(string Name); //parametric constructor , just for testing , we shouldn't have another attributes.
        void addCard(Card card); // to distribute the cards
        int stacksize(); //The number of cards left , it should update during the game.
        int cardesTaken(); //The Number of cards win , it shoul update win the player win a round
        void WinCard(Card win, Card mycard); // this is the function that will update the winning cards and the winning rate...
        void LoseCard(); // Lose card
        string getname(); //getter
        bool iswin(); //return True if The Player win 
        Card Playcard(); //play a card , remove from the stack , return the card 
        int getvectories(); //getter
        void SetStackSize(int size); //setter

    };
    
}