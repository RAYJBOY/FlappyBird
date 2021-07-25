#ifndef ENGINE_H
#define ENGINE_H

#include "mbed.h"
#include "N5110.h"
#include "Gamepad.h"
#include "Bitmap.h"
#include "bird.h"
#include "obstacle.h"
#include "virus.h"
#include "menu.h"

/**
@brief Class for running the game

@version 1.0

@author Muhammad Hamza Imam

@date April 2020

*/



class Engine{
    
    public:
    
    /** 
    * @brief Creates initial obstacle and sets the score
    */    
    Engine(); //creates initial obstacle and sets the score
    
    /** 
    * @brief Runs the game
    */
    void run(); //runs the game
    
    /** 
    * @brief Shows the player the score after losing
    */
    void GameOver(); //if player loses, displays end score of player
    
    /** 
    * @brief Used to get reference to pad being used by the engine
    * @returns a pointer to the pad being used
    */    
    Gamepad* getPad(); //returns pointer to pad object used by engine
    
    /** 
    * @brief Used to get reference to lcd being used by the engine
    * @returns a pointer to the lcd being used
    */    
    N5110* getLCD(); //returns pointer to lcd object used by engine
    
    /** 
    * @brief Used to display options to the user (like play, instructions etc.)
    */    
    void displayMenu(); //displays the opening screen and the in-game menu to player
    
    /** 
    * @brief Used to update score as player progresses through the game
    */    
    void UpdateScore(); //updates player's score
        
    private:
    vector<Obstacle>obstacles; //used to store all obstacles created
    vector<Virus>viruses; //used to store all virus objects created
    Gamepad pad; //since this is the engine of the game, pad and lcd are created here
    N5110 lcd;
    Bird myBird; //creates the bird
    Menu myMenu; //created to display the opening screen and the in-game menu
    int score; //counter for keeping track of the player's score

};

#endif