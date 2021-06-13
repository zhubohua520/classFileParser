//
// Created by zbh on 2021/6/8.
//

#include "ConstantPool.h"

ConstantPool::ConstantPool() {

}

ConstantPool::ConstantPool(int capacity) {
    p_key = (unsigned short *) malloc(capacity);
    p_value = (unsigned long *) malloc(capacity);
    p_tag = (unsigned char *) malloc(capacity);

}

void ConstantPool::setTag(int key, unsigned char *p_tag) {
    *(this->p_tag + key) = *p_tag;
}
