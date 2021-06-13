//
// Created by zbh on 2021/6/9.
//

#include "ClassFileParser.h"
#include <fstream>


InstanceKlass *ClassFileParser::parseClassFile(ifstream *p_in) {


    InstanceKlass *instanceKlass = new InstanceKlass();
    char *p_magic = readBytes(p_in, 4);
    instanceKlass->setMagic(p_magic);
    char *p_version = readBytes(p_in, 4);
    instanceKlass->setVersion(p_version);
    printf("副版本号：%d\n", instanceKlass->getMinorVersion());
    printf("主版本号：%d\n", instanceKlass->getMajorVersion());

    char *p_constant_pool_count = readBytes(p_in, 2);
    instanceKlass->setConstantPoolCount(p_constant_pool_count);
    printf("常量池长度：%d\n", instanceKlass->getConstantPoolCount());
    ClassFileParser::parseConstantPool(p_in, instanceKlass);

    return instanceKlass;
}

char *ClassFileParser::readBytes(ifstream *p_in, unsigned int capacity) {

    char *c2 = (char *) malloc(capacity);
//    char c[capacity];
    if (!p_in->eof()) {

        p_in->get(c2, capacity + 1);

    }
//
//    unsigned char c1 = c[0];
//    c[0] = (unsigned char) c[0];
//
//    printf("%x\n", c1);
//    printf("%x\n", c[0]);

    return c2;
}

char *ClassFileParser::readByte(ifstream *p_in) {
    return readBytes(p_in, 1);
}

void ClassFileParser::parseConstantPool(ifstream *p_in, InstanceKlass *instanceKlass) {
    printf("开始解析常量池\n");

    short count = instanceKlass->getConstantPoolCount();

//    int i = ConstantPool::JVM_CONSTANT_Class;
    ConstantPool *p_constantPool = new ConstantPool(count);
    int i = 1;
    while (i < count) {
        char *c = readByte(p_in);
        unsigned char *p_tag = (unsigned char *) c;
        p_constantPool->setTag(i, p_tag);
        switch (p_tag) {
            
        }


        i++;
    }

}


