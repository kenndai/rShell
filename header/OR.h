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


#endif // OR_H
