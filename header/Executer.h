#ifndef EXECUTER_H
#define EXECUTER_H

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include "Token.h"
#include "PAREN.h"
#include "AND.h"
#include "OR.h"
#include "SEMI.h"
#include "CMD.h"

class Executer {

    public:

        Executer();
        ~Executer();
        void setExecuter(std::vector<Token*> &tokenList);

    private:

        std::vector<Token*> tokenList;
        std::vector<unsigned int> numList;

        void cleanExecuter();
        void execute();
        void mirror();
        void shunting();
        void makeTree();
        void makeTreeRecursiveHelper(unsigned int &i, Token* currentNode);
        void run();

};


#endif // EXECUTER_H
