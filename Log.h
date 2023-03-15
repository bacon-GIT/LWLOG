#ifndef Log_h
#define Log_h
#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
#include <ctime> 
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
                logfile.open(file, std::ios_base::app);
            }
                
            ~Logger() {
                logfile.close();
            }

            void DEBUG(std::string msg) {
                log_prefix = "[DEBUG] ";
                log = log_prefix + msg + " " + log_suffix;
                WriteFile(log);
            }

            void INFO(std::string msg) {
                log_prefix = "[INFO] ";
                log = log_prefix + msg + " " + log_suffix;
                WriteFile(log);
            }
            void WARN(std::string msg) { 
                log_prefix = "[WARN] ";
                log = log_prefix + msg + " " + log_suffix;
                WriteFile(log);
            }
            void ERROR(std::string msg) {
                log_prefix = "[ERROR] ";
                log = log_prefix + msg + " " + log_suffix;
                WriteFile(log);
            }

        private:
            void WriteFile(std::string msg) {
                logfile << msg;
            }
            std::string msg;
    };
}