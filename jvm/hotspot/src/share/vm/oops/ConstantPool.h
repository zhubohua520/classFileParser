//
// Created by zbh on 2021/6/8.
//

#ifndef CLASSFILEPARSER_CONSTANTPOOL_H
#define CLASSFILEPARSER_CONSTANTPOOL_H

#include <map>


static const int JVM_CONSTANT_Class = 7;

class ConstantPool {
public:
    static const int JVM_CONSTANT_Utf8 = 1;
    static const int JVM_CONSTANT_Unicode = 2;   /* unused */
    static const int JVM_CONSTANT_Integer = 3;
    static const int JVM_CONSTANT_Float = 4;
    static const int JVM_CONSTANT_Long = 5;
    static const int JVM_CONSTANT_Double = 6;
    static const int JVM_CONSTANT_Class = 7;
    static const int JVM_CONSTANT_String = 8;
    static const int JVM_CONSTANT_Fieldref = 9;
    static const int JVM_CONSTANT_Methodref = 10;
    static const int JVM_CONSTANT_InterfaceMethodref = 11;
    static const int JVM_CONSTANT_NameAndType = 12;
    static const int JVM_CONSTANT_MethodHandle = 15; /* JSR 292 */
    static const int JVM_CONSTANT_MethodType = 16;   /* JSR 292 */
    static const int JVM_CONSTANT_InvokeDynamic = 18;    /* JSR 292 */
    static const int JVM_CONSTANT_ExternalMax = 18;  /* Last tag found in classfiles */



public:
    ConstantPool();

    ConstantPool(int capacity);

public:
    void setTag(int key, int *p_tag);

    void put(int index, char **p);

    char **get(int index);

    unsigned short *getClassIndex(int index);

    unsigned short *getNameAndTypeIndex(int index);

    unsigned short *getStringIndex(int index);

    unsigned short *getClassInfoIndex(int index);

    unsigned short *getNameIndex(int index);

    unsigned short *getDescriptorIndex(int index);

    char *getUtf8Info(int index);

private:
    char **p_key;
//    unsigned long *p_value;
    int *p_tag;

    unsigned short *getShort(int index);

    unsigned short *getNextShort(int index);

};


#endif //CLASSFILEPARSER_CONSTANTPOOL_H
