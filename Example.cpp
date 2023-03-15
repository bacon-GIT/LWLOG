#include <iostream>
#include "Log.h"

int main() {
    Log::Logger mylogger("TestName");
    mylogger.DEBUG("Test Debug");
    mylogger.INFO("Test Info");
    mylogger.WARN("Test Warning");
    mylogger.ERROR("Test Error");
    return 0;
}