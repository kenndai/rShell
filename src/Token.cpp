#include "Token.h"


Token::Token() {

}

Token::Token(std::string &cmd) {
    this->cmd = cmd;
    extractInfo(cmd);
}

Token::~Token() {
    /* nukem() */
}

void Token::extractInfo(std::string &str) {
    std::string space = " ";
    std::string fileName = "";
    std::string argList = "";
    size_t pos = 0;
    size_t tempPos;

    if ( (tempPos = str.find(space)) != std::string::npos )
        pos = tempPos;
    else if ( (str.length() != 0) && (str.find(space) == std::string::npos) )
        pos = str.length();
    fileName = str.substr(0, pos);
    argList = str.substr(pos, str.length());

    trimWhiteSpaces(argList);

    this->info[0] = fileName;
    this->info[1] = removeQuotations(argList);
}

std::string& Token::getString() {
    return this->cmd;
}

std::string* Token::getInfo() {
    return this->info;
}

std::string& Token::removeQuotations(std::string &str) {
    str.erase( remove( str.begin(), str.end(), '\"' ), str.end() );
    return str;
}


Token Token::operator=(const Token &other) {
    if(this != &other) {
        this->cmd = other.cmd;
        for (unsigned int i = 0; i < cmd.length(); i++)
            this->info[i] = other.info[i];
    }
    return *this;
}

void Token::trimWhiteSpaces(std::string &str) {
    str.erase(str.begin(), std::find_if(str.begin(), str.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
    str.erase(std::find_if(str.rbegin(), str.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), str.end());
}
