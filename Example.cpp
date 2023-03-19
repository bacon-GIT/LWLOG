#include <iostream>
#include "Log.h"

Log::Logger mylogger("TestName", true);


int main() {
    mylogger.DEBUG("Test Debug");
    mylogger.INFO("Test Info");
    mylogger.WARN("Test Warning");
    mylogger.ERROR("Test Error");
    mylogger.CloseLogger();
    return 0;
}