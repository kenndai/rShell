#include "../header/Parser.h"


Parser::Parser() {

}

Parser::~Parser() {

}

void Parser::setParser(std::string &str) {
    cleanParser();      //delete old data
    parseString(str);
}

void Parser::cleanParser() {
    this->tokenList.clear();
    this->connectorList.clear();
}

void Parser::parseString(std::string &str) {
    std::string AND = " && ";
    std::string OR = " || ";
    std::string SEMI = "; ";
    std::string cmd;
    std::string connector;
    size_t pos = std::string::npos;
    size_t tempPos;

    str = removeComment(str);           //remove everything to rigth of '#'

    /* >>>>>>>>>>>>>>>>>>>>> Find which connector comes next <<<<<<<<<<<<<<<<<<<<<<<<*/

    if ( (tempPos = str.find(AND)) != std::string::npos ) { //find the first &&
        connector = "AND";              //set which connector was last found
        pos = tempPos;                  //set the initial pos
    }
    if ( (tempPos = str.find(OR)) != std::string::npos ) {
        if (pos == std::string::npos || tempPos < pos) {
            connector = "OR";
            pos = tempPos;
        }
    }
    if ( (tempPos = str.find(SEMI)) != std::string::npos ) {
        if ( pos == std::string::npos || tempPos < pos ) {
            connector = "SEMI";
            pos = tempPos;
        }
    }
    if ( pos == std::string::npos )     //pos was never found which means this entire str needs appending
        connector = "NONE";

/* >>>>>>> Next connector position is 'pos' and next connector is 'connector' <<<<<< */

    if (connector == "AND") {
        cmd = str.substr(0, pos);   //grab the portion of str we want
        str.erase(0, cmd.length()); //delete that portion from the original string

        trimWhiteSpaces(cmd);
        this->tokenList.push_back(makeToken(cmd));
        this->connectorList.push_back(connector);

        str.erase(0, AND.length()); //delete portion of string with the connector
        parseString(str);

    } else if (connector == "OR") {
        cmd = str.substr(0, pos);
        str.erase(0, cmd.length());

        trimWhiteSpaces(cmd);
        this->tokenList.push_back(makeToken(cmd));
        this->connectorList.push_back(connector);

        str.erase(0, OR.length());
        parseString(str);

    } else if (connector == "SEMI") {
        cmd = str.substr(0, pos);
        str.erase(0, cmd.length());

        trimWhiteSpaces(cmd);
        this->tokenList.push_back(makeToken(cmd));
        this->connectorList.push_back(connector);

        str.erase(0, SEMI.length());
        parseString(str);

    } else {    // "NONE" was found, this is the end of the string

        trimWhiteSpaces(str);
        this->tokenList.push_back(makeToken(str));
        this->connectorList.push_back(connector);

        str.erase(0, str.length());   //make the string empty
    }

}

Token* Parser::makeToken(std::string &cmd) {
    Token *t = new Token(cmd);
    return t;
}

std::vector<std::string>& Parser::getConnectorList() {
    return this->connectorList;
}

std::vector<Token*>& Parser::getTokenList() {
    return this->tokenList;
}

std::string& Parser::removeComment(std::string &str) {
    //everything to right of "#" is comment
    size_t pos = str.find("#");
    str = str.substr(0, pos);
    return str;
}

void Parser::trimWhiteSpaces(std::string &str) {
    trimLeftWhiteSpaces(str);
    trimRightWhiteSpaces(str);
}

void Parser::trimLeftWhiteSpaces(std::string &str) {
    str.erase(str.begin(), std::find_if(str.begin(), str.end(),
              std::not1(std::ptr_fun<int, int>(std::isspace))));
}

void Parser::trimRightWhiteSpaces(std::string &str) {
    str.erase(std::find_if(str.rbegin(), str.rend(),
              std::not1(std::ptr_fun<int, int>(std::isspace))).base(), str.end());
}
