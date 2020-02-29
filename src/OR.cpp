#include "../header/OR.h"

OR::OR() {

}

OR::~OR() {
    /* nukem() */
}

Token* OR::getLeftChild() {
    return this->leftToken;
}

Token* OR::getRightChild() {
    return this->rightToken;
}

void OR::assignLeftChild(Token* t) {
    this->leftToken = t;
}

void OR::assignRightChild(Token* t) {
    this->rightToken = t;
}

bool OR::execute() {
    if (leftToken == nullptr || rightToken == nullptr)
        throw "Child Token was not defined";
    else if (leftToken->execute() || rightToken->execute()) //if successfully executed
        return true;
    else
        return false;
}

std::string OR::tokenType() {
    return val;
}
