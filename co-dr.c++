//The goal of of the program is for the arduino to accept the

//Free RTOS (Real time Operating System)


/*Actuate two separate relays (we can try parallel processing?) 
>> for the solenoid and the ematch separately 
>> this should send a a signal to fire the solenoid/ematch for a given number of time */ 

//Script produces a voltage to the Analog Input 
//Conduct electricity from 5V and conduct it to the button 
// The button will then push the electricty to the Analog Input
// The analog input then sends the same voltage to the digital output 

//Executing Actual Script 


//things to look up: Free RTOS 


// actual pseudocode 

//This happens upon user input 

//digitalwrite -- sets the pins  

    //digital pin out - binary values 
    //analog-- number of volts 


//the true condition for the while loop is when we start the proccess. 

//while loop >> true 

    //load cell is collecting data continously throughout the span, this can be append to CSV File 

    //if userinput >> true

        //sollenoid 
            // it should either be True(firing) or False(not Fire) 
        //start firing 
        //stop firing once three real seconds elapsed after  initial user input 



        //E-Match 
            //should fire a given amount after the sollenoid opens 
            //PLZ FIRE THE EMATCH LOL 

    //when while loop is done, the data will be on a CSV file.  




//the role of an output relay is to convert boolean logic level signals to external motion 



