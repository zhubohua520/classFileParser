//
// Created by zbh on 2021/6/14.
//

#ifndef CLASSFILEPARSER_CONSTANTVALUEATTRIBUTE_H
#define CLASSFILEPARSER_CONSTANTVALUEATTRIBUTE_H


#include "AttributeInfo.h"

class ConstantValueAttribute : public AttributeInfo {

private:
    unsigned short *constantValueIndex;
public:
    unsigned short *getConstantValueIndex() const;

    void setConstantValueIndex(unsigned short *constantValueIndex);
};


#endif //CLASSFILEPARSER_CONSTANTVALUEATTRIBUTE_H
