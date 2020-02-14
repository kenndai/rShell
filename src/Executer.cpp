#include "Executer.h"


Executer::Executer() {
    //initialize class variables
}

Executer::~Executer() {
    //nukem()
}

void Executer::setExecuter(std::vector<Token*> &tokenList, std::vector<std::string> &connectionList) {
    std::vector<Command*> commandList;
    for (unsigned int i = 0; i < tokenList.size(); i++) //make Command object for every Token
        commandList.push_back( makeCommand( tokenList.at(i)->getInfo() ) );

    execute(commandList, connectionList);   //execute the commands
}

Command* Executer::makeCommand(std::string *info) {
    Command *c = new Command(info);
    return c;
}

void Executer::execute(std::vector<Command*> &commandList, std::vector<std::string> &connectionList) {
    //execute commands based on logic
    bool cmdSuccess;
    for (unsigned int i = 0; i < commandList.size(); i++) {         //for every command...
        cmdSuccess = commandList.at(i)->run();                      //run cmd, did it succeed?

        if ( !cmdSuccess && (connectionList.at(i) == "AND") )       //if cmd failed + &&, terminate
            break;
        else if ( cmdSuccess && (connectionList.at(i) == "OR") )    //if cmd succeeded + ||, terminate
            break;
      //else all other cases keep going
    }
}
