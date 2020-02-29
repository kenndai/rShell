#include "../header/Parser.h"

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
}

void Parser::parseString(std::string &str) {
    std::string AND = "&&";
    std::string OR = "||";
    std::string SEMI = ";";
    std::string OPEN_PAREN = "(";
    std::string CLOSE_PAREN = ")";
    size_t pos;

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
        str.erase(0, pos);
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
