
//libraries
#include <SPI.h>
#include <SD.h>

//defining pins
#define sollenoidRelay 16
#define ematchRelay 17
#define ampOne 2
#define ampTwo 3
#define button 15

//sd cardthere are 4 connections to the arduino, given the SD card is an SPI advice it can only be connected to SPI pins [10-13])
#define MOSIpin 11
#define MISOpin 12
#define CLKpin 13
#define CSpin 10


//solenoid and ematch difference


//global variables
bool buttonPressed = false;
File myFile; 
int timeDifference = 3 ; 
unsigned long currentTime;    //elapsed time since the button is pressed
int stop = 5; //when to fully stop the program
unsigned long buttonPressedTime;  // time elapsed in milliseconds since t he button 



//additional functions
void sdSetup() {


  //will begin to exchange data at 11520 bits per second

  Serial.begin(115200);


    //attempt to initialize SD card
    if (!SD.begin(CSpin)) {
    Serial.println("initialization failed!");
  }
  Serial.println("initialization done.");

  //instantiate file

  myFile = SD.open("data.csv", FILE_WRITE);
  myFile.print("Time");
  myFile.print(",");
  myFile.print("Clock") ;
  myFile.print(",");
  myFile.print("Data");
  myFile.print("\n");
}


void initializePins() {

  pinMode(button, INPUT);
  pinMode(sollenoidRelay, OUTPUT);
  digitalWrite(sollenoidRelay, LOW);
  pinMode(ematchRelay, OUTPUT);
  digitalWrite(ematchRelay, LOW);
  pinMode(ampOne, INPUT);
  pinMode(ampTwo, INPUT);
  digitalWrite(ampOne, HIGH);
  digitalWrite(ampTwo, HIGH);
}

void setup() {

  //initialize pins
  initializePins();

  //initialize sd card and file
  sdSetup();

}


void loop() {

  currentTime = millis();  

  int buttonState = digitalRead(button);

  if (buttonState == HIGH) {

    buttonPressed = true;
    buttonPressedTime = millis(); 
     //instantiate start
  }



  //initial button press
  if (buttonPressed) {
    digitalWrite(sollenoidRelay, HIGH);
  }
  //after an elapsed time, ematches fire off 
  if (buttonPressed && (currentTime - buttonPressedTime == timeDifference)) {

    digitalWrite(ematchRelay, HIGH);

  }

  if(currentTime == stop){
    digitalWrite(ematchRelay, LOW); 
    digitalWrite(sollenoidRelay, LOW); 
    buttonPressed = false; 
  }


  long recordedValueOne = digitalRead(ampOne);
  long recordedValueTwo = digitalRead(ampTwo);

  myFile.print(currentTime);
  myFile.print(",");
  myFile.print(recordedValueOne) ;
  myFile.print(",");
  myFile.print(recordedValueTwo);
  myFile.print("\n");


}


