//
// Created by zbh on 2021/6/9.
//

#ifndef CLASSFILEPARSER_CLASSFILEPARSER_H
#define CLASSFILEPARSER_CLASSFILEPARSER_H


#include "../oops/InstanceKlass.h"

class ClassFileParser {

public:
    static InstanceKlass *parseClassFile(ifstream *p_in);

    static char *readBytes(ifstream *p_in, unsigned int capacity);

    static char *readByte(ifstream *p_in);

    static void parseConstantPool(ifstream *p_in, InstanceKlass *instance_klass);
};


#endif //CLASSFILEPARSER_CLASSFILEPARSER_H
