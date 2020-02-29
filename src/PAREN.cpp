#include "../header/PAREN.h"

PAREN::PAREN(std::string bracket) {
    this->val = bracket;
}

PAREN::~PAREN() {
    /* nukem() */
}

void PAREN::assignLeftChild(Token* t) {

}

void PAREN::assignRightChild(Token* t) {

}

Token* PAREN::getLeftChild() {
    return nullptr;
}

Token* PAREN::getRightChild() {
    return nullptr;
}

bool PAREN::execute() {
    //error
}

std::string PAREN::tokenType() {
    return val;
}
