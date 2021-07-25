#include "obstacle.h"

//sets the width, height, x-coordinate and the y-coordinate of the obstacle
Obstacle::Obstacle(){
    
    obstacle_position.x = 85; //the obstacles are not visible at start
    obstacle_position.y = 0; //starting y-coordinate of upper pipe
    width = 10; //width of both pipes
    height = rand()%28; //used to declare the height of the upper pipe. Max height of upper pipe must still allow bird to jump under it.
    
}

//draws the obstacle on the lcd
void Obstacle::draw(N5110 &lcd){
    
    lcd.drawRect(obstacle_position.x, obstacle_position.y, width, height, FILL_BLACK); //draws upper pipe
    lcd.drawRect(obstacle_position.x, height+23, width, (48-height), FILL_BLACK); //draws lower pipe
    
}

//makes the obstacles go backwards towards the bird    
void Obstacle::update(){
    
    obstacle_position.x--; //obstacle moves towards bird on lcd
    if(obstacle_position.x <= 0){
        
        width--; //if obstacle reaches end, width decreases to make it look like it goes out of the lcd
        
    }
    
}

//checks if bird collided with obstacles
bool Obstacle::collide(N5110 &lcd){
    
    int i;
    for(i = obstacle_position.y; i<=height; i++){ //checks if bird collides with left part of top pipe
    
        if(lcd.getPixel(obstacle_position.x, i) == 1){
            
            return true; //returns true if collision    
            
        }   
        
    }
    
    int j;  
    for(j = height+23; j<=48; j++){ //checks if bird collides with left part of bottom pipe
    
        if(lcd.getPixel(obstacle_position.x, j) == 1){
            
            return true; //returns true if collision   
            
        }
        
    }
    
    int k;   
    for(k = obstacle_position.x; k<=width+obstacle_position.x; k++){ //checks if bird collides with base of top pipe
    
        if(lcd.getPixel(k, height) == 1){
            
            return true; //returns true if collision
            
        }
        
    }
    
    int l;  
    for(l = obstacle_position.x; l<=width+obstacle_position.x; l++){ //checks if bird collides with top of bottome pipe
    
        if(lcd.getPixel(l, height+23) == 1){
            
            return true; //returns true if collision
            
        }
        
    }
    
    return false; //returns false if no collision  
    
}