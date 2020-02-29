#include <iostream>
#include <vector>
#include "../header/Executer.h"
#include "../header/Parser.h"
#include "../header/Token.h"

using namespace std;

int main(int argc, char** argv)
{
    std::string input;
    std::vector<Token*> tokenList;
    Parser *Parser_obj = new Parser();
    Executer *Executer_obj = new Executer();

    if (argc > 1) {   //argv was used
        input = argv[1];
        for (unsigned int i = 2; i < argc; i++) //make the input into 1 long string
            input = input + " " + argv[i];

        Parser_obj->setParser(input);   //pass input to parser object
        tokenList = Parser_obj->getTokenList();
        Executer_obj->setExecuter(tokenList); //pass tokenList and ParserList to Executer

        exit(0);    //don't loop if argv was used
    }

    while (true) {
        cout << "[assignment-gitgud-rShell]$ "; //prompt user, get input
        getline(cin, input);

        Parser_obj->setParser(input);   //pass input to parser object
        tokenList = Parser_obj->getTokenList();
        Executer_obj->setExecuter(tokenList); //pass tokenList and ParserList to Executer

    }

    return 0;
}
