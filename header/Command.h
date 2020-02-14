#ifndef COMMAND_H
#define COMMAND_H

#include "unistd.h"
#include <iostream>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

class Command {

    public:

        Command(std::string *info);
        ~Command();
        bool run();

    private:

        std::string info[2];

};


#endif // COMMAND_H
