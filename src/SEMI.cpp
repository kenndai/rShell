#include "../header/SEMI.h"

SEMI::SEMI() {

}

SEMI::~SEMI() {
    /* nukem() */
}

Token* SEMI::getLeftChild() {
    return nullptr;
}

Token* SEMI::getRightChild() {
    return nullptr;
}

void SEMI::assignLeftChild(Token* t){

}

void SEMI::assignRightChild(Token* t){

}

bool SEMI::execute() {
    //error
}

std::string SEMI::tokenType() {
    return val;
}
