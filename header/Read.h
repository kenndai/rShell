#ifndef READ_H
#define READ_H

#include <string>

class Read {

    public:
        Read() {};
        ~Read() {};

    private:

        virtual void trimWhiteSpaces(std::string &str) = 0;

};

#endif // READ_H

