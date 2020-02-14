#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <vector>
#include <algorithm>
#include "Token.h"
#include "Read.h"

using namespace std;

class Parser : public Read {

    public:

        Parser();
        ~Parser();
        void setParser(std::string &str);
        std::vector<std::string>& getConnectorList();
        std::vector<Token*>& getTokenList();

    private:

        vector<std::string> connectorList;  //list of AND OR SEMI
        vector<Token*> tokenList;   //list of TOKEN objects

        Token* makeToken(std::string &cmd);
        void parseString(std::string &str);
        void cleanParser();
        std::string& removeComment(std::string &str);
        virtual void trimWhiteSpaces(std::string &str);
        void trimLeftWhiteSpaces(std::string &str);
        void trimRightWhiteSpaces(std::string &str);

};


#endif // PARSER_H
