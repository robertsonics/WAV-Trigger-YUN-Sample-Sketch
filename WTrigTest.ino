// ****************************************************************************
//     Filename: WTrigTest.c
// Date Created: 2/23/2014
//
//     Comments: Basic Arduino YUN control of the WAV Trigger
//
// Programmers: Jamie Robertson, jamie@robertsonics.com
//
// Comments: This sketch demonstrates the use of the WAV Trigger library using
//  an Arduino YUN to provide basic control from a web browser. To use, point
//  your browser to http://arduino.local/sd/WTrigTest, where "arduino" is the
//  name you gave your YUN when you set it up.
//
//  Because I'm not an html5/css expert, this example is rather simple, and
//  provides control of only track 1. It can easily be extended with some add-
//  itional html/css to create a multi-channel mixer.
//
//  Thanks to Matteo Loglio for the initial examples
// ****************************************************************************

#include <Bridge.h>
#include <YunServer.h>
#include <YunClient.h>

// The hardware serial port is not available on the YUN, and there are issues
//  with interrupts using the native SoftwareSerial library on the YUN, so I
//  ended up using the AltSoftwareSerial library, which means the serial TX pin
//  to the WAV Trigger is the YUN's pin 5.

#include "AltSoftSerial.h"
#include "wavTrigger.h"

wavTrigger wTrig;

// Listen on default port 5555, the webserver on the Yun
// will forward all the HTTP requests for us.
YunServer server;

// ****************************************************************************
void setup() {
  Serial.begin(9600);
  
  // WAV Trigger startup at 57600
  wTrig.start();
  
  // Bridge startup
  Bridge.begin();

  // Listen for incoming connection only from localhost
  server.listenOnLocalhost();
  server.begin();
}

// ****************************************************************************
void loop() {
  
int var;
  
  // Get clients coming from server
  YunClient client = server.accept();

  // There is a new client?
  if (client) {

    String command = client.readStringUntil('/');

    // track command
    if (command == "track") {
      var = client.parseInt();
      if (var == 1) {
        wTrig.trackPlaySolo(1);
        delay(10);
        wTrig.trackLoop(1, true);
      } 
      else {
        wTrig.trackStop(1);
       }
    }
    
    // volume command
    else if (command == "volume") {
      var = client.parseInt();
      wTrig.trackGain(1, var);
    }     

    // Close connection and free resources.
    client.stop();
  }

  delay(50); // Poll every 50ms
}



