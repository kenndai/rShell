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
        virtual void assignLeftChild(Token* t);
        virtual void assignRightChild(Token* t);
        virtual Token* getLeftChild();
        virtual Token* getRightChild();

    private:

        std::string val;

};

PAREN::PAREN(std::string bracket) {
    this->val = bracket;
}

PAREN::~PAREN() {
    /* nukem() */
}

void PAREN::assignLeftChild(Token* t) {

}

void PAREN::assignRightChild(Token* t) {

}

Token* PAREN::getLeftChild() {
    return nullptr;
}

Token* PAREN::getRightChild() {
    return nullptr;
}

bool PAREN::execute() {
    //error
}

std::string PAREN::tokenType() {
    return val;
}


#endif // PARENTHESES_H
