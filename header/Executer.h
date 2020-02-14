#ifndef EXECUTER_H
#define EXECUTER_H

#include <iostream>
#include <vector>
#include "Token.h"
#include "Command.h"

class Executer {

    public:

        Executer();
        ~Executer();
        void setExecuter(std::vector<Token*> &tokenList, std::vector<std::string> &connectionList);

    private:

        Command* makeCommand(std::string *info);
        void execute(std::vector<Command*> &commandList, std::vector<std::string> &connectionList);

};


#endif // EXECUTER_H
