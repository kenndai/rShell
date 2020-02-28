#ifndef SEMI_H
#define SEMI_H

#include "Token.h"

class SEMI : public Token{

    public:

        SEMI();
        ~SEMI();
        void assignChild(Token* t);

        virtual bool execute();
        virtual std::string tokenType();

    private:

        std::string val = ";";
        Token* t = t;

};

SEMI::SEMI() {

}

SEMI::~SEMI() {
    /* nukem() */
}

void SEMI::assignChild(Token* t){
    this->t = t;
}

bool SEMI::execute() {
    if (t != nullptr) {
        t->execute();
        return true;    //always return true
    } else //no child token
        throw "-bash: syntax error near unexpected token `;'";
}

std::string SEMI::tokenType() {
    return val;
}


#endif // SEMI_H
