from flask import Flask, request, render_template
import RPi.GPIO as GPIO
import time

app = Flask(__name__)

ledPin = 18
pwmPin = 24
buzzer = 17
trig = 5
echo = 6
scale = [262, 294, 330, 349, 392, 440, 494, 523]

def _setup():
    GPIO.setmode(GPIO.BCM)
    GPIO.setup(ledPin, GPIO.OUT)
    GPIO.setup(pwmPin, GPIO.OUT)
    GPIO.setup(buzzer, GPIO.OUT)
    GPIO.setup(trig, GPIO.OUT)
    GPIO.setup(echo, GPIO.IN)
    global pwmLed, pwmBuzz
    pwmLed = GPIO.PWM(pwmPin, 100)
    pwmBuzz = GPIO.PWM(buzzer, 1.0)
    pwmLed.start(0)

def _clean():
    GPIO.output(ledPin, False)
    pwmLed.stop()
    pwmBuzz.stop()

global i
i = 0

@app.route('/')
def home():
    try:
        _setup()
    except:
        print(home)
    return render_template("index.html")

@app.route('/data/led', methods=['POST'])
def _led():
    data = request.form['led']
    try:
        if data == "on":
            GPIO.output(ledPin, True)
        elif data == "off":
            GPIO.output(ledPin, False)
    except:
        print(led)
    return render_template("index.html")

@app.route('/data/pwm', methods=['POST'])
def _pwmLed():
    global i
    data = request.form['pwm']
    try:
        if data == "+":
            if i <= 90:
                i = i + 10
            pwmLed.ChangeDutyCycle(i)
        elif data == "-":
            if i >= 10:
                i = i - 10
            pwmLed.ChangeDutyCycle(i)
    except:
        print(pwm)
    return render_template("index.html")

@app.route('/data/buzz', methods=['POST'])
def _buzzer():
    data = request.form['buzz']
    try:
        if data == "on":
            pwmBuzz.start(50)
            for freq in scale:
                pwmBuzz.ChangeFrequency(freq)
                time.sleep(0.3)
            pwmBuzz.stop()
    except:
        print(buzzer)
    return render_template("index.html")

@app.route('/data/ultra', methods=['POST'])
def _ultra():
    data = request.form['ultra']
    if data == "on":
        global min
        min = 700.0
        for _ in range(10):
            GPIO.output(trig, False)
            time.sleep(0.2)
            GPIO.output(trig, True)
            time.sleep(0.00001)
            GPIO.output(trig, False)
            while GPIO.input(echo) == 0:
                start = time.time()
            while GPIO.input(echo) == 1:
                stop = time.time()
            interval = stop - start
            distance = interval * 17000
            distance = round(distance, 2)
#           print(distance)
            if min > distance:
                min = distance            
        
    return render_template("index.html",distance=min)

@app.route('/data/clean', methods=['POST'])
def _clean():
    data = request.form['led']
    try:
        if data == "clean":
            GPIO.cleanup()
            _clean()
        if data == "set":
            _setup()
    except: 
        pass
    return render_template("index.html")
    
if __name__ == "__main__":
    app.run(host="0.0.0.0", port="8080")
            

