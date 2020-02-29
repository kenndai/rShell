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


#endif // TRIMWHITESPACES_H
