#ifndef VIRUS_H
#define VIRUS_H

#include "mbed.h"
#include "N5110.h"
#include "Gamepad.h"
#include "Bitmap.h"

/**
@brief Class for creating and interacting with the virus

@version 1.0

@author Muhammad Hamza Imam

@date April 2020

*/

class Virus{
    
    public:
    
        /** 
        * @brief Sets the width, height, x-coordinate and the y-coordinate of the virus
        */   
        Virus(); //sets the width, height, x-coordinate and the y-coordinate of the virus
        
        /** 
        * @brief Draws the virus on the lcd
        * @param takes a reference to the lcd to draw the virus on
        */         
        void draw(N5110 &lcd); //draws the virus on the lcd
        
        /** 
        * @brief Updates the virus coordinates
        */          
        void update(); //makes the virus go backwards towards the bird
        
        /** 
        * @brief Checks if bird has collided with the virus
        * @param takes a reference to the lcd where the viruses are drawn
        * @returns true if collision occurs, false otherwise
        */        
        bool collide(N5110 &lcd); //checks if bird collided with virus
        
        Vector2D virus_position; //used to store the x and y coordinates of the virus
        
        
        
    private:
 
        int height; //height of the virus 
        int width; //width of the virus

};

#endif