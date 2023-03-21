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

/*
Author:     bacon-GIT @ Github
Version:    1.2
Info:       A header file for quick logging capabilities

            #include <Log.h>
            Logger(std::string file, bool out_flag_param, int log_level_param)
            
            Log Levels:
                0   -   NONE
                1   -   DEBUG
                2   -   INFO
                3   -   WARM
                4   -   ERROR
                5   -   CRITICAL
*/


namespace Log {
    class Logger {
        std::ofstream logfile;
        std::string log;
        std::string log_prefix;

        bool out_flag;
        int log_level;

        // Get Current Time
        time_t now = time(0);
        char* dt = ctime(&now);
        std::string log_suffix = dt;

        public:
            Logger(std::string file, bool out_flag_param, int log_level_param) {
                log_level = log_level_param;
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
                if (log_level > 0) {
                    writeFile(stringBuilder(msg, "[DEBUG] "));
                }
            }
            void INFO(std::string msg) {
                if (log_level > 1) {
                    writeFile(stringBuilder(msg, "[INFO] "));
                }
            }
            void WARN(std::string msg) { 
                if (log_level > 2) {
                    writeFile(stringBuilder(msg, "[WARN] "));
                }
            }
            void ERROR(std::string msg) {
                if (log_level > 3) {
                    writeFile(stringBuilder(msg, "[ERROR] "));
                }
            }
             void CRITICAL(std::string msg) {
                if (log_level > 4) {
                    writeFile(stringBuilder(msg, "[CRITICAL] "));
                }
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