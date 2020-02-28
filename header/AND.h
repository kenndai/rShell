#ifndef AND_H
#define AND_H

#include <iostream>
#include "Token.h"

class AND : public Token{

    public:

        AND();
        ~AND();
        void assignLeftChild(Token* t);
        void assignRightChild(Token* t);

        virtual bool execute();
        virtual std::string tokenType();

    private:

        std::string val = "AND";
        Token* leftToken;
        Token* rightToken;

};

AND::AND() {

}

AND::~AND() {
    /* nukem() */
}

void AND::assignRightChild(Token* t) {
    this->rightToken = t;
}

bool AND::execute() {
    if (leftToken == nullptr || rightToken == nullptr)
        throw "Child Token was not defined";
    else if (leftToken->execute() && rightToken->execute()) //if successfully executed
        return true;
    else
        return false;
}

std::string AND::tokenType() {
    return val;
}


#endif // AND_H
