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

void InstanceKlass::setConstantPool(ConstantPool *constant_pool) {
    this->constant_pool = constant_pool;
}

ConstantPool *InstanceKlass::getConstantPool() {
    return constant_pool;
}

void InstanceKlass::setAccessFlags(const char *c) {


    this->access_flags = (unsigned short *) c;
    Converter::little2BigSwap2(access_flags);
}

unsigned short InstanceKlass::getAccessFlags() {
    return *access_flags;
}

unsigned short InstanceKlass::getThisClass() {
    return *this_class;
}

void InstanceKlass::setThisClass(const char *thisClass) {
    this->this_class = (unsigned short *) thisClass;
    Converter::little2BigSwap2(this_class);
}

unsigned short InstanceKlass::getSuperClass() {
    return *super_class;
}

void InstanceKlass::setSuperClass(const char *c) {
    super_class = (unsigned short *) c;
    Converter::little2BigSwap2(super_class);
}

unsigned short InstanceKlass::getInterfacesCount() {
    return *interfaces_count;
}

void InstanceKlass::setInterfacesCount(const char *c) {
    interfaces_count = (unsigned short *) c;
    Converter::little2BigSwap2(super_class);
}

unsigned short InstanceKlass::getFieldsCount() {
    return *fields_count;
}

void InstanceKlass::setFieldsCount(const char *c) {
    fields_count = (unsigned short *) c;
    Converter::little2BigSwap2(fields_count);
}

unsigned short InstanceKlass::getMethodCount() {
    return *method_count;
}

void InstanceKlass::setMethodCount(const char *c) {
    method_count = (unsigned short *) c;
    Converter::little2BigSwap2(method_count);
}

unsigned short InstanceKlass::getAttributesCount() const {
    return attributes_count;
}

void InstanceKlass::setAttributesCount(unsigned short attributesCount) {
    attributes_count = attributesCount;
}

char **InstanceKlass::getMethods() const {
    return methods;
}

void InstanceKlass::setMethods(char **methods) {
    InstanceKlass::methods = methods;
}











