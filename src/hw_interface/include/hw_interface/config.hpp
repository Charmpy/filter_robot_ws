#ifndef HW_INTERFACE_CONFIG_H
#define HW_INTERFACE_CONFIG_H

#include <string>


struct Config
{
  std::string device = "/dev/ttyUSB0";
  int baud_rate = 500000;
  int timeout = 5000;
};


#endif // DIFFDRIVE_ARDUINO_CONFIG_H