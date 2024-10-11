#ifndef HW_INTERFACE_ARDUINO_COMMS_H
#define HW_INTERFACE_ARDUINO_COMMS_H

#include <serial/serial.h>
#include <cstring>
#include <string>



#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>

#include <fcntl.h>      // Для работы с файлами
#include <termios.h>    // Для настройки UART
#include <unistd.h> 


#include "config.hpp"

class ArduinoComms
{
public:

  ArduinoComms()
  {  }

  Config cfg_;
  void setup(const std::string serial_device);
  void sendEmptyMsg();
  void readOdometry(
    double &pos_x, double &pos_y, double &pos_w,
    double &vel_x, double &vel_y, double &vel_w
    
  );
  void setSpeed(int vel_x, int vel_y, int vel_w);
 
  bool connected() const { return serial_conn_.isOpen(); }

  std::string sendMsg(const std::string &msg_to_send, bool print_output = false);

  
  std::mutex uart_mutex;                 // Мьютекс для защиты UART ресурса
  std::condition_variable async_cv;      // Условная переменная для асинхронной отправки
  bool async_ready; 

private:
  serial::Serial serial_conn_;  ///< Underlying serial connection 
};

#endif // DIFFDRIVE_ARDUINO_ARDUINO_COMMS_H