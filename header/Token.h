#ifndef TOKEN_H
#define TOKEN_H

#include <iostream>

class Token {

    public:

        Token();
        ~Token();

        virtual bool execute() = 0;
        virtual std::string tokenType() = 0;
        virtual void assignLeftChild(Token* t) = 0;
        virtual void assignRightChild(Token* t) = 0;
        virtual Token* getLeftChild() = 0;
        virtual Token* getRightChild() = 0;

};

Token::Token() {

}

Token::~Token() {
    /* nukem() */
}


#endif // TOKEN_H
