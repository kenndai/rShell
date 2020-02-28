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

        std::string val = ";";
        Token* leftToken;
        Token* parentToken;

};

SEMI::SEMI() {

}

SEMI::~SEMI() {
    /* nukem() */
}

Token* SEMI::getLeftChild() {
    return this->leftToken;
}

Token* SEMI::getRightChild() {
    return nullptr;
}

void SEMI::assignLeftChild(Token* t){
    this->leftToken = t;
}

void SEMI::assignRightChild(Token* t){

}

bool SEMI::execute() {
    if (leftToken != nullptr) {
        leftToken->execute();
        return true;    //always return true
    } else //no child token
        throw "-bash: syntax error near unexpected token `;'";
}

std::string SEMI::tokenType() {
    return val;
}


#endif // SEMI_H
