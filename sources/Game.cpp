#include "stdlib.h"
#include <iostream>
#include <stdexcept>
#include "game.hpp"

namespace ariel
{
    Game::Game(Player& First , Player& Second):First_player(First),Second_player(Second){
        lastturnlog="";
        log="";
        try{
            distributecards();
        }
        catch(std::exception& e){
            cerr << "An Error ocuured during the distribute of the cards" << e.what() <<endl;
        }
    }
    void Game::setcards(){
        Card c1("Ace of Hearts",1);
        Card c2("2 of Hearts",2);
        Card c3("3 of Hearts",3);
        Card c4("4 of Hearts",4);
        Card c5("5 of Hearts",5);
        Card c6("6 of Hearts",6);
        Card c7("7 of Hearts",7);
        Card c8("8 of Hearts",8);
        Card c9("9 of Hearts",9);
        Card c10("10 of Hearts",10);
        Card c11("Jack of Hearts",11);
        Card c12("Queen of Hearts",12);
        Card c13("King of Hearts",13);

        Card c14("Ace of Spades",1);
        Card c15("2 of Spades",2);
        Card c16("3 of Spades",3);
        Card c17("4 of Spades",4);
        Card c18("5 of Spades",5);
        Card c19("6 of Spades",6);
        Card c20("7 of Spades",7);
        Card c21("8 of Spades",8);
        Card c22("9 of Spades",9);
        Card c23("10 of Spades",10);
        Card c24("Jack of Spades",11);
        Card c25("Queen of Spades",12);
        Card c26("King of Spades",13);

        Card c27("Ace of Diamonds",1);
        Card c28("2 of Diamonds",2);
        Card c29("3 of Diamonds",3);
        Card c30("4 of Diamonds",4);
        Card c31("5 of Diamonds",5);
        Card c32("6 of Diamonds",6);
        Card c33("7 of Diamonds",7);
        Card c34("8 of Diamonds",8);
        Card c35("9 of Diamonds",9);
        Card c36("10 of Diamonds",10);
        Card c37("Jack of Diamonds",11);
        Card c38("Queen of Diamonds",12);
        Card c39("King of Diamonds",13);        

        Card c40("Ace of Clubs",1);
        Card c41("2 of Clubs",2);
        Card c42("3 of Clubs",3);
        Card c43("4 of Clubs",4);
        Card c44("5 of Clubs",5);
        Card c45("6 of Clubs",6);
        Card c46("7 of Clubs",7);
        Card c47("8 of Clubs",8);
        Card c48("9 of Clubs",9);
        Card c49("10 of Clubs",10);
        Card c50("Jack of Clubs",11);
        Card c51("Queen of Clubs",12);
        Card c52("King of Clubs",13);
        this->Stack.push(c1);
        this->Stack.push(c2);
        this->Stack.push(c3);
        this->Stack.push(c4);
        this->Stack.push(c5);
        this->Stack.push(c6);
        this->Stack.push(c7);
        this->Stack.push(c8);
        this->Stack.push(c9);
        this->Stack.push(c10);
        this->Stack.push(c11);
        this->Stack.push(c12);
        this->Stack.push(c13);
        this->Stack.push(c14);
        this->Stack.push(c15);
        this->Stack.push(c16);
        this->Stack.push(c17);
        this->Stack.push(c18);
        this->Stack.push(c19);
        this->Stack.push(c20);
        this->Stack.push(c21);
        this->Stack.push(c22);
        this->Stack.push(c23);
        this->Stack.push(c24);
        this->Stack.push(c25);
        this->Stack.push(c26);
        this->Stack.push(c27);
        this->Stack.push(c28);
        this->Stack.push(c29);
        this->Stack.push(c30);
        this->Stack.push(c31);
        this->Stack.push(c32);
        this->Stack.push(c33);
        this->Stack.push(c34);
        this->Stack.push(c35);
        this->Stack.push(c36);
        this->Stack.push(c37);
        this->Stack.push(c38);
        this->Stack.push(c39);
        this->Stack.push(c40);
        this->Stack.push(c41);
        this->Stack.push(c42);
        this->Stack.push(c43);
        this->Stack.push(c44);
        this->Stack.push(c45);
        this->Stack.push(c46);
        this->Stack.push(c47);
        this->Stack.push(c48);
        this->Stack.push(c49);
        this->Stack.push(c50);
        this->Stack.push(c51);
        this->Stack.push(c52);  
    }
    void Game::distributecards(){
        setcards();
        int player=0;
        for(int i=1 ; i<= 52 ; i++){
            player=rand()%2;
            if(!(this->Stack.empty())){
                if(player==0)
                {
                    if (this->First_player.stacksize()<26)
                    {
                        if(!(this->Stack.empty())){
                            this->First_player.addCard(this->Stack.top());
                        }
                    }
                    else
                    {
                        this->Second_player.addCard(this->Stack.top());

                    }
                }
                else
                {
                    if (this->Second_player.stacksize()<26)
                    {
                        this->Second_player.addCard(this->Stack.top());
                    }
                    else
                    {
                        this->First_player.addCard(this->Stack.top());
                    }
                }
                this->Stack.pop(); 
            }
        }
    }
    
