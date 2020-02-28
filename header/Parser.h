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

};

Parser::Parser() {
    this->trimmer = new TrimWhiteSpaces();
}

Parser::~Parser() {

}

void Parser::cleanParser() {
    this->tokenList.clear();
}

void Parser::setParser(std::string &str) {
    cleanParser();
    trimmer->trimRightWhiteSpaces(str);
    parseString(str);
    std::cout << std::endl;
}

void Parser::parseString(std::string &str) {
    std::string AND = "&&";
    std::string OR = "||";
    std::string SEMI = ";";
    std::string OPEN_PAREN = "(";
    std::string CLOSE_PAREN = ")";
    size_t pos;
    //size_t tempPos;

    trimmer->trimLeftWhiteSpaces(str);

    if (str.substr(0, 2) == AND) {
        makeToken(AND);
        str.erase(0, AND.length());
        parseString(str);
    } else if (str.substr(0, 2) == OR) {
        makeToken(OR);
        str.erase(0, OR.length());
        parseString(str);
    } else if (str.substr(0, 1) == SEMI) {
        makeToken(SEMI);
        str.erase(0, SEMI.length());
        parseString(str);
    } else if (str.substr(0, 1) == OPEN_PAREN) {
        makeToken(OPEN_PAREN);
        str.erase(0, OPEN_PAREN.length());
        parseString(str);
    } else if (str.substr(0, 1) == CLOSE_PAREN) {
        makeToken(CLOSE_PAREN);
        str.erase(0, CLOSE_PAREN.length());
        parseString(str);
    } else if (str != "" ){ //command found
        pos = findCommandLength(str);
        makeToken(str.substr(0, pos));
        str.erase(0, pos+1);
        parseString(str);
    }

}

size_t Parser::findCommandLength(const std::string &str) {
    size_t tempPos, pos = std::string::npos;
    std::string AND = "&&";
    std::string OR = "||";
    std::string SEMI = ";";
    std::string OPEN_PAREN = "(";
    std::string CLOSE_PAREN = ")";
    std::string connector = "";

    /* Find the next operator that comes in the string */
    if ( (tempPos = str.find(AND)) != std::string::npos ) { //find the first &&
        pos = tempPos;                  //set the initial pos
        connector = AND;
    }
    if ( (tempPos = str.find(OR)) != std::string::npos ) {
        if (pos == std::string::npos || tempPos < pos) {
            pos = tempPos;
            connector = OR;
        }
    }
    if ( (tempPos = str.find(SEMI)) != std::string::npos ) {
        if ( pos == std::string::npos || tempPos < pos ) {
            pos = tempPos;
            connector = SEMI;
        }
    }
    if ( (tempPos = str.find(OPEN_PAREN)) != std::string::npos ) {
        if ( pos == std::string::npos || tempPos < pos ) {
            pos = tempPos;
            connector = SEMI;
        }
    }
    if ( (tempPos = str.find(CLOSE_PAREN)) != std::string::npos ) {
        if ( pos == std::string::npos || tempPos < pos ) {
            pos = tempPos;
            connector = SEMI;
        }
    }
    //no operator was found which means this is the end of the string
    if ( pos == std::string::npos )
        pos = str.length(); //rest of str

    //don't include the operator in the pos
    if ( (connector == AND) || (connector == OR) )
        pos = pos - 2;
    else if ( (connector == SEMI) || (connector == OPEN_PAREN) || (connector == CLOSE_PAREN))
        pos--;

    return pos;

}

Token* Parser::makeToken(std::string type) {
// (, ), ;, &&, ||, cmd
    if (type == "(")
        this->tokenList.push_back(new PAREN("("));
    else if (type == ")")
        this->tokenList.push_back(new PAREN(")"));
    else if (type == "||")
        this->tokenList.push_back(new OR());
    else if (type == "&&")
        this->tokenList.push_back(new AND());
    else if (type == ";")
        this->tokenList.push_back(new SEMI());
    else      //it's a command
        this->tokenList.push_back(new CMD(type));
}

std::vector<Token*> Parser::getTokenList() {
    return this->tokenList;
}


#endif // PARSER_H
