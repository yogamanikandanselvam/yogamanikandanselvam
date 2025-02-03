import speech_recognition as sr  
import RPi.GPIO as GPIO  
import time  

# Set up GPIO for relay  
GPIO.setmode(GPIO.BCM)  
GPIO.setup(18, GPIO.OUT) 

def recognize_speech():  
    r = sr.Recognizer()  
    
    with sr.Microphone() as source:  
        print("Listening...")  
        audio = r.listen(source)  

        try:  
            command = r.recognize_google(audio).lower()  
            print(f"You said: {command}")  
            return command  
        except sr.UnknownValueError:  
            print("Sorry, I did not understand that.")  
            return None  
        except sr.RequestError:  
            print("Could not request results from Google Speech Recognition service.")  
            return None  

def main():  
    try:  
        while True:  
            command = recognize_speech()  
            if command:  
                if "turn on" in command:  
                    GPIO.output(18, GPIO.HIGH)   
                    print("Device turned ON")  
                elif "turn off" in command:  
                    GPIO.output(18, GPIO.LOW)   
                    print("Device turned OFF")  
                time.sleep(1) 
    except KeyboardInterrupt:  
        pass  
    finally:  
        GPIO.cleanup()  

if __name__ == "__main__":  
    main()