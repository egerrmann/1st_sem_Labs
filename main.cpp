//variant 9
#include <iostream>
#include <fstream>

using namespace std;

char *strncat(char *destination, const char *source, int n) {
    char *lastSymbol = destination;
    for (; *lastSymbol != '\0'; ++lastSymbol);
        while (*source != '\0' && n > 0) {
            *lastSymbol++ = *source++;
            --n;
        }
    *lastSymbol = '\0';
    return destination;
}

int main() {
}