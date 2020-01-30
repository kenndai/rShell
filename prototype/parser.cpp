#include <iostream>
#include <vector>

using namespace std;

class Parser {

public:

    Parser(std::string &str);
    ~Parser();
    void findConnectors(std::string &str);
    void makeToken(std::string &cmdStr);
    std::vector<std::string> getConnectorList();
    std::vector<std::string> getTokenList();

private:

    vector<std::string> connectorList;
    vector<std::string> tokenList;
};

Parser::Parser(std::string &str) {
    findConnectors(str);
}

Parser::~Parser() {

}

void Parser::findConnectors(std::string &str) {

    std::string AND = " && ";
    std::string OR = " || ";
    std::string SEMI = "; ";
    std::string cmd;
    size_t pos = 0;

    if ( (pos = str.find(AND)) != std::string::npos) { //find &&
        cmd = str.substr(0, pos);
        this->connectorList.push_back(cmd);
        this->tokenList.push_back("AND"); //aka makeToken()
        str.erase(0, pos + AND.length());
        findConnectors(str);

    } else if ( (pos = str.find(OR)) != std::string::npos) { //find ||
        cmd = str.substr(0, pos);
        this->connectorList.push_back(cmd);
        this->tokenList.push_back("OR"); //aka makeToken()
        str.erase(0, pos + AND.length());
        findConnectors(str);

    } else if ( (pos = str.find(SEMI)) != std::string::npos) { //find ;
        cmd = str.substr(0, pos);
        this->connectorList.push_back(cmd);
        this->tokenList.push_back("SEMI"); //aka makeToken()
        str.erase(0, pos + AND.length());
        findConnectors(str);

    } else if ( !str.empty() ) { //not empty then last command remains
        this->connectorList.push_back(str);
        str = "";
    } //string is empty
}

void makeToken(std::string &cmdStr) {

}

std::vector<std::string> Parser::getConnectorList() {
    return this->connectorList;
}

std::vector<std::string> Parser::getTokenList() {
    return this->tokenList;
}


int main()
{
    vector<std::string> connectorList;
    vector<std::string> tokenList;

    std::string input;
    cout << "Input user commands seperated by &&, ||, or ;" << endl;
    getline(cin, input);

    Parser *ParseGod = new Parser(input);
    connectorList = ParseGod->getConnectorList();
    tokenList = ParseGod->getTokenList();

    for (unsigned int i = 0; i < connectorList.size(); i++) {
        std::cout << connectorList.at(i) << std::endl;
    }

    return 0;
}

