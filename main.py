import serial
import time
import pyautogui

# Create Serial port object
ser = serial.Serial('/dev/ttyACM0',9600)
# wait for 2 seconds for the communication to get established
time.sleep(2)

while True:
    # Getting data from the Serial Connection
    serialData = str(ser.readline(),'utf-8')[:-1]
    # Performing actions on the basis of input received
    if 'Play/Pause' in serialData:
        pyautogui.hotkey('space')
    elif 'Rewind' in serialData:
        pyautogui.hotkey('ctrl','left')
    elif 'Forward' in serialData:
        pyautogui.hotkey('ctrl','right')
    elif 'VolumeUp' in serialData:
        pyautogui.hotkey('ctrl','down')
    elif 'VolumeDown' in serialData:
        pyautogui.hotkey('ctrl','up')