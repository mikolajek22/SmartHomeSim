#include <iostream>
#include "logger.h"
#include <string>

using namespace std;
void print_log(string level, string color, string messages) {
    cout << color << "[" << level << "]" << ": " << messages << END_COLOR << endl;
}

void color_print(string color, string messages) {
    cout << color << messages << END_COLOR << endl;
}