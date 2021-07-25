/* 
ELEC2645 Embedded Systems Project
School of Electronic & Electrical Engineering
University of Leeds
2019/20

Name: Muhammad Hamza Imam
Username: el18mhi
Student ID Number: 201247020
Date: 08/03/2020
*/

// includes
#include "mbed.h"
#include "Gamepad.h"
#include "N5110.h"
#include "bird.h"
#include "obstacle.h"
#include "engine.h"
#include "menu.h"


// objects
Gamepad* pad; //pointer to the pad used by engine
N5110* lcd; //pointer to the lcd used by engine

//code starts execution here
int main()
{
    
    #ifndef TEST_0
    printf("In start of main");
    #endif
    
    Engine myEngine; //a new engine object created that will be used to run the game
    myEngine.displayMenu(); //used to display a menu to the user, where he/she can choose what to do
    pad = myEngine.getPad(); //pad pointer references the pad used by engine
    lcd = myEngine.getLCD(); //lcd pointer references the lcd used by the engine
    lcd->clear(); 
    lcd->printString("Thank you for",3,1); //displays exit message
    lcd->printString("playing!",20,2);
    lcd->refresh();
    wait(3); //displays the message for 3 seconds
    lcd->clear();
    lcd->refresh(); //lcd goes blank at the end   
    
    #ifndef TEST_1
    printf("End of main");
    #endif
    
}


