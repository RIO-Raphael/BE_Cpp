#include "exception.h"
#include "constantes.h"

Robot_Exception :: Robot_Exception(int ID):id(ID){
    if (ID<=sizeof(TAB_EXCEP)){
        message=TAB_EXCEP[ID];
    }
}