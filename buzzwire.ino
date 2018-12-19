/*************************************************
   Public Constants
 *************************************************/

#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978

//TM1637 *_display = new TM1637(12, 13); // create display object, 12 = CLK (clock), 13 = D10 (data)

// music
int songState = 0;

int melody[] = {
  NOTE_F4, NOTE_E4, NOTE_D4, NOTE_CS4,
  NOTE_C4, NOTE_B3, NOTE_AS3, NOTE_A3,
  NOTE_G3, NOTE_A3, NOTE_AS3, NOTE_A3,
  NOTE_G3, NOTE_C4, 0,

  NOTE_C4, NOTE_A3, NOTE_A3, NOTE_A3,
  NOTE_GS3, NOTE_A3, NOTE_F4, NOTE_C4,
  NOTE_C4, NOTE_A3, NOTE_AS3, NOTE_AS3,
  NOTE_AS3, NOTE_C4, NOTE_D4, 0,

  NOTE_AS3, NOTE_G3, NOTE_G3, NOTE_G3,
  NOTE_FS3, NOTE_G3, NOTE_E4, NOTE_D4,
  NOTE_D4, NOTE_AS3, NOTE_A3, NOTE_A3,
  NOTE_A3, NOTE_AS3, NOTE_C4, 0,

  NOTE_C4, NOTE_A3, NOTE_A3, NOTE_A3,
  NOTE_GS3, NOTE_A3, NOTE_A4, NOTE_F4,
  NOTE_F4, NOTE_C4, NOTE_B3, NOTE_G4,
  NOTE_G4, NOTE_G4, NOTE_G4, 0,

  NOTE_G4, NOTE_E4, NOTE_G4, NOTE_G4,
  NOTE_FS4, NOTE_G4, NOTE_D4, NOTE_G4,
  NOTE_G4, NOTE_FS4, NOTE_G4, NOTE_C4,
  NOTE_B3, NOTE_C4, NOTE_B3, NOTE_C4, 0
};

int tempo[] = {
  8, 16, 8, 16,
  8, 16, 8, 16,
  16, 16, 16, 8,
  16, 8, 3,

  12, 16, 16, 16,
  8, 16, 8, 16,
  8, 16, 8, 16,
  8, 16, 4, 12,

  12, 16, 16, 16,
  8, 16, 8, 16,
  8, 16, 8, 16,
  8, 16, 4, 12,

  12, 16, 16, 16,
  8, 16, 8, 16,
  8, 16, 8, 16,
  8, 16, 4, 16,

  12, 17, 17, 17,
  8, 12, 17, 17,
  17, 8, 16, 8,
  16, 8, 16, 8, 1
};

// non blocking setup
// free play

unsigned long time;

unsigned long previousMillis1 = 0; // time words last changed
const long interval1 = 1500; // interval between changing

// music
unsigned long previousMillis2 = 0; // time last changed
const long interval2 = 100; // interval between notes

int displayStatus = 0; // keep track of what's displayed
int mode = 0; // keep track of game mode -- change to 0 or 1 for different modes

bool countdown = false;

unsigned long previousMillis3 = 0; // time last changed
const long interval3 = 1000; // interval between countdown
int count = 20; // challenge mode timer

void setup() {
  // put your setup code here, to run once:
  pinMode(9, INPUT); // setup circuit
  pinMode(10, OUTPUT); // setup buzzer 1
  pinMode(11, OUTPUT); // setup buzzer 2
  pinMode(2, INPUT); // setup button
  Serial.begin(9600);
  
  // _display->set(5); // set brightness
  // _display->point(false); // remove colon
  // _display->init(); // start display
}

