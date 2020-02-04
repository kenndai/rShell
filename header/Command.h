#ifndef COMMAND_H
#define COMMAND_H

#include <iostream>

class Command {

    public:

        Command(std::string *info);
        ~Command();
        bool run();
        bool checkExit();

    private:

        bool exit = false;
        std::string info[2];
};

Command::Command(std::string *info) {
    this->info[0] = info[0];
    this->info[1] = info[1];
}

Command::~Command() {
    //nukem()
}

bool Command::run() {
    //fork(), execvp(), waitpid()
    //if exit command was called set exit variable to true
    //check wifexit() if successful or not, return true or false
    std::cout << info[0] << " " << info[1] << std::endl;    //just for testing purposes to see which commands were called
    return true;
}

bool Command::checkExit() {
    return this->exit;
}

#endif // COMMAND_H
