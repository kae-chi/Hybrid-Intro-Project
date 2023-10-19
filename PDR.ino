#define button 15
#define sollenoidPin 16
#define ematchPin 17
#define loadcell 18 
//do this for all pins and give them names, relay yadayada
//numbers are arbitrary, 

void setup() {

  //spypins are intialized 

  //button pin is activated with initializePins 

  //if pins rdy, then begin proccess 
    // from the arduino, power 5v pin for sollenoid 
    // which will go into the relay, being converted to 12v 
    //12v goes into solenoid valve through n.o 

  // until sollenoid delay(**arbitrary**) ends, power the relay which goes into the ematch
    //5v >> relay >> 12v 
    // 12v goes into ematch 
    // ematch fires off (this will prob be timed)

  //power is cut from both relays, solenoid will close. 
  //https://www.circuitbasics.com/logging-arduino-data-to-files-on-a-computer/#:~:text=We%20will%20collect%20data%20and,or%20transmitted%20over%20a%20link.
  // SD card https://docs.arduino.cc/learn/programming/sd-guide 
  //done 

}

void loop() {
  //if button is pressed
    // digital pins for button will be HIGH 
  //collecting data

  //append data to csv files 
 
}


bool initalizePins(boolean push){ 

  //important pins 
    pinMode(button, INPUT); 
    pinMode(sollenoidRelay, OUTPUT)
    digitalWrite(sollenoidRelay, LOW)
    pinMode(ematchRelay, OUTPUT)
    digitalWrite(ematchRelay, LOW)
    pinMode(loadcell, INPUT)

    //digital pins for 5v+ 
    // digital pin for button 
    // Ground pins from Arduino to relays 
    // Normal output from relays to the ground of ematch and sollenoid valves
    // Com pins take 12v (connect to the battery )

}
