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


#endif // AND_H
