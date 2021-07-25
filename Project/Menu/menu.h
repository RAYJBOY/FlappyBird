#ifndef MENU_H
#define MENU_H

#include "mbed.h"
#include "N5110.h"
#include "Gamepad.h"
#include "Bitmap.h"


/**
@brief Class for creating and interacting with the menu

@version 1.0

@author Muhammad Hamza Imam

@date April 2020

*/

class Menu{
    
    public:
    
        /** 
        * @brief Empty constructor
        */
        Menu(); //empty constructor as all functionality is in methods
    
        /** 
        * @brief Displays the options as a menu to the user before starting game
        * @returns a corresponding number depending on what player chooses
        * @param takes a reference to the lcd and pad that it must display the menu on
        */    
        int display(N5110 &lcd, Gamepad &pad); //returns an integer corresponding to the option chosen by player
    
        /** 
        * @brief Displays the instructions to the user
        * @param takes a reference to the lcd it must diplay it on
        */      
        void instructions(N5110 &lcd); //displays the instructions to the player if he/she is new to the game
    
        /** 
        * @brief Displays the credits to the player
        * @param takes a reference of the lcd it must display it on
        */  
        void credits(N5110 &lcd); //displays the credits to the player
    
        /** 
        * @brief Displays the starting screen (with title and sprite) to player
        * @param takes a reference to the lcd it must display it on
        */  
        void opening(N5110 &lcd); //displays the opening screen
    
};

#endif