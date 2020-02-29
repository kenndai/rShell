#ifndef CMD_H
#define CMD_H

#include <iostream>
#include "Token.h"
#include "TrimWhiteSpaces.h"
#include "unistd.h"
#include <iostream>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>


class CMD : public Token{

    public:

        std::string info[3];

        CMD(std::string cmdStr);
        ~CMD();

        virtual bool execute();
        virtual std::string tokenType();
        virtual void assignLeftChild(Token* t);
        virtual void assignRightChild(Token* t);
        virtual Token* getLeftChild();
        virtual Token* getRightChild();

    private:

        TrimWhiteSpaces *trimmer;
        std::string val = "CMD";
        bool bracketsFound = false;

        void extractInfo(std::string &str);
        std::string& removeQuotations(std::string &str);
        std::string& removeBrackets(std::string &str);
        void convertToTestCmd();
        void checkEcho();
        bool runTest();

};


#endif // COMMAND_H
