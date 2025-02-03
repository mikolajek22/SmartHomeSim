#include <string>
using namespace std;
#define ERROR_COLOR         "\033[31m"
#define INFO_COLOR          "\033[32m"
#define WARNING_COLOR       "\033[33m"
#define END_COLOR           "\033[0m"
void print_log(string level, string color, string messages);
#define LOG_INFO(msg)       print_log("INFO", INFO_COLOR, msg)
#define LOG_WARNING(msg)    print_log("WARNING", WARNING_COLOR, msg)
#define LOG_ERROR(msg)      print_log("ERROR", ERROR_COLOR, msg)