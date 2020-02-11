#ifndef TRIMWHITESPACE_H
#define TRIMWHITESPACE_H

#include <iostream>
#include <algorithm>

using namespace std;

class TrimWhiteSpace {

    public:
        TrimWhiteSpace();
        ~TrimWhiteSpace();
        void trimLeftWhiteSpaces(std::string &str);
        void trimRightWhiteSpaces(std::string &str);
        void trimBothWhiteSpaces(std::string &str);

};

TrimWhiteSpace::TrimWhiteSpace() {

}

TrimWhiteSpace::~TrimWhiteSpace() {

}

void TrimWhiteSpace::trimLeftWhiteSpaces(std::string &str) {
    str.erase(str.begin(), std::find_if(str.begin(), str.end(),
              std::not1(std::ptr_fun<int, int>(std::isspace))));
}

void TrimWhiteSpace::trimRightWhiteSpaces(std::string &str) {
    str.erase(std::find_if(str.rbegin(), str.rend(),
              std::not1(std::ptr_fun<int, int>(std::isspace))).base(), str.end());
}

void TrimWhiteSpace::trimBothWhiteSpaces(std::string &str) {
    trimLeftWhiteSpaces(str);
    trimRightWhiteSpaces(str);
}

#endif // TRIMWHITESPACE_H

