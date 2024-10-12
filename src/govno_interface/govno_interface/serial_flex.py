import serial
import  threading

class SerialFlex:
    def __init__(self):
        self.ser = serial.Serial('/dev/ttyUSB1', )
        self.ser.baudrate = 115200
        self.ser.timeout = 10.0
        self.mutex = threading.Lock()
    
    def send_vel(self, x, y, w):
        send = f"set_body_vel {round(x * 1000)} {round(y * 1000)} {round(w * 1000)}\r"
        try:
            self.mutex.acquire()
            self.ser.write(str.encode(send))
            line = bytearray()
            while True:
                c = self.ser.read(1)
                if c != b"\r":
                    line += c
                else:
                    break
            return bytes(line)
            return send
        except Exception:
            return "error"
        finally:
            self.mutex.release()
    
    def get_odom(self):
        send = f"odom\r"
        try:
            self.mutex.acquire()
            self.ser.write(str.encode(send))
            line = bytearray()
            while True:
                c = self.ser.read(1)
                if c != b"\r":
                    line += c
                else:
                    break
            return bytes(line)
        except Exception as ex:
            return str(ex)
        finally:
            self.mutex.release()
    