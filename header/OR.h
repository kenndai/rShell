#ifndef OR_H
#define OR_H

#include <iostream>
#include "Token.h"

class OR : public Token{

    public:

        OR();
        ~OR();
        void assignLeftChild(Token* t);
        void assignRightChild(Token* t);

        virtual bool execute();
        virtual std::string tokenType();

    private:

        std::string val = "OR";
        Token* leftToken;
        Token* rightToken;
};

OR::OR() {

}

OR::~OR() {
    /* nukem() */
}

void OR::assignLeftChild(Token* t) {
    this->leftToken = t;
}

void OR::assignRightChild(Token* t) {
    this->rightToken = t;
}

bool OR::execute() {
    if (leftToken == nullptr || rightToken == nullptr)
        throw "Child Token was not defined";
    else if (leftToken->execute() || rightToken->execute()) //if successfully executed
        return true;
    else
        return false;
}

std::string OR::tokenType() {
    return val;
}

#endif // OR_H
