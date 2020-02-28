#ifndef CMD_H
#define CMD_H

#include <iostream>
#include "Token.h"
#include "TrimWhiteSpaces.h"

class CMD : public Token{

    public:

        std::string arg[3];

        CMD(std::string cmdStr);
        ~CMD();

        virtual bool execute();
        virtual std::string tokenType();

        CMD operator=(const CMD &other);

    private:

        TrimWhiteSpaces *trimmer;
        std::string val = "CMD";

        void extractInfo(std::string &str);
        std::string& removeQuotations(std::string &str);
        std::string& removeBrackets(std::string &str);

};

CMD::CMD(std::string cmdStr) {
    trimmer->trimBothWhiteSpaces(cmdStr);
    extractInfo(cmdStr);
}

CMD::~CMD() {
    /* nukem() */
}

void CMD::extractInfo(std::string &str) {
    std::string space = " ";
    std::string tempArg;
    size_t pos;

    str = removeBrackets(str);

    for (unsigned int i = 0; i < 3; i++) {
        if ( (pos = str.find(space)) != std::string::npos ) //next space found
            tempArg = str.substr(pos);
        else if ( (str.length() != 0) && (str.find(space) == std::string::npos) ) //no spaces left but still need to append rest of string
            tempArg = str;
        else
            tempArg = "";

        if (pos != std::string::npos) { //if string isn't empty
            if (i == 1) //if second argument
                arg[i] = removeQuotations(tempArg);
            else
                arg[i] = tempArg;
        }
        trimmer->trimLeftWhiteSpaces(str);
    }

}

std::string& CMD::removeBrackets(std::string &str) {

}

std::string& CMD::removeQuotations(std::string &str) {
    str.erase( remove( str.begin(), str.end(), '\"' ), str.end() );
    return str;
}

bool CMD::execute() {
    std::cout << arg[0] << " " << arg[1] << " " << arg[3] << std::endl;
}

std::string CMD::tokenType() {
    return val;
}

CMD CMD::operator=(const CMD &other) {
    if(this != &other) {
        for (unsigned int i = 0; i < arg->size(); i++)
            this->arg[i] = other.arg[i];
    }
    return *this;
}


#endif // COMMAND_H
