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

        // Get Current Time
        time_t now = time(0);
        char* dt = ctime(&now);
        std::string log_suffix = dt;

        public:
            Logger(std::string file) {
                if(fileExists(file)) {
                logfile.open(file, std::ios_base::app);
                } else {
                    std::cerr << "[-] Log file does not exist. Attempting to create it...";
                    std::ofstream {file};
                    logfile.open(file, std::ios_base::app);
                }
            }

            ~Logger() {
                logfile.close();
            }

            void DEBUG(std::string msg) {
                log_prefix = "[DEBUG] | ";
                log = log_prefix + msg + " | " + log_suffix;
                writeFile(log);
            }

            void INFO(std::string msg) {
                log_prefix = "[INFO] | ";
                log = log_prefix + msg + " | " + log_suffix;
                writeFile(log);
            }
            void WARN(std::string msg) { 
                log_prefix = "[WARN] | ";
                log = log_prefix + msg + " | " + log_suffix;
                writeFile(log);
            }
            void ERROR(std::string msg) {
                log_prefix = "[ERROR] | ";
                log = log_prefix + msg + " | " + log_suffix;
                writeFile(log);
            }

        private:
            void writeFile(std::string msg) {
                logfile << msg;
            }
            inline bool fileExists (const std::string& name) {
                struct stat buffer;   
                return (stat (name.c_str(), &buffer) == 0); 
            }
            std::string msg;
    };
}