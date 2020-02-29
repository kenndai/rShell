#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <vector>
#include <algorithm>
#include "Token.h"
#include "TrimWhiteSpaces.h"
#include "AND.h"
#include "OR.h"
#include "SEMI.h"
#include "PAREN.h"
#include "CMD.h"

class Parser {

    public:

        Parser();
        ~Parser();
        void setParser(std::string &str);
        std::vector<Token*> getTokenList();

    private:

        std::vector<Token*> tokenList;   //list of TOKEN objects
        TrimWhiteSpaces *trimmer;

        Token* makeToken(std::string type);
        void cleanParser();
        void parseString(std::string &str);
        size_t findCommandLength(const std::string &str);
        std::string& removeComment(std::string &str);

};


#endif // PARSER_H
