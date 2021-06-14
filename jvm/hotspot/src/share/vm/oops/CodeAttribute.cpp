//
// Created by zbh on 2021/6/14.
//

#include "CodeAttribute.h"

unsigned short *CodeAttribute::getMaxStack() const {
    return maxStack;
}

void CodeAttribute::setMaxStack(unsigned short *maxStack) {
    CodeAttribute::maxStack = maxStack;
}

unsigned short *CodeAttribute::getMaxLocals() const {
    return maxLocals;
}

void CodeAttribute::setMaxLocals(unsigned short *maxLocals) {
    CodeAttribute::maxLocals = maxLocals;
}

unsigned int *CodeAttribute::getCodeLength() const {
    return codeLength;
}

void CodeAttribute::setCodeLength(unsigned int *codeLength) {
    CodeAttribute::codeLength = codeLength;
}

char **CodeAttribute::getCode() const {
    return code;
}

void CodeAttribute::setCode(char **code) {
    CodeAttribute::code = code;
}

unsigned short *CodeAttribute::getExceptionTableLength() const {
    return exceptionTableLength;
}

void CodeAttribute::setExceptionTableLength(unsigned short *exceptionTableLength) {
    CodeAttribute::exceptionTableLength = exceptionTableLength;
}

CodeAttributeException **CodeAttribute::getExceptionTable() const {
    return exceptionTable;
}

void CodeAttribute::setExceptionTable(CodeAttributeException **exceptionTable) {
    CodeAttribute::exceptionTable = exceptionTable;
}

unsigned short *CodeAttribute::getAttributesCount() const {
    return attributesCount;
}

void CodeAttribute::setAttributesCount(unsigned short *attributesCount) {
    CodeAttribute::attributesCount = attributesCount;
}

AttributeInfo **CodeAttribute::getAttributes() const {
    return attributes;
}

void CodeAttribute::setAttributes(AttributeInfo **attributes) {
    CodeAttribute::attributes = attributes;
}


