# Jarvis AI Bot using Python
# Libraries import
import psutil
import requests
import pyjokes as pyjokes  # pip install pyjokes
import pyttsx3  # pip install pyttx3
import speech_recognition as sr
import datetime
from email import encoders
from email.mime.base import MIMEBase
from email.mime.multipart import MIMEMultipart
import wikipedia
import os
import googlesearch
import smtplib
import winshell as winshell
import pywhatkit
import webbrowser
import urllib.request
import urllib.parse
import re
import screen_brightness_control as sbc
import cv2
from pygame import mixer
# Libraries import end 

# -- setup for voice engine -- 
engine = pyttsx3.init('sapi5')
voices = engine.getProperty('voices')
engine.setProperty('voice', voices[0].id) # print(voices[0].id) 0= Male voice / 1 = female voice


# speak function : to get audio output from JARVIS
def speak(audio):
    engine.say(audio)
    engine.runAndWait()


# Wish function : to get wish according to time
def wishme():
    hour = int(datetime.datetime.now().hour)
    if hour >= 0 and hour < 12:
        speak("Good Morning!")
    elif 12 <= hour < 18:
        speak("Good Afternoon!")
    else:
        speak("Good Evening!")
    speak("Hello Sir Jarvis is here.Please tell me how may I help you? ")


# Take commands from me , microphone input and string output
def takeCommand():
    # It takes microphone input from the user and returns string output

    r = sr.Recognizer()
    with sr.Microphone() as source:
        print("Listening...")
        r.pause_threshold = 1
        audio = r.listen(source)
    
    # Recognize the voice using google function 
    try:
        print("Recognizing...")

        query = r.recognize_google(audio, language='en-in')
        print(f"User said: {query}\n")

    except Exception as e:
        print("Say that again please...")
        return "None"
    return query


# -- sendmail function : to send mail --
def sendmail(to, content):
    server = smtplib.SMTP('smtp.gmail.com', 587) # Gmail as SMTP server port is 587 for sending 
    server.ehlo()
    server.starttls()

    # password in .txt file for security and reading it
    with open('P.txt', 'r') as f:
        password = f.read()
        Mail_ID = 'Your_mail_address@gmail.com'
        server.login(Mail_ID, password)

    server.sendmail(Mail_ID, to, content)

    server.close()
# -- End of send mail function --

# username function : to get master info
def usrname():
    uname = "Ishan"
    speak(f"Welcome Mister{uname}")


# enable function : to turn on wifi (Useless here because without internet program will not work) 
def enable():
    os.system("netsh interface set interface 'Wifi' enabled")


# To turn off wifi using OS module 
def disable():
    os.system("netsh interface set interface 'Wifi' disabled")


# -- time converting function of time voice --  
def convertTime(seconds):
    minutes, seconds = divmod(seconds, 60)
    hours, minutes = divmod(minutes, 60)
    return "%d:%02d:%02d" % (hours, minutes, seconds)
# -- End of time converting function -- 

# -- Use Camera to take photo --
def take_photo():
    videoCaptureObject = cv2.VideoCapture(0)
    result = True
    while (result):
        ret, frame = videoCaptureObject.read()
        imgn = input("Enter name to image file(with .jpg/.png  extension): ")
        cv2.imwrite(str(imgn), frame)
        result = False
    videoCaptureObject.release()
    cv2.destroyAllWindows()
# -- End of photo taking function --

