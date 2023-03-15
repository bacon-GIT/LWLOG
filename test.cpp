#include <iostream>
#include "Log.h"

int main() {
    Log::Logger mylogger("C:\\Users\\jbaco\\Desktop\\scripts\\LogSizzle\\testlog.txt");
    mylogger.WARN("Test Warning");
    return 0;
}