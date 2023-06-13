#include <LiquidCrystal.h>

#define LCD_COLUMNS 16
#define LCD_ROWS 2
#define SCROLL_DELAY 500 // Delay between each scrolling step (in milliseconds)
#define DISPLAY_DURATION 5000 // Display duration for artist name and song name (in milliseconds)

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // Adjust pin numbers as per your Arduino setup

// Variables for scrolling text
String artistName;
String songName;
String currentText;
unsigned long displayStartTime;

void setup() {
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
   digitalWrite(8,HIGH);
  digitalWrite(9,HIGH);
  delay(1000);
  lcd.begin(LCD_COLUMNS, LCD_ROWS);
  lcd.clear();
  lcd.print("Spotify Info");
  lcd.setCursor(0, 1);
  lcd.print("Initializing...");
  delay(2000);
  Serial.begin(9600);
   // Set the baud rate to match the Python code
}

void loop() {
  digitalWrite(8,HIGH);
  digitalWrite(9,HIGH);
  delay(1000);
  if (Serial.available() > 0) {
    String data = Serial.readStringUntil('\n');
    data.trim(); // Remove leading/trailing whitespace
    
    int pipeIndex1 = data.indexOf('|');
    int pipeIndex2 = data.lastIndexOf('|');
    
    if (pipeIndex1 != -1 && pipeIndex2 != -1) {
      artistName = data.substring(0, pipeIndex1);
      songName = data.substring(pipeIndex1 + 1, pipeIndex2);
      String songBar = data.substring(pipeIndex2 + 1);
      
      // Clear the LCD screen
      lcd.clear();
  
      // Display artist name for 5 seconds
      displayStartTime = millis();
      currentText = artistName;
      while (millis() - displayStartTime < DISPLAY_DURATION) {
        lcd.setCursor(0, 0);
        lcd.print(currentText);
        lcd.setCursor(0, 1);
        lcd.print(songBar);
        delay(SCROLL_DELAY);
      }

      // Display song name for 5 seconds
      displayStartTime = millis();
      currentText = songName;
      while (millis() - displayStartTime < DISPLAY_DURATION) {
        lcd.setCursor(0, 0);
        lcd.print(currentText);
        lcd.setCursor(0, 1);
        lcd.print(songBar);
        delay(SCROLL_DELAY);
      }

      // Print the song progress bar on the bottom line
      lcd.setCursor(0, 1);
      lcd.print(songBar);
    }
  }
}
