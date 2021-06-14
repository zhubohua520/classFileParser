//
// Created by zbh on 2021/6/8.
//

#ifndef CLASSFILEPARSER_METHOD_H
#define CLASSFILEPARSER_METHOD_H


#include "InstanceKlass.h"

class Method {

private:
    unsigned short *access_flags;

    unsigned short *name_index; //u2

    unsigned short *descriptor_index;

    unsigned short *attributes_count;

    char **p_attributes; //属性集合

    char** p_belong_klass; //找爹用的

public:
    Method(unsigned short *attributesCount);

public:
    unsigned short *getAccessFlags() const;

    void setAccessFlags(unsigned short *accessFlags);

    unsigned short *getNameIndex() const;

    void setNameIndex(unsigned short *nameIndex);

    unsigned short *getDescriptorIndex() const;

    void setDescriptorIndex(unsigned short *descriptorIndex);

    unsigned short *getAttributesCount() const;

    void setAttributesCount(unsigned short *attributesCount);

    char **getPBelongKlass() const;

    void setPBelongKlass(char **pBelongKlass);

};


#endif //CLASSFILEPARSER_METHOD_H
