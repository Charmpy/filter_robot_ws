#include "hw_interface/arduino_comms.hpp"
// #include <ros/console.h>
#include <rclcpp/rclcpp.hpp>
#include <sstream>
#include <cstdlib>
#include <string>

void ArduinoComms::setup(const std::string serial_device)
{  
    serial_conn_.setPort(serial_device);
    serial_conn_.setBaudrate(cfg_.baud_rate);
    serial::Timeout tt = serial::Timeout::simpleTimeout(cfg_.timeout);
    serial_conn_.setTimeout(tt); // This should be inline except setTimeout takes a reference and so needs a variable
    serial_conn_.open();
    // serial_conn_.(serial_device, baud_rate, serial::Timeout::simpleTimeout(timeout_ms));

}


void ArduinoComms::sendEmptyMsg()
{
    std::string response = sendMsg("_");
}

void ArduinoComms::readOdometry(
    double &pos_x, double &pos_y, double &pos_w,
    double &vel_x, double &vel_y, double &vel_w
    
    )
{
    
    // serial_conn_.write("O_");

    std::string response = sendMsg("O _");
    
    std::vector<std::string> res;
    int pos = 0;
    while(pos < response.size()){
        pos = response.find(" ");
        res.push_back(response.substr(0,pos));
        response.erase(0,pos+1); // 3 is the length of the delimiter, "%20"
    }
    pos_x = std::stod(res[0]);
    pos_y = std::stod(res[1]);
    pos_w = std::stod(res[2]);
    vel_x = std::stod(res[3]);
    vel_y = std::stod(res[4]);
    vel_w = std::stod(res[5]);
}


void ArduinoComms::setSpeed(int vel_x, int vel_y, int vel_w)
{
    std::ostringstream strs;
    strs << "G " << vel_x << " " << vel_y << " " << vel_w << " _";
    std::string response = sendMsg(strs.str());
}

std::string ArduinoComms::sendMsg(const std::string &msg_to_send, bool print_output)
{
    serial_conn_.write(msg_to_send);
    std::string response = serial_conn_.readline(65536, "_");


    if (print_output)
    {
        RCLCPP_INFO_STREAM(logger_,"Sent: " << msg_to_send);
        RCLCPP_INFO_STREAM(logger_,"Received: " << response);
    }

    return response;
}