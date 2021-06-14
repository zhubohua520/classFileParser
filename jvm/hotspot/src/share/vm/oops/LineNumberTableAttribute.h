//
// Created by zbh on 2021/6/14.
//

#ifndef CLASSFILEPARSER_LINENUMBERTABLEATTRIBUTE_H
#define CLASSFILEPARSER_LINENUMBERTABLEATTRIBUTE_H


#include "AttributeInfo.h"

class LineNumberTableAttribute : public AttributeInfo {

public:
    class LineNumber {
        unsigned short startPc;
        unsigned short lineNumber;
    };

private:
    unsigned short *lineNumberTableLength;

    LineNumberTableAttribute::LineNumber **lineNumberTable;


};


#endif //CLASSFILEPARSER_LINENUMBERTABLEATTRIBUTE_H
