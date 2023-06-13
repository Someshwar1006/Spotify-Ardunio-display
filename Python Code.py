import serial
import spotipy
import spotipy.util as util
import time

# Spotify API credentials
SPOTIFY_USERNAME = ''
SPOTIFY_CLIENT_ID = ''
SPOTIFY_CLIENT_SECRET = ''
SPOTIFY_REDIRECT_URI = ''

# Arduino serial port
ARDUINO_PORT = '/dev/ttyUSB0'  # Change this to the appropriate port

# Initialize Arduino serial connection
arduino = serial.Serial(ARDUINO_PORT, 9600, timeout=1)

# Spotify access token
scope = 'user-read-playback-state'
token = util.prompt_for_user_token(SPOTIFY_USERNAME, scope, client_id=SPOTIFY_CLIENT_ID,
                                   client_secret=SPOTIFY_CLIENT_SECRET, redirect_uri=SPOTIFY_REDIRECT_URI)
spotify = spotipy.Spotify(auth=token)

def send_data_to_arduino(song_name, artist_name, song_time):
    # Format the data as a string to be sent to Arduino
    data = f"{song_name}|{artist_name}|{song_time}"

    # Send the data to Arduino
    arduino.write(data.encode())

def update_song_info():
    while True:
        # Get the currently playing track information
        current_track = spotify.current_user_playing_track()

        if current_track is not None:
            # Extract relevant information
            song_name = current_track['item']['name']
            artist_name = current_track['item']['artists'][0]['name']
            song_time = current_track['progress_ms']

            # Convert song_time to bar format (e.g., [==  ] or [====])
            bar_length = 16  # Length of the LCD screen
            progress = int((song_time / current_track['item']['duration_ms']) * bar_length)
            song_bar = '[' + '=' * progress + ' ' * (bar_length - progress) + ']'

            # Send data to Arduino
            send_data_to_arduino(song_name, artist_name, song_bar)
            print(song_name)

        time.sleep(1)  # Update every second

# Start the song info update loop
update_song_info()
