/*
  SD card datalogger
 
 This example shows how to log data from three analog sensors 
 to an SD card using the SD library.
 	
 The circuit:
 * analog sensors on analog ins 0, 1, and 2
 * SD card attached to SPI bus as follows:
 ** MOSI - pin 11, pin 7 on Teensy with audio board
 ** MISO - pin 12
 ** CLK - pin 13, pin 14 on Teensy with audio board
 ** CS - pin 4,  pin 10 on Teensy with audio board
 
 created  24 Nov 2010
 modified 9 Apr 2012
 by Tom Igoe
 
 This example code is in the public domain.
 	 
 */

//#include <SD.h>
#include <SPI.h>

// On the Ethernet Shield, CS is pin 4. Note that even if it's not
// used as the CS pin, the hardware CS pin (10 on most Arduino boards,
// 53 on the Mega) must be left as an output or the SD library
// functions will not work.

// change this to match your SD shield or module;
// Arduino Ethernet shield: pin 4
// Adafruit SD shields and modules: pin 10
// Sparkfun SD shield: pin 8
// Teensy audio board: pin 10
// Teensy 3.5 & 3.6 & 4.1 on-board: BUILTIN_SDCARD
// Wiz820+SD board: pin 4
// Teensy 2.0: pin 0
// Teensy++ 2.0: pin 20
int data_counter = 0;
void setup()
{
 // Open serial communications and wait for port to open:
  Serial.begin(9600);
  Serial1.begin(115200);
   while (!Serial) {
    ; // wait for serial port to connect.
  }
while (!Serial1) {
    ; // wait for serial port to connect.
  }

  Serial.println("Starting...");
}
String all_data;
bool data_counter1;
bool data_counter2;
String values;
void loop()
{

  if (data_counter1){
  data_counter2 = true;
  data_counter1 = false;
  }
  String data_all;
  // make a string for assembling the data to log:
  String dataString1;  // datastring that will hold values from 
  String dataString2;  // datastring that will hold values from 
  String dataString3;

  bool ready = false;
  if (Serial1.available()>0){
   if (data_counter1)
    data_counter2 = true;
    Serial.println("something happened");
    dataString1 = Serial1.readString();
    dataString2 = Serial1.readString();
    dataString3 = Serial1.readString();
  Serial.print(dataString1);
  Serial.print(dataString2);
  Serial.println(dataString3);
  data_all = dataString1 + dataString2 + dataString3;
  if (data_all.substring(0,6) == "append")
  data_counter1 = true;
  }
  delay(10);

if (data_counter1){
 all_data = data_all;
}

if (data_counter2){
all_data += data_all;
Serial.print("all data is: "); 
Serial.println(all_data);
data_counter2= false;
values = parseString(all_data);
Serial.print("values are: "); 
Serial.println(values);
}
}

String msg[10];

String parseString(String s){
  int len= s.length();
  int i = 0;
  int prev_comma = 0;
  
  bool first = true;
  s = s.substring(118);
  for (i = 0; i<len;i++){
    //find commas and export data values
   /* if(s.charAt(i)== ',' and first){
      msg[msg_num] = s.substring(0,i);
      prev_comma = i;
      first = false;
    }
    else if (s.charAt(i)== ','){
      msg[msg_num] = s.substring(prev_comma+1,i);
      prev_comma = i;
    }
    */
  }
  return s;
}
double* parseValues(String s){


}
