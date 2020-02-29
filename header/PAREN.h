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


#endif // PARENTHESES_H