void loop() {
  // put your main code here, to run repeatedly:
//  if (mode == 0) {
//    // challenge mode
//    if (digitalRead(2) == HIGH) {
//      delay(25);
//      if (digitalRead(2) == HIGH) {
//        countdown = true; // start COUNTDOWN
//      }
//    }
//    if (countdown) {
//      showCountdown(); // advance countdown
//    }
//  }
//  else {
//    // free play
//    toggleFreePlay();
//  }
  
  time = millis();
  
  if (digitalRead(9) == HIGH) {
    delay(5);
    if (digitalRead(9) == HIGH) {
      time += 5000;
      while (digitalRead(9) == HIGH) {
        buzz(10, NOTE_B0, 1000);
      }
    }
  }

  if (digitalRead(2) == HIGH) {
    Serial.println(time);
    delay(1000);
    exit(0);
    //INSERT CODE TO SEND TIME  
  }
  
  else
    sing();
}

void showCountdown() {
  // countdown the time remaining
  unsigned long currentMillis = millis(); // current time
  if (currentMillis - previousMillis3 >= interval3) {
    previousMillis3 = currentMillis;
    --count;
    //showNumber(count);
    if (count == 0) {
      // game over
      countdown = false;
      count = 20;
      // reset countdown
      // buzz 3 times
      buzz(10, NOTE_B0, 1000 );
      delay(100);
      buzz(10, NOTE_B0, 1000 );
      delay(100);
      buzz(10, NOTE_B0, 1000);
    }
  }
}

//void showNumber(int number) {
// // show numbers (maximum 99) on display
// _display->display(0, 25); // write - to segment 1
// _display->display(3, 25); // write - to segment 4
//
// // write number to middle of display
//  if(number == 10)
//  {
//     _display->display(1,1);
//   _display->display(2,0);
//  }
//  else if(number > 9)
//  {
//   _display->display(1,1);
//   int newVal = number - 10;
//   _display->display(2, newVal);
//  }
//  else
//  {
//     _display->display(1,0);
//   _display->display(2,number);
//  }
//}

void toggleFreePlay() {
  // scroll between words without blocking
  unsigned long currentMillis = millis(); // current time
  if (currentMillis - previousMillis1 >= interval1) {
    previousMillis1 = currentMillis;
    // if(displayStatus == 1)
    // showPlay();
    // else
    // showFree();
  }
}

//void showPlay() {
// // write "PLAY" to the display
// _display->display(0, 21); // write P to segment 1
// _display->display(1, 18); // write L to segment 2
// _display->display(2, 10); // write A to segment 3
// _display->display(3, 4); // write Y to segment 4
// displayStatus = 2;
//}

//void showFree() {
//  write "Free" to the display
// _display->display(0, 15); // write F to segment 1
// _display->display(1, 23); // write r to segment 2
// _display->display(2, 14); // write E to segment 3
// _display->display(3, 14); // write E to segment 4
// displayStatus = 1;
//}

void buzz(int targetPin, long frequency, long length) {
  /* Buzzer example function by Rob Faludi
    http://www.faludi.com
    https://gist.github.com/AnthonyDiGirolamo/1405180
  */
  long delayValue = 1000000 / frequency / 2; // calculate the delay value between transitions
  //// 1 second's worth of microseconds, divided by the frequency, then split in half since
  //// there are two phases to each cycle
  long numCycles = frequency * length / 1000; // calculate the number of cycles for proper timing
  //// multiply frequency, which is really cycles per second, by the number of seconds to
  //// get the total number of cycles to produce
  for (long i = 0; i < numCycles; i++) { // for the calculated length of time...
    digitalWrite(targetPin, HIGH); // write the buzzer pin high to push out the diaphragm
    delayMicroseconds(delayValue); // wait for the calculated delay value
    digitalWrite(targetPin, LOW); // write the buzzer pin low to pull back the diaphragm
    delayMicroseconds(delayValue); // wait again for the calculated delay value
  }
}

void sing() {
  // play the song in a non blocking way
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis2 >= interval2) {
    previousMillis2 = currentMillis;
    int noteDuration = 1000 / tempo[songState];
    buzz(10, melody[songState], noteDuration);
    int pauseBetweenNotes = noteDuration;
    delay(pauseBetweenNotes);

    // stop the tone playing:
    buzz(10, 0, noteDuration);

    ++songState;
    // start song again if finished
    if (songState > 79) {
      songState = 14; // skip intro
    }
  }
}
