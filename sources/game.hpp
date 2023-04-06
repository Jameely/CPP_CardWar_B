#pragma once

#include <stack>
#include "player.hpp"
#include "card.hpp"

using namespace std;

namespace ariel
{
    class Game
    {
    private:
        Player& First_player ; //player 1
        Player& Second_player; //player 2
        string log ; //should print all the game
        string lastturnlog; //should print the last log
        string winner; // the winner at the end of the game
        stack<Card> Stack; // must be private
        stack<Card> drawfirst;
        stack<Card> drawsecond;
//        stack<Card> stack; 
        // should hold 52 cards .
        //13 Hearts.
        //13 Spades.
        //13 Diamonds.
        //13 Clubs.

    public:
        Game(Player& first , Player& second);  //parametric constructor
        void playTurn();                // play turn
        void printLastTurn();           // should print the last turn like "Alice put Q-Hearts , Bob put K-Diamonds . Bob Take The Cards"
        void playAll();                 // play the game
        void printWiner();              // print the winner
        void printLog();                // print all the game 
        void printStats();              // print stats
        void getRoundsNumber();         // return the rounds 
        void setWinner(string win);  // hold Winner
        void setcards();  //set the 52 wanted card
        string getWinner();             // Return The Winner
        // in this function we distribute the cards
        //in case 0 the first player will take the card 
        // in case 1 the second player will take the card 
        // if one have 26 cards the other will take all the cards 
        void distributecards(); // random distribute
    };

    
}