//
// Created by zbh on 2021/6/14.
//

#include "ConstantValueAttribute.h"

unsigned short *ConstantValueAttribute::getConstantValueIndex() const {
    return constantValueIndex;
}

void ConstantValueAttribute::setConstantValueIndex(unsigned short *constantValueIndex) {
    ConstantValueAttribute::constantValueIndex = constantValueIndex;
}
