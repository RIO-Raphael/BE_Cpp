#include "stdio.h"
#include <iostream>
#include <string>

using namespace std;

class Robot_Exception{
    public:
        Robot_Exception(int ID);
        string Get_message(){return message;}
    private :
        int id;
        string message;
};