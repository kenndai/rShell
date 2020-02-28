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

Executer::Executer() {

}

Executer::~Executer() {
    //nukem()
}

void Executer::setExecuter(std::vector<Token*> &tokenList) {
    cleanExecuter();
    this->tokenList = tokenList;
    execute();
}

void Executer::cleanExecuter() {
    this->tokenList.clear();
    this->numList.clear();
}

void Executer::execute() {
    mirror();
    shunting();
    mirror();
    makeTree();
    run();
}

void Executer::mirror() {
    std::vector<Token*> tempVect;

    for (unsigned int i = 1; i <= tokenList.size(); i++) {
        if ( tokenList.at(tokenList.size() - i)->tokenType() == "(") //if "(" switch to ")"
            tempVect.push_back( new PAREN(")"));
        else if ( tokenList.at(tokenList.size() - i)->tokenType() == ")") //if "(" switch to ")"
            tempVect.push_back( new PAREN("("));
        else    //if no bracket detected
            tempVect.push_back( tokenList.at( tokenList.size() - i ) );
    }

    this->tokenList = tempVect;
}

void Executer::shunting() {
    std::stack<Token*> stk;
    std::vector<Token*> vect;

    for (unsigned int i = 0; i < tokenList.size(); i++) {
        //check if bracket
        if (tokenList.at(i)->tokenType() == ")") {   //if end bracket then pop from queue until "(" hit
            while (true) {  //keep popping queue until "(" hit
                if (!stk.empty() && stk.top()->tokenType() != "(") { //if stack not empty and front isn't "(", pop into queue
                    vect.push_back(stk.top());
                    stk.pop();
                } else {    //either empty or top is "("
                    if (stk.top()->tokenType() == "(")
                        stk.pop();
                    break;
                }
            }
        } else if ( tokenList.at(i)->tokenType() == "CMD" ) //if CMD found, enqueue
            vect.push_back(tokenList.at(i));
        else if ( tokenList.at(i)->tokenType() != "SEMI" ) //not ")" or "CMD" or "SEMI" then must be "(", "OR", "AND"
            stk.push(tokenList.at(i));  //push to stack
    }

    while (!stk.empty()) {  //at the end if stack still not empty, enqueue the rest
        vect.push_back(stk.top());
        stk.pop();
    }

    this->tokenList = vect;

}

void Executer::makeTree() {
    for (unsigned int i = 0; i < tokenList.size();) {
        if (!tokenList.empty()) { //if not empty()
            this->numList.push_back(i);   //push back 0
            Token* currentNode = tokenList.at(i); //assign first node
            i++;
            makeTreeRecursiveHelper(i, currentNode); //pass in 1 (next position), first Node
        }
    }
}

void Executer::makeTreeRecursiveHelper(unsigned int &i, Token* currentNode) {
    if ( (currentNode->tokenType() == "AND") || (currentNode->tokenType() == "OR") ) { //if node is AND or OR
        currentNode->assignLeftChild(tokenList.at(i));  //assign next node in list as left child
        i++;                                            //increment so i points to position of next token in list
        makeTreeRecursiveHelper(i, currentNode->getLeftChild()); //send in the left child and fill it's children

        currentNode->assignRightChild(tokenList.at(i));  //do the same to right child
        i++;
        makeTreeRecursiveHelper(i, currentNode->getRightChild());
    }   //else CMD node was found, do nothing
}

void Executer::run() {
    if (numList.size() > 0) { //if list is empty
        for (unsigned int i = 0; i < numList.size(); i++)  //for every element in numList run execute() on it
            tokenList.at(numList.at(i))->execute();
    }
}

#endif // EXECUTER_H
