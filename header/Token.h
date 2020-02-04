#ifndef TOKEN_H
#define TOKEN_H

#include <iostream>

using namespace std;

class Token {

    public:

        Token();
        Token(std::string &cmd);
        ~Token();
        std::string& getString();
        std::string* getInfo(); //return the pointer to the array, first element

        Token operator=(const Token &other);

    private:

        std::string cmd;
        std::string info[2];    //3 is a safe number. info shouldn't exceed 5

        bool isValid();
        void extractInfo(std::string &str);
        void trimWhiteSpaces(std::string &str);
};

Token::Token() {

}

Token::Token(std::string &cmd) {
    this->cmd = cmd;
    extractInfo(cmd);
}

Token::~Token() {
    /* nukem() */
}

bool Token::isValid() {
    /* find the first white space then split. Check if left side is
 *     valid command if execvp() doesnt return false value
 *         or just send the left side to execvp() to see if it works */
    return true;
}

void Token::extractInfo(std::string &str) {
    std::string space = " ";
    std::string fileName = "";
    std::string argList = "";
    size_t pos = 0;
    size_t tempPos;

    if ( (tempPos = str.find(space)) != std::string::npos )
        pos = tempPos;
    fileName = str.substr(0, pos);
    argList = str.substr(pos, str.length());
    trimWhiteSpaces(argList);

    this->info[0] = fileName;
    this->info[1] = argList;

}

std::string& Token::getString() {
    return this->cmd;
}

std::string* Token::getInfo() {
    return this->info;
}

void Token::trimWhiteSpaces(std::string &str) {
    /* trim left side */
    str.erase(str.begin(), std::find_if(str.begin(), str.end(),
              std::not1(std::ptr_fun<int, int>(std::isspace))));
    /* trim right side */
    str.erase(std::find_if(str.rbegin(), str.rend(),
              std::not1(std::ptr_fun<int, int>(std::isspace))).base(), str.end());
}

Token Token::operator=(const Token &other) {
    if(this != &other) {
        this->cmd = other.cmd;
        for (unsigned int i = 0; i < cmd.length(); i++)
            this->info[i] = other.info[i];
    }
    return *this;
}

#endif // TOKEN_H
