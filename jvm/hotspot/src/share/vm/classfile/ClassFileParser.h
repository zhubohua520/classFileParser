//
// Created by zbh on 2021/6/9.
//

#ifndef CLASSFILEPARSER_CLASSFILEPARSER_H
#define CLASSFILEPARSER_CLASSFILEPARSER_H


#include "../oops/InstanceKlass.h"

class ClassFileParser {

public:
    static InstanceKlass *parseClassFile(ifstream *p_in);

    static char *readBytes(ifstream *p_in, size_t capacity);

    static char *readByte(ifstream *p_in);

    static int *readByteToInt(ifstream *p_in);

    static unsigned int * readBytesToUnsignedInt(ifstream *p_in, size_t capacity);

    static short *readBytesToShort(ifstream *p_in, size_t capacity);

    static unsigned short *readBytesToUnsignedShort(ifstream *p_in, size_t capacity);

    static char *readBytesToString(ifstream *p_in, size_t capacity);

    static void parseConstantPool(ifstream *p_in, InstanceKlass *instance_klass);

    static void parseInterface(ifstream *p_in, InstanceKlass *instance_klass);

    static void parseFieldsInfo(ifstream *p_in, InstanceKlass *instance_klass);

    static void parseMethodInfo(ifstream *p_in, InstanceKlass *instance_klass);

    static AttributeInfo ** parseAttributeInfo(ifstream *p_in, ConstantPool *constant_pool);
};


#endif //CLASSFILEPARSER_CLASSFILEPARSER_H
