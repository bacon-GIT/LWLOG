#ifndef Log_h
#define Log_h
#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
#include <ctime> 
#include <sys/stat.h>
#include <unistd.h>
#endif


namespace Log {
    class Logger {
        std::ofstream logfile;
        std::string log;
        std::string log_prefix;

        bool out_flag;

        // Get Current Time
        time_t now = time(0);
        char* dt = ctime(&now);
        std::string log_suffix = dt;

        public:
            Logger(std::string file, bool out_flag_param) {
                out_flag = out_flag_param;
                if(fileExists(file)) {
                logfile.open(file, std::ios_base::app);
                } else {
                    std::cerr << "[-] Log file does not exist. Attempting to create it...";
                    std::ofstream {file};
                    logfile.open(file, std::ios_base::app);
                }
            }
            std::string stringBuilder(std::string msg, std::string log_prefix) {
                return log_prefix + msg + " " + log_suffix;
            }
            void DEBUG(std::string msg) {
                writeFile(stringBuilder(msg, "[DEBUG] "));
            }
            void INFO(std::string msg) {
                writeFile(stringBuilder(msg, "[INFO] "));
            }
            void WARN(std::string msg) { 
                writeFile(stringBuilder(msg, "[WARN] "));
            }
            void ERROR(std::string msg) {
                writeFile(stringBuilder(msg, "[ERROR] "));
            }
            void CloseLogger() {
                logfile.close();
            }

        private:
            void writeFile(std::string msg) {
                logfile << msg;
                if (out_flag) {
                    std::cout << msg;
                }
            }
            inline bool fileExists (const std::string& name) {
                struct stat buffer;   
                return (stat (name.c_str(), &buffer) == 0); 
            }
            std::string msg;
    };
}