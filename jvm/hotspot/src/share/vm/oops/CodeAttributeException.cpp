//
// Created by zbh on 2021/6/14.
//

#include "CodeAttributeException.h"

unsigned short *CodeAttributeException::getStartPc() const {
    return startPc;
}

void CodeAttributeException::setStartPc(unsigned short *startPc) {
    CodeAttributeException::startPc = startPc;
}

unsigned short *CodeAttributeException::getEndPc() const {
    return endPc;
}

void CodeAttributeException::setEndPc(unsigned short *endPc) {
    CodeAttributeException::endPc = endPc;
}

unsigned short *CodeAttributeException::getHandlePc() const {
    return handlePc;
}

void CodeAttributeException::setHandlePc(unsigned short *handlePc) {
    CodeAttributeException::handlePc = handlePc;
}

unsigned short *CodeAttributeException::getCatchType() const {
    return catchType;
}

void CodeAttributeException::setCatchType(unsigned short *catchType) {
    CodeAttributeException::catchType = catchType;
}