    void Game::playTurn(){
        if(this->First_player.stacksize()==0 || this->Second_player.stacksize()==0){
            throw runtime_error("#Game Over! ");
        }
        if(First_player.getname()==Second_player.getname()){
            throw runtime_error("You Trying to play with your self !");
        }
        Card c1 = First_player.Playcard();
        Card c2 = Second_player.Playcard();
        try{

            if(c1.isGreater(c2)==1){
                if(!(this->drawfirst.empty()) || !(this->drawsecond.empty()) ){
                    while(!(this->drawfirst.empty()) && (!(this->drawsecond.empty()))){
                        First_player.WinCard(drawfirst.top(),drawsecond.top());
                        this->drawfirst.pop();
                        this->drawsecond.pop();
                    }
                }
                First_player.WinCard(c1, c2);
                Second_player.LoseCard();
                lastturnlog =First_player.getname() + " Played :" + c1.getcard() + "," + Second_player.getname() +" Played :" +c2.getcard() +" " +First_player.getname() +"  Win!\n"; 
                log+=lastturnlog;
            }
            else if(c1.isGreater(c2)==-1){
                if(!(this->drawfirst.empty()) || !(this->drawsecond.empty()) ){
                    while(!(this->drawfirst.empty()) && (!(this->drawsecond.empty()))){
                        Second_player.WinCard(drawfirst.top(),drawsecond.top());
                        this->drawfirst.pop();
                        this->drawsecond.pop();
                    }     
                }           
                Second_player.WinCard(c1, c2);
                First_player.LoseCard();
                lastturnlog =First_player.getname() + " Played :" + c1.getcard() + "," + Second_player.getname() +" Played :" +c2.getcard() + " "+Second_player.getname() +"  Win!\n"; 
                log+=lastturnlog;
            }
            else{
                First_player.LoseCard();
                Second_player.LoseCard();
                this->drawfirst.push(c1);
                this->drawsecond.push(c2);

                lastturnlog =First_player.getname() + " Played :" + c1.getcard() + "," + Second_player.getname() +" Played :" +c2.getcard() + "  DRAW!\n"; 
                log+=lastturnlog;        

                c1=this->First_player.Playcard();
                c2=this->Second_player.Playcard();
                First_player.LoseCard();
                Second_player.LoseCard();
                this->drawfirst.push(c1);
                this->drawsecond.push(c2);                

            }
        }
        catch(std::exception& e){
            cerr << "An Error ocuured during the game" << e.what() <<endl;
        }
    }

    void Game::playAll(){
        while(First_player.stacksize()!=0 && Second_player.stacksize()!=0){
            try{
                playTurn();
            }
                catch(std::exception& e){
            cerr << "An Error ocuured during the game" << e.what() <<endl;
        }
        }
        if(!(this->drawfirst.empty()) || (!(this->drawsecond.empty()))){
            while(!drawfirst.empty()){
                First_player.addCard(drawfirst.top());
                drawfirst.pop();
            }
            while(!drawsecond.empty()){
                Second_player.addCard(drawsecond.top());
                drawsecond.pop();
            }   
            try{
                playAll();
            }
                catch(std::exception& e){
            cerr << "An Error ocuured during the game" << e.what() <<endl;
        }                     
        }
        if(First_player.getvectories() > Second_player.getvectories()){
            this->setWinner(First_player.getname());
            log+="The Winner in this Game is :" +First_player.getname() +"\n";
        }
        else if(First_player.getvectories() < Second_player.getvectories()){
            this->setWinner(Second_player.getname());
            log+="The Winner in this Game is :" +Second_player.getname() +"\n";
        }
        else{
            log+="The Game was endeed by DRAW\n";
        }
    }
    void Game::printWiner(){
        try{
            cout << "The Winner in this Game is:" << this->getWinner() << endl;
        }
        catch(exception &e){
            throw runtime_error("There is no winner yet!" + string(e.what()));
        }
    }
    void Game::printLog(){
        try{
            cout << log;
        }
        catch(exception& e){
            throw runtime_error("an error ocuured while printing the log " + string(e.what()));
        }
    }
    void Game::printStats(){}
    void Game::printLastTurn(){
        try{
            cout << lastturnlog << endl;
        }
        catch(exception& e){
            throw runtime_error("an error ocuured while printing the last turn log " + string(e.what()));
        }
    }
    void Game::setWinner(string win){this->winner=win;}
    string Game::getWinner(){return winner;}

}