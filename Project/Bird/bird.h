#ifndef BIRD_H
#define BIRD_H

#include "mbed.h"
#include "N5110.h"
#include "Gamepad.h"
#include "Bitmap.h"

/**
@brief Class for creating and interacting with the bird

@version 1.0

@author Muhammad Hamza Imam

@date April 2020

*/


class Bird{
    
    public:
    
        /** 
        * @brief Sets initial position of bird
        */
        Bird(); //used to set the initial position of the bird
        
        /** 
        * @brief Draws the bird on lcd
        * @param takes a reference to the lcd that the bird should appear on
        */
        void draw(N5110 &lcd); //draws the bird on the lcd
        
        /** 
        * @brief Makes the bird jump by decrementing y-coordinates
        * @param takes a reference to the lcd that the bird should appear on
        */        
        void jump(N5110 &lcd); //makes the bird jump by decrementing the y-coordinate
        
        /** 
        * @brief Checks if bird has fallen to the ground
        * @returns true if bird has fallen, false otherwise
        */        
        bool dropped(); //returns true if bird has dropped (and thus player loses)
        
        /** 
        * @brief Updates bird coordinates
        */        
        void update(); //makes the bird drop if not made to jump
        
    private:
        Vector2D bird_position; //initial position of bird

};

#endif