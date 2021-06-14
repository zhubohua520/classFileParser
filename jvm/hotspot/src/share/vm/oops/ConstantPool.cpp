//
// Created by zbh on 2021/6/8.
//

#include "ConstantPool.h"

ConstantPool::ConstantPool() {

}

ConstantPool::ConstantPool(int capacity) {

    p_key = (char **) malloc(capacity * sizeof(p_key));
//    p_value = (unsigned long *) malloc(capacity);
    p_tag = (int *) malloc(capacity);

}

void ConstantPool::setTag(int key, int *p_tag) {
    *(this->p_tag + key) = *p_tag;
}

void ConstantPool::put(int index, char **p) {

    *(this->p_key + index) = *p;

}

char **ConstantPool::get(int index) {
    char **p = (char **) (p_key + index);

    return p;

}

unsigned short *ConstantPool::getClassIndex(int index) {

    return getShort(index);

}

unsigned short *ConstantPool::getNameAndTypeIndex(int index) {
    return getNextShort(index);
}

unsigned short *ConstantPool::getStringIndex(int index) {


    return getShort(index);
}

unsigned short *ConstantPool::getClassInfoIndex(int index) {
    return getShort(index);
}

unsigned short *ConstantPool::getShort(int index) {
    char **p = get(index);

    unsigned short *result = (unsigned short *) *p;

    return result;
}

char *ConstantPool::getUtf8Info(int index) {

    char **p = get(index);
    return *p;
}

unsigned short *ConstantPool::getNameIndex(int index) {
    return getShort(index);
}

unsigned short *ConstantPool::getDescriptorIndex(int index) {


    return getNextShort(index);
}

unsigned short *ConstantPool::getNextShort(int index) {
    char **p = get(index);

    unsigned short *result = (unsigned short *) (*p + 2);

    return result;
}



