#ifndef OR_H
#define OR_H

#include <iostream>
#include "Token.h"

class OR : public Token{

    public:

        OR();
        ~OR();

        virtual void assignLeftChild(Token* t);
        virtual void assignRightChild(Token* t);
        virtual Token* getLeftChild();
        virtual Token* getRightChild();
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

Token* OR::getLeftChild() {
    return this->leftToken;
}

Token* OR::getRightChild() {
    return this->rightToken;
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
