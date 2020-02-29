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


#endif // SEMI_H
