//
// Created by zbh on 2021/6/8.
//

#ifndef CLASSFILEPARSER_ATTRIBUTEINFO_H
#define CLASSFILEPARSER_ATTRIBUTEINFO_H


class AttributeInfo {
public:
    //region attribute
    const char *CONSTANT_VALUE = "ConstantValue\0";

    const char *CODE = "Code";

    const char *LINE_NUMBER_TABLE = "LineNumberTable";

    const char *LOCAL_VARIABLE_TABLE = "LocalVariableTable";

    const char *EXCEPTIONS = "Exceptions";

    const char *SOURCE_FILE = "SourceFile";
    //endregion

private:
    unsigned short *attributeNameIndex; //u2
    unsigned int *attributeLength;  //u4
public:
    unsigned short *getAttributeNameIndex() const;

    void setAttributeNameIndex(unsigned short *attributeNameIndex);

    unsigned int *getAttributeLength() const;

    void setAttributeLength(unsigned int *attributeLength);


};


#endif //CLASSFILEPARSER_ATTRIBUTEINFO_H
