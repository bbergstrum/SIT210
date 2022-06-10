import RPi.GPIO as GPIO
from gpiozero import Buzzer 
from gpiozero import DistanceSensor
from gpiozero import LED 
from datetime import date, datetime
import time

GPIO.setmode(GPIO.BCM)
BUZZER = Buzzer(16)
LED = LED(17)
SENSOR = DistanceSensor(echo=24, trigger=23 ) 

if _name_ == "_main_":
  while True:
    distance = SENSOR.value
    print(f'Distance {distance :1.2f} M')
    time.sleep(0.1)
    if distance < 0.1:
      Alert(0.1, 0.4, 0.0005)
    elif distance > 0.1 and distance < 0.2:
      Alert(0.1, 0.4, 0.2)
    elif distance > 0.2 and distance < 0.4:
      Alert(0.1, 0.8, 0.5)
    elif distance > 0.4 and distance < 0.8:
      Alert(0.1, 1.2, 1)
    else:
      BUZZER.off()

GPIO.cleanup()

def Alert(beepStart, beepStop, duration):
  LED.on()
  BUZZER.blink(beepStart, beepStop)
  time.sleep(duration)
  LED.off()
