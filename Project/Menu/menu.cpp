#include "menu.h"


int menu_bird_sprite[12][17] = { //bird sprite used for opening screen
    
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

//empty constructor as all functionality is in methods
Menu::Menu(){
    
}

//displays the opening screen
void Menu::opening(N5110 &lcd){
                
    #ifndef TEST_5
    printf("Opening screen");
    #endif 
    
    lcd.printString("Flappy Birds!", 5, 1); //displays title
    lcd.drawSprite(33, 24 , 12, 17, (int *)menu_bird_sprite); //displays sprite under title
    lcd.refresh();
    wait(3);
    
}

//returns an integer corresponding to the option chosen by player
int Menu::display(N5110 &lcd, Gamepad &pad){

    #ifndef TEST_6
    printf("Main menu");
    #endif 
    
    lcd.clear();
    while(1){ 
    
        lcd.printString("A. Play", 1,1); //displays all options to player
        lcd.printString("B. Instructions", 1,2);
        lcd.printString("X. Credits", 1,3);
        lcd.printString("Y. Quit", 1, 4);
        if(pad.A_held()){ //returns corresponding result to player input
        
            return 1;   
            
        }
        else if(pad.B_held()){
            
            return 2;   
            
        }
        else if(pad.X_held()){
            
            return 3;   
            
        }
        else if(pad.Y_held()){
            
            return 4;   
            
        }
        
        lcd.refresh();                    
    }
    
}

//displays the instructions to the player if he/she is new to the game
void Menu::instructions(N5110 &lcd){

    #ifndef TEST_7
    printf("Instructions");
    #endif 
    
    lcd.clear();
    lcd.printString("Instructions:", 1,0); //shows instructions to user on lcd
    lcd.printString("Press A to", 1,1);
    lcd.printString("jump.", 1,2);
    lcd.printString("Avoid the ", 1,3);
    lcd.printString("obstacles,", 1,4);
    lcd.printString("floor, viruses", 1,5);
    lcd.refresh();
    wait(5);
    
}

//displays the credits to the player
void Menu::credits(N5110 &lcd){
    
    #ifndef TEST_8
    printf("Creds");
    #endif 
    
    lcd.clear();
    lcd.printString("Game made by", 5,0); //shows credits to user on lcd
    lcd.printString("Muhammad Hamza", 1,1);
    lcd.printString("Imam", 30,2);
    lcd.printString("el18mhi", 23,3);
    lcd.printString("Enjoy!", 26,4);
    lcd.refresh();
    wait(5);   
    
}