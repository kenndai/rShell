#include <iostream>
#include <vector>
#include "../header/Executer.h"
#include "../header/Parser.h"
#include "../header/Token.h"

using namespace std;

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
        //Executer_obj->setExecuter( tokenList, connectorList );  //pass tokenList and ParserList to Executer

        for (unsigned int i = 0; i < tokenList.size(); i++) {
            std::cout << tokenList.at(i)->execute() << std::endl;
        }

    }

    return 0;
}
