#ifndef AND_H
#define AND_H

#include <iostream>
#include "Token.h"

class AND : public Token{

    public:

        AND();
        ~AND();

        virtual void assignLeftChild(Token* t);
        virtual void assignRightChild(Token* t);
        virtual Token* getLeftChild();
        virtual Token* getRightChild();
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

Token* AND::getLeftChild() {
    return this->leftToken;
}

Token* AND::getRightChild() {
    return this->rightToken;
}

void AND::assignRightChild(Token* t) {
    this->rightToken = t;
}

void AND::assignLeftChild(Token* t) {
    this->leftToken = t;
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
