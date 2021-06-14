//
// Created by zbh on 2021/6/8.
//

#include "AttributeInfo.h"

unsigned short *AttributeInfo::getAttributeNameIndex() const {
    return attributeNameIndex;
}

void AttributeInfo::setAttributeNameIndex(unsigned short *attributeNameIndex) {
    AttributeInfo::attributeNameIndex = attributeNameIndex;
}

unsigned int *AttributeInfo::getAttributeLength() const {
    return attributeLength;
}

void AttributeInfo::setAttributeLength(unsigned int *attributeLength) {
    AttributeInfo::attributeLength = attributeLength;
}


