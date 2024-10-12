import serial

class SerialFlex:
    def __init__(self):
        self.ser = serial.Serial('/dev/ttyUSB1')
        self.ser.baudrate = 115200
    
    def send_vel(self, x, y, w):
        send = f"set_body_vel {round(x * 1000)} {round(y * 1000)} {round(w * 1000)}\r"
        self.ser.write(str.encode(send))
        return send