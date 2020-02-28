#ifndef PAREN_H
#define PAREN_H

#include <iostream>
#include "Token.h"

class PAREN : public Token{

    public:

        PAREN(std::string bracket);
        ~PAREN();

        virtual bool execute();
        virtual std::string tokenType();

    private:

        std::string val;

};

PAREN::PAREN(std::string bracket) {
    this->val = bracket;
}

PAREN::~PAREN() {
    /* nukem() */
}

bool PAREN::execute() {
    //error
}

std::string PAREN::tokenType() {
    return val;
}


#endif // PARENTHESES_H
