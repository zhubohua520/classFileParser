//
// Created by zbh on 2021/6/14.
//

#ifndef CLASSFILEPARSER_CODEATTRIBUTE_H
#define CLASSFILEPARSER_CODEATTRIBUTE_H


#include "AttributeInfo.h"
#include "CodeAttributeException.h"

class CodeAttribute : public AttributeInfo {

private:
    unsigned short *maxStack; //u2

    unsigned short *maxLocals; //u2

    unsigned int *codeLength; //u4

    char **code; //大小为codeLength

    unsigned short *exceptionTableLength; //u2

    CodeAttributeException **exceptionTable;

    unsigned short *attributesCount;

    AttributeInfo **attributes;

public:
    unsigned short *getMaxStack() const;

    void setMaxStack(unsigned short *maxStack);

    unsigned short *getMaxLocals() const;

    void setMaxLocals(unsigned short *maxLocals);

    unsigned int *getCodeLength() const;

    void setCodeLength(unsigned int *codeLength);

    char **getCode() const;

    void setCode(char **code);

    unsigned short *getExceptionTableLength() const;

    void setExceptionTableLength(unsigned short *exceptionTableLength);

    CodeAttributeException **getExceptionTable() const;

    void setExceptionTable(CodeAttributeException **exceptionTable);

    unsigned short *getAttributesCount() const;

    void setAttributesCount(unsigned short *attributesCount);

    AttributeInfo **getAttributes() const;

    void setAttributes(AttributeInfo **attributes);


};

#endif //CLASSFILEPARSER_CODEATTRIBUTE_H
