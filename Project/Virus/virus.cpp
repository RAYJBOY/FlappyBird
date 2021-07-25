#include "virus.h"

//sets the width, height, x-coordinate and the y-coordinate of the virus
Virus::Virus(){ 
    
    virus_position.x = 85; //sets the x coordinate for the virus to be drawn
    virus_position.y = rand()%47; //sets the y coordinate for the virus to be drawn. 47 is the maximum y coordinate
    
    width = 2; //sets the width of the virus
    height = 2; //sets the height of the virus
    
}

//draws the virus on the lcd
void Virus::draw(N5110 &lcd){ 

    lcd.drawRect(virus_position.x, virus_position.y, width, height, FILL_BLACK); 
    
}

//updates the x coordinates of the virus
void Virus::update(){ 

    virus_position.x--; //when updated, virus moves closer to bird
    if(virus_position.x <= 0){ //if virus is on the left edge, its width decreases until 0 to remove it completely from the lcd
        
        width--; 
        
    }
    
}

//returns true if collision occurs, false otherwise
bool Virus::collide(N5110 &lcd){ 

    int i;
    for(i = virus_position.y; i<=height+virus_position.y; i++){ 
        
        if(virus_position.x<0 || virus_position.x>84 || virus_position.y > 48 || virus_position.y < 0){ //if the virus is not on the lcd, dont consider it
        }
        
        else if(lcd.getPixel(virus_position.x, i) == 1){ //checks if left part of virus collides with bird. Right part not accounted for as it did not make a difference to the game.
        
            return true; //returns true if collision    
            
        }   
        
    }
    
    
    int k;   
    for(k = virus_position.x; k<=width+virus_position.x; k++){ 
    
        if(lcd.getPixel(k, height) == 1){ //checks if bird collides with bottom of virus
        
            return true; //returns true if collision
            
        }
        
        if(lcd.getPixel(k, virus_position.y) == 1){ //checks if bird collides with top of virus
        
            return true; //returns true if collision
            
        }
        
    }
    
    return false;
}