# Main function to run all commands
def run():
    while True:
        query = takeCommand().lower()  # lower case string

        #  -- Wikipedia search --
        if 'wikipedia' in query:
            speak('Searching Wikipedia...')
            query = query.replace("wikipedia", "")
            search1 = query
            q1 = search1.split()[0]
            results = wikipedia.summary(query, sentences=2)
            speak("According to wikipedia")
            print(results)
            webbrowser.open(f"https://en.wikipedia.org/wiki/{q1}")
            speak(results)
        # -- End of wikipedia search

        # General commands 1
        elif ('who are you' in query) or ('what is your name' in query):
            speak("My name is Jarvis and aim is to serve you sir!")

        # General commands 2
        elif ('who is jarvis' in query):
            speak('I am the Jarvis Sir and by the way  Jarvis is intelligent Auto artificial intelligence')

        # General commands 3
        elif 'who is owner of you' in query:
            speak("Your Name")

        # General commands 4
        elif 'how are you' in query:
            speak("I am fine")


        # Time and date
        elif 'time' in query:

            now = datetime.datetime.now().strftime('%I %M %p')
            print(now)
            speak("current time is" + now)
            x = datetime.datetime.now().strftime('%d %B %Y')
            print(x)
            speak("Date is " + x)


        # General commands 5
        elif 'thanks' in query:
            speak("any time sir")
            speak(" most welcome sir")


        # Location of city
        elif "where is" in query:
            query = query.replace("where is", "")
            location = query

            speak("User asked to Locate")
            speak(location)
            webbrowser.open("https://www.google.com/maps/place/" + location)

        # Tell joke
        elif 'joke' in query:
            j = pyjokes.get_joke()
            js = str(j)
            print(js)
            speak(js)


        # General commands 6
        elif 'nice one' in query:
            speak("thank you sir")

        # General commands 7
        elif 'who made you' in query:
            speak("off course you sir")

        # Google search
        elif 'google for' in query:
            speak("Searching in google")
            webbrowser.open(f"https://www.google.com/search?q={query}&oq={query}")

        # Youtube open
        elif 'open youtube' in query:
            speak("Opening youtube")
            webbrowser.open("youtube.com")

        # Google Open in browser
        elif 'open google' in query:
            speak("Opening google")
            webbrowser.open("google.com")

        # Play music in device
        elif 'play music' in query:
            music_dir = 'File_path_to_songs'
            songs = os.listdir(music_dir)
            speak("Playing Music")
            print(songs)
            os.startfile(os.path.join(music_dir, songs[0]))
       
        #play music on spotify
        elif 'spotify' in query:
            speak("Turning on spotify")
            q1 = query.split()[0]
            webbrowser.open(f"https://open.spotify.com/search/{q1}")

        # Send mail
        elif 'send a mail' in query:
            try:
                speak("What should I say?")
                content = takeCommand()
                speak("whom should i send")
                to = input()
                speak("any attachments sir")
                anse = takeCommand()
                y = "yes"
                if anse == y:
                    # Message part
                    msg = MIMEMultipart()

                    # From field
                    From = input("Enter From Field: ")
                    msg['From'] = str(From)

                    # Subject field
                    sub = input("Enter Subject Field: ")
                    msg['Subject'] = str(sub)

                    # Attaching image in mail and send it as payload
                    # Image should be in same directory otherwise give full path
                    filename = input("Enter file name with extension: ")
                    attachments = open(filename, 'rb')

                    p = MIMEBase('application', 'octet-stream')
                    p.set_payload(attachments.read())

                    encoders.encode_base64(p)
                    p.add_header('Content-Disposition', f'attachments; filename={filename}')
                    msg.attach(p)

                    # Sending mail
                    sendmail(to, content)
                    speak("Email has been sent !")

                else:
                    sendmail(to, content)
                    speak("Email has been sent !")
            except Exception as e:
                print(e)
                speak("I am not able to send this email sir ")


        # Whatsapp message  but time should be in 24 hours format and using chrome whatsapp web 
        elif 'whatsapp' in query:
            try:
                speak('please enter phone number sir')
                phoneno = input("Enter Phone no with + :")
                pnstr = str(phoneno)
                speak('what do you want to send')
                Text = input("Enter message to send :")
                speak('enter time sir')
                th = input("Enter hour time in 24hrs format :")
                thi = int(th)
                tm = input("Enter minute time in 24hrs format :")
                tmi = int(tm)
                speak('sending message')
                pywhatkit.sendwhatmsg(f'{pnstr}', f'{Text}', thi, tmi)
                print(f"Sending Whatsapp message to {pnstr}  ......")
                speak('message sent successfully sir ')
            except:
                speak('failed to send message.please check errors')
                print("Error!!!Check phone no and internet connection ......")

        # Play Music on youtube
        elif 'play' in query:
            song = query.replace('play', '')
            speak('playing' + song)
            pywhatkit.playonyt(song)

        # Empty recycle bin
        elif 'empty recycle bin' in query:
            winshell.recycle_bin().empty(confirm=False, show_progress=False, sound=True)
            speak("Recycle Bin Recycled")

        # Shutdown system
        elif 'shutdown system' in query:
            speak("Hold On a Sec ! Your system is on its way to shut down")
            os.system("shutdown /s /t 1")

        # Write a note
        elif "write a note" in query:
            speak("What should i write, sir")
            note = takeCommand()
            file = open('jarvis.txt', 'w')
            speak("Sir, Should i include date and time")
            snfm = takeCommand()
            if 'yes' in snfm or 'sure' in snfm:
                strTime = datetime.datetime.now().strftime('%Y/%m/%d %I:%M:%S')
                file.write(strTime)
                file.write(" :- ")
                file.write(note)
            else:
                file.write(note)

        # Show note
        elif "show note" in query:
            speak("Showing Notes")
            file = open("jarvis.txt", "r")
            print(file.read())
            speak(file.read(6))

        # Find your location
        elif 'where i am' in query or 'where we are' in query:
            res = requests.get('https://ipinfo.io/')
            data = res.json()

            city = data['city']
            country = data['country']

            location = data['loc'].split(',')
            latitude = location[0]
            longitude = location[1]

            speak(city)
            speak(country)
            speak(latitude)
            speak(longitude)

            print("Latitude : ", latitude)
            print("Longitude : ", longitude)
            print("City : ", city)
            print("Country: ", country)
            webbrowser.open("https://www.google.com/maps/place/" + latitude + " " + longitude)

        # Increase brightness of screen
        elif 'lumos' in query or 'increase brightness' in query:
            b1 = sbc.get_brightness()
            print(b1)
            speak(f"current brightness is {b1}")
            speak("Increasing it")
            sbc.set_brightness(85)

        # Decrease brightness of screen
        elif 'nox' in query or 'decrease brightness' in query:
            b2 = sbc.get_brightness()
            print(b2)
            speak(f"current brightness is {b2}")
            speak("Decreasing it")
            sbc.set_brightness(40)
       

        # Turn on wifi
        elif 'turn on wifi' in query:
            speak("turning on wifi sir")
            enable()

        # TUrn off wifi
        elif 'turn off wifi' in query:
            speak("turning off wifi sir")
            disable()

        # Check Battery percentage and power plug
        elif 'check battery' in query or 'check power' in query:
            battery = psutil.sensors_battery()
            bp = battery.percent
            strbp = str(bp)
            print("Battery status :", bp)
            speak(f"sir battery percentage is {strbp}")
            if bp >= 80:
                speak("there is enough power sir")
            elif bp >= 50:
                speak("good condition")
            elif bp < 50:
                speak("need to plug power sir")
            elif bp <= 15:
                speak("battery at critical condition sir please charge it")

            bpp = battery.power_plugged
            strbpp = str(bpp)
            print("Power plugged in : ", bpp)
            t = "True"
            if strbpp == t:
                speak("connected to power sir")
            else:
                speak("Not connected to power sir")

        # Alarm
        elif 'alarm' in query:
            tune = 'Tune_In_.mp3_file_location'
            speak("set time for alarm sir")
            alarm_hour = int(input("Set hour: "))
            alarm_minutes = int(input("Set minutes: "))
            am_pm = input("am or pm? ")
            print(f"Waiting for time: {alarm_hour}:{alarm_minutes} {am_pm}")
            speak("alarm is set have a good time sir")
            # time conversion
            # because datetime module returns time in military form i.e. 24 hrs format
            if am_pm == 'pm':  # to convert pm to military time
                alarm_hour += 12

            elif alarm_hour == 12 and am_pm == 'am':  # to convert 12am to military time
                alarm_hour -= 12

            else:
                pass

            while True:  # infinite loop starts to make the program running until time matches alarm time

                # ringing alarm + execution condition for alarm
                if alarm_hour == datetime.datetime.now().hour and alarm_minutes == datetime.datetime.now().minute:
                    print("\nIt's the time!")
                    # Play the alarm tune
                    mixer.init()
                    mixer.music.load(tune)
                    # Setting loops=-1 to ensure that alarm only stops when user stops it!
                    mixer.music.play(loops=-1)
                    # Asking user to stop the alarm
                    input("Press ENTER to stop alarm")
                    mixer.music.stop()
                    break

        # Take photo from camera
        elif 'take photo' in query:
            speak("sir taking photo  say cheese sir ")
            take_photo()


        # stop listening or give sleep time act as pause key 
        elif "don't listen" in query or "stop listening" in query:
            speak("for how much time you want to stop jarvis from listening commands")
            a = takeCommand()
            a1 = int(a)
            datetime.datetime.time.sleep(a1)
            print(a1)

        # exit from code
        elif 'exit' in query or 'turn off' in query:
            uname = "Ishan"
            speak(f"Thanks for giving me your time {uname} sir ")
            speak("exiting")
            exit()

# Main function with calls of all function

if __name__ == '__main__':
    usrname()
    wishme()
    run()
