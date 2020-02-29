#ifndef SEMI_H
#define SEMI_H

#include "Token.h"

class SEMI : public Token{

    public:

        SEMI();
        ~SEMI();

        virtual bool execute();
        virtual std::string tokenType();
        virtual void assignLeftChild(Token* t);
        virtual void assignRightChild(Token* t);
        virtual Token* getLeftChild();
        virtual Token* getRightChild();

    private:

        std::string val = "SEMI";

};

SEMI::SEMI() {

}

SEMI::~SEMI() {
    /* nukem() */
}

Token* SEMI::getLeftChild() {
    return nullptr;
}

Token* SEMI::getRightChild() {
    return nullptr;
}

void SEMI::assignLeftChild(Token* t){

}

void SEMI::assignRightChild(Token* t){

}

bool SEMI::execute() {
    //error
}

std::string SEMI::tokenType() {
    return val;
}


#endif // SEMI_H
