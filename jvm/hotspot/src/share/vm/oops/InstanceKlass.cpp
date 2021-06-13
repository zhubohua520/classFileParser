//
// Created by zbh on 2021/6/7.
//


#include "InstanceKlass.h"
#include "../../tools/Converter.h"

char *InstanceKlass::getMagic() {

    char *c_magic = (char *) magic;

    return c_magic;
}

void InstanceKlass::setMagic(const char *c) {

    magic = (int *) c;

    Converter::little2BigSwap(magic);
}

void InstanceKlass::setVersion(const char *c) {

    version = (int *) c;

    version = Converter::little2BigSwap(version);
}

unsigned short InstanceKlass::getMinorVersion() {

    unsigned short s = *version >> 8;

    return s;
}

unsigned short InstanceKlass::getMajorVersion() {

    unsigned short s = *version & 0xffff;

    return s;
}

void InstanceKlass::setConstantPoolCount(const char *c) {
    constant_pool_count = (unsigned short *) c;

    constant_pool_count = Converter::little2BigSwap2(constant_pool_count);
}

unsigned short InstanceKlass::getConstantPoolCount() {
    return *constant_pool_count;
}







