//
// Created by zbh on 2021/6/8.
//

#include "Method.h"

unsigned short *Method::getAccessFlags() const {
    return access_flags;
}

void Method::setAccessFlags(unsigned short *accessFlags) {
    access_flags = accessFlags;
}

unsigned short *Method::getNameIndex() const {
    return name_index;
}

void Method::setNameIndex(unsigned short *nameIndex) {
    name_index = nameIndex;
}

unsigned short *Method::getDescriptorIndex() const {
    return descriptor_index;
}

void Method::setDescriptorIndex(unsigned short *descriptorIndex) {
    descriptor_index = descriptorIndex;
}

unsigned short *Method::getAttributesCount() const {
    return attributes_count;
}

void Method::setAttributesCount(unsigned short *attributesCount) {
    attributes_count = attributesCount;
}

Method::Method(unsigned short *attributesCount) : attributes_count(attributesCount) {

    p_attributes = (char **) malloc(*attributesCount * sizeof(p_attributes));
}

char **Method::getPBelongKlass() const {
    return p_belong_klass;
}

void Method::setPBelongKlass(char **pBelongKlass) {
    p_belong_klass = pBelongKlass;
}


