#include <iostream>
#include <vector>
#include "../header/Command.h"
#include "../header/Executer.h"
#include "../header/Parser.h"

int main()
{
    std::vector<std::string> connectorList;
    std::vector<Token*> tokenList;
    Parser *Parser_obj = new Parser();
    Executer *Executer_obj = new Executer();

    std::string input;
    std::string inputCopy;  //this string is never passed therefore never changed

    while (true) {
        cout << "[assignment-gitgud-rShell]$ "; //prompt user, get input
        getline(cin, input);
        inputCopy = input;

        Parser_obj->setParser(input);   //pass input to parser object
        tokenList = Parser_obj->getTokenList();
        connectorList = Parser_obj->getConnectorList();
        Executer_obj->setExecuter( tokenList, connectorList );  //pass tokenList and ParserList to Executer

    }

    return 0;
}
