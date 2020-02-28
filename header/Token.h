#ifndef TOKEN_H
#define TOKEN_H

#include <iostream>

class Token {

    public:

        Token();
        ~Token();

        virtual bool execute() = 0;
        virtual std::string tokenType() = 0;

};

Token::Token() {

}

Token::~Token() {
    /* nukem() */
}


#endif // TOKEN_H
