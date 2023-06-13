# Spotify Arduino Display

This project allows you to display real-time Spotify song information, including artist name, song name, and song progress, on an Arduino connected to a 16x2 LCD screen. The Python script interacts with the Spotify API to retrieve the currently playing song, and then sends the song information to the Arduino via a serial connection. The Arduino receives the data and displays it on the LCD screen.

## Prerequisites

To run this project, you'll need the following:

- Arduino board (e.g., Arduino Uno)
- 16x2 LCD screen
- Jumper wires
- Python (version 3.6 or later)
- Python libraries: spotipy, serial, time
- Arduino IDE (or any compatible IDE)
- Spotify developer account (for API access)
- Basic knowledge of Arduino and Python programming

## Getting Started

1. Connect the 16x2 LCD screen to the Arduino following the wiring diagram provided. Adjust the pin numbers in the Arduino code accordingly.

2. Install the necessary Python libraries by running the following command:

3. Create a Spotify developer account and create a new app to obtain your client ID and client secret. Follow these steps:
- Visit the [Spotify Developer Dashboard](https://developer.spotify.com/dashboard) and log in with your Spotify account.
- Create a new app and fill in the required information.
- Once your app is created, you'll see your client ID and client secret on the app's dashboard.

4. Update the Python code (spotify_arduino.py) with your Spotify client ID, client secret, and API dashboard link.

- Open the spotify_arduino.py file in a text editor.
- Replace `YOUR_CLIENT_ID` with your Spotify client ID.
- Replace `YOUR_CLIENT_SECRET` with your Spotify client secret.
- Replace `YOUR_API_DASHBOARD_LINK` with the link to your Spotify app's dashboard.

5. Upload the Arduino code (spotify_arduino.ino) to your Arduino board using the Arduino IDE or a compatible IDE.

6. Run the Python script (spotify_arduino.py) to start the data transmission from Spotify to the Arduino.

7. The Arduino will receive the song information and display it on the LCD screen.

## Customization

- If you want to change the delay interval between data transmissions from Python to Arduino, modify the time.sleep() value in the Python script.

- Adjust the pin numbers in the Arduino code if your LCD screen is connected to different pins.

- Feel free to customize the display format, font, or additional functionality based on your preferences and requirements.

## Troubleshooting

- Make sure the Arduino board is properly connected to your computer via USB.

- Double-check your Spotify credentials, including the client ID and client secret, and ensure they are correctly entered in the Python code.

- Ensure that the required Python libraries (spotipy, serial, time) are installed.

- If the LCD display is not showing any information, check the wiring connections and the pin numbers in the Arduino code.

