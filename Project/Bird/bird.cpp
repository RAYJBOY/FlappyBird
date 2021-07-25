#include "bird.h"

int bird_sprite[12][17] = { //sprite for bird. Not complex enough for own class
    
{ 0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0 },
{ 0,0,0,0,1,1,0,0,0,1,0,0,1,0,0,0,0 },
{ 0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0 },
{ 0,0,1,0,0,0,0,0,1,0,0,0,1,0,1,0,0 },
{ 0,1,0,0,0,0,0,0,1,0,0,0,1,0,1,0,0 },
{ 0,1,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0 },
{ 0,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,0 },
{ 1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,1 },
{ 1,0,0,0,0,1,0,0,1,0,1,1,1,1,1,1,0 },
{ 1,0,0,0,1,0,0,0,0,1,0,0,0,0,0,1,0 },
{ 0,1,1,1,1,0,0,0,0,0,1,1,1,1,1,0,0 },
{ 0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0 }   
};
    
//used to set the initial position of the bird
Bird::Bird(){
 
    bird_position.x = 20; //max = 84. Sets bird x-coordinate
    bird_position.y = 18; //max = 48. Sets bird y-coordinate
    
}

//makes the bird drop if not made to jump
void Bird::update(){
    
    bird_position.y++; //updating bird means it drops   
    
}

//draws the bird on the lcd
void Bird::draw(N5110 &lcd){
    
    lcd.drawSprite(bird_position.x, bird_position.y , 12, 17, (int *)bird_sprite); //draws the sprite on lcd
    
}

//makes the bird jump by decrementing the y-coordinate
void Bird::jump(N5110 &lcd){
    
    if(bird_position.y<0){ //checks to make sure bird does not fly out of the screen
        
        bird_position.y = 0;
        
    }
    
    else{
        
        bird_position.y--; //decreasing y coordinate makes the bird jump
        
    }
    
    draw(lcd);  
    
}

//returns true if bird has dropped (and thus player loses)
bool Bird::dropped(){
    
    if(bird_position.y == 36) //if the y-coordinate of the bird raches 36, it touches the ground and player loses
        return true;
        
    else
        return false; //if bird still airborne, then returns false   
        
}