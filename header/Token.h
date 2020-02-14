#ifndef TOKEN_H
#define TOKEN_H

#include <iostream>
#include <algorithm>
#include "Read.h"

using namespace std;

class Token : public Read {

    public:

        Token();
        Token(std::string &cmd);
        ~Token();
        std::string& getString();
        std::string* getInfo(); //return the pointer to the array, first element

        Token operator=(const Token &other);

    private:

        std::string cmd;
        std::string info[2];    //3 is a safe number. info shouldn't exceed 5

        void extractInfo(std::string &str);
        std::string& removeQuotations(std::string &str);
        virtual void trimWhiteSpaces(std::string &str);

};


#endif // TOKEN_H
