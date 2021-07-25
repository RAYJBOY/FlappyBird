#include "engine.h"

//creates initial obstacle and sets the score
Engine::Engine(){
        
    #ifndef TEST_2
    printf("Engine constructor");
    #endif
    
    Obstacle newObs; //creates initial obstacle
    obstacles.push_back(newObs); //pushes it into the vector of obstacles
    score = 0; //score of player is 0 at start.
        
}

//runs the game
void Engine::run(){
    
    #ifndef TEST_3
    printf("Running engine");
    #endif
    
    lcd.init(); //initialises the lcd
    lcd.setContrast(0.45);
    lcd.clear(); //clears the lcd before starting game
    int numb_of_obstacles = 0; //acts as counter, used to check for collisions with bird
    int numb_of_viruses = -1; //acts as a counter used to check for collisions with viruses

    while(1){ //runs until bird drops or collision occurs
       
        if(myBird.dropped()){
            
            GameOver(); //if bird drops, game is over           
            return;
  
            
        }
        

        if(obstacles[numb_of_obstacles].obstacle_position.x <= 35){
             
            Obstacle newObs; //everytime the current obstacle reaches x-coordinate of 35, engine makes a new obstacle
            obstacles.push_back(newObs); //new obstacle pushed into vector
            numb_of_obstacles++; //keeps track of the latest obstacle (as it is used for collision detection
            UpdateScore(); //everytime new obstacle is made, it means player has crossed the previous obstacle; score increases       
            
        }
        
        if(obstacles[numb_of_obstacles].obstacle_position.x == 55){ // draws the virus between 2 consecutive obstacles
        
            Virus virus;
            viruses.push_back(virus); //creates a new virus object and pushes it into vector so it can be drawn
            numb_of_viruses++; //updates the number of viruses
            
        }
              
        lcd.clear(); //clears after each frame
        if(pad.A_held()){ //if user presses A, bird jumps
                       
            int i = 0;
            for(i = 0; i<5; i++){ //bird jumps by 5 pixels
            
                lcd.clear();
                myBird.jump(lcd);
                for(int k = 0; k<obstacles.size(); k++){ //used to check if bird collided with any obstacle
                
                    obstacles[k].update(); //updates all obstacles in vector so they all go backwards/reduce in width
                    if(obstacles[k].collide(lcd)){
                        
                        GameOver(); //if bird collides with any obstacle, game over.
                        return;   
                        
                    }
                    
                    obstacles[k].draw(lcd); //if no collision, then draw all obstacles
                    
                }
                
                for(int a = 0; a<viruses.size(); a++){ //used to check if bird collided with any viruses
                
                    viruses[a].update(); //updates all viruses in vector so they all go backwards/reduce in width
                    if(viruses[a].collide(lcd)){
                        
                        GameOver(); //if bird collides with any virus, game over.
                        return;   
                        
                    }
                    
                    viruses[a].draw(lcd); //if no collision, then draw all viruses
                    
                }
                
                wait_ms(1000/25); //25 fps
                lcd.refresh();
                
            }
            
        }
        
        else{ //otherwise, it keeps falling
        
            myBird.update(); //if not jumped, bird falls
            myBird.draw(lcd);
            for(int k = 0; k<obstacles.size(); k++){ //collision check for every obstacle
            
                obstacles[k].update(); //updates all obstacles in vector so they all go backwards/reduce in width
                if(obstacles[k].collide(lcd)){
                    
                    GameOver(); //if bird collides with obstacle, game over
                    return;   
                    
                }
                
                obstacles[k].draw(lcd);
            }
            
            for(int k = 0; k<viruses.size(); k++){ //used to check if bird collided with any viruses
                
                viruses[k].update(); //updates all viruses in vector so they all go backwards/reduce in width
                if(viruses[k].collide(lcd)){
                    
                    GameOver(); //if bird collides with any virus, game over.
                    return;   
                        
                }
                    
                viruses[k].draw(lcd); //if no collision, then draw all viruses
                    
            }
            
            wait_ms(1000/25); //25 fps
        }
                
        char score_buffer[14];
        sprintf(score_buffer,"%d", score);
        lcd.printString(score_buffer,0,0); //prints out the score on the top left corner of lcd
        lcd.refresh();
        
    }
    
}

//if player loses, displays end score of player
void Engine::GameOver(){
                
    #ifndef TEST_3
    printf("Game Over!");
    #endif 
    
    wait_ms(200); //after player loses, it waits 200 ms to ensure user sees what happened
    int i = 84;
    int k = 0;
    int j = 48; //i, j and k are used for transition after loss
    for(i = 84; i>=0; i=i-2){
        
        lcd.drawRect(k, k, i, j, FILL_TRANSPARENT); //fills the screen with rectangles
        k++;
        j=j-2;
        wait_ms(20);
        lcd.refresh();
        
    }
    wait_ms(150);
    lcd.clear();
    char buffer[14];
    sprintf(buffer, "Game Over!"); //"Game Over" and score displayed to user after losing
    lcd.printString(buffer, 13,2);
    lcd.printString("Score:" , 15,3);
    char score_disp[14];
    sprintf(score_disp, "%d", score);
    lcd.printString(score_disp, 55,3);
    lcd.refresh();
    wait_ms(2500);
    
}

//used by main.cpp
Gamepad* Engine::getPad(){ 

    Gamepad* padPointer = &pad;
    return padPointer;   
    
}

//used by main.cpp to display exiting message
N5110* Engine::getLCD(){ 

    N5110* lcdPointer = &lcd;
    return lcdPointer;   
    
}

//displays the opening screen and the in-game menu to player
void Engine::displayMenu(){ 
    
    #ifndef TEST_4
    printf("Menu display");
    #endif 
                    
    lcd.init(); //initialises lcd before displaying anything
    lcd.setContrast(0.45);
    
    myMenu.opening(lcd); //displays the opening screen of the game (with the title and the flappy bird sprite)
    
    while(1){
        
        lcd.clear();
        int result = myMenu.display(lcd, pad); //displays the menu to the user and waits to get input
        lcd.refresh();
        wait(0.2);
    
        if(result == 1){ //if user presses A, it plays the game
        
           Engine newEngine;
           newEngine.run(); //runs the game
           
        }
        else if(result == 2){ //if user presses B, it displays the instructions
        
            myMenu.instructions(lcd);   
            
        }   
        else if(result == 3){ //if user presses X, it displays the credits
        
            myMenu.credits(lcd);   
            
        }
        else if(result == 4){ //if user presses Y, it quits. Restart needed to play game
        
            return;   
            
        }
        
    }
    
}

//updates player's score
void Engine::UpdateScore(){ 
            
    score++; //updates score
    
}
