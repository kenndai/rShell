#ifndef TRIMWHITESPACES_H
#define TRIMWHITESPACES_H

#include <iostream>
#include <algorithm>

class TrimWhiteSpaces {

    public:
        TrimWhiteSpaces();
        ~TrimWhiteSpaces();
        void trimLeftWhiteSpaces(std::string &str);
        void trimRightWhiteSpaces(std::string &str);
        void trimBothWhiteSpaces(std::string &str);

};

TrimWhiteSpaces::TrimWhiteSpaces() {

}

TrimWhiteSpaces::~TrimWhiteSpaces() {
    /*nukem*/
}

void TrimWhiteSpaces::trimLeftWhiteSpaces(std::string &str) {
    str.erase(str.begin(), std::find_if(str.begin(), str.end(),
                  std::not1(std::ptr_fun<int, int>(std::isspace))));
}

void TrimWhiteSpaces::trimRightWhiteSpaces(std::string &str) {
    str.erase(std::find_if(str.rbegin(), str.rend(),
                  std::not1(std::ptr_fun<int, int>(std::isspace))).base(), str.end());
}

void TrimWhiteSpaces::trimBothWhiteSpaces(std::string &str) {
    trimLeftWhiteSpaces(str);
    trimRightWhiteSpaces(str);
}


#endif // TRIMWHITESPACES_H
