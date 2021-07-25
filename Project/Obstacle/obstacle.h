#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "mbed.h"
#include "N5110.h"
#include "Gamepad.h"
#include "Bitmap.h"

/**
@brief Class for creating and interacting with the obstacles

@version 1.0

@author Muhammad Hamza Imam

@date April 2020

*/

class Obstacle{
    
    public:
    
        /** 
        * @brief Sets the width, height, x-coordinate and the y-coordinate of the obstacle
        */
        Obstacle(); //sets the width, height, x-coordinate and the y-coordinate of the obstacle
        
        /** 
        * @brief Draws the obsacles on the lcd
        * @param takes a reference to the lcd to draw the obstacle on
        */          
        void draw(N5110 &lcd); //draws the obstacle on the lcd
        
        /** 
        * @brief Updates the obstacle coordinates
        */       
        void update(); //makes the obstacles go backwards towards the bird
        
        /** 
        * @brief Checks if bird has collided with the obstacles
        * @param takes a reference to the lcd where the obstacles are drawn
        * @returns true if collision occurs, false otherwise
        */  
        bool collide(N5110 &lcd); //checks if bird collided with obstacles
        Vector2D obstacle_position; //used to store the x and y coordinates of the obstacle
        
    private:
    
        int height; //height of the obstacle      
        int width; //width of the obstacle

};

#endif