//
// Created by zbh on 2021/6/7.
//

#ifndef CLASSFILEPARSER_INSTANCEKLASS_H
#define CLASSFILEPARSER_INSTANCEKLASS_H


#include "Klass.h"
#include "ConstantPool.h"
#include "InterfaceInfo.h"
#include "FieldInfo.h"
#include "Method.h"
#include "AttributeInfo.h"
#include <string>

using namespace std;

class InstanceKlass : public Klass {


private:

    int *magic;

    int *version;

    unsigned short *constant_pool_count;

    ConstantPool constant_pool;  //size:constantPoolCount-1

    unsigned short access_flags; //u2

    unsigned short this_class; //u2

    unsigned short super_class; //u2

    unsigned short interfaces_count; //u2

    InterfaceInfo interfaces; //u2 结构是Constant_class_info

    unsigned short fields_count; //u2

    FieldInfo fields;

    unsigned short method_count; //u2

    Method methods;

    unsigned short attributes_count; //u2

    AttributeInfo attributes;


public:
    char *getMagic();

    void setMagic(const char *c);

    void setVersion(const char *c);

    unsigned short getMinorVersion();

    unsigned short getMajorVersion();

    void setConstantPoolCount(const char *c);

    unsigned short getConstantPoolCount();
};


#endif //CLASSFILEPARSER_INSTANCEKLASS_H
