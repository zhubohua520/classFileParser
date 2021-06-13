//
// Created by zbh on 2021/6/10.
//

#include "Converter.h"

char *Converter::toUnsignedChar(char *c, int capacity) {

    int i = 0;
    while (i < capacity) {
        char temp = *c++;
        i++;
    }
    //TODO 没有写完

    return c;
}

//小端转大端
int Converter::little2Big(int *le) {
    return *le << 24
           | (*le & 0xFF00) << 8
           | (*le & 0xFF0000) >> 8
           | *le >> 24;
}


int Converter::big2Little(int *be) {

    return *be >> 24 | (*be & 0xFF0000) >> 8 | (*be & 0xFF00) << 8 | *be << 24;

}

int *Converter::little2BigSwap(int *le) {
    char *c = (char *) le;

    char temp = *c;
    *c = *(c + 3);
    *(c + 3) = temp;

    temp = *(c + 1);
    *(c + 1) = *(c + 2);
    *(c + 2) = temp;


    return le;
}

unsigned short * Converter::little2BigSwap2(unsigned short *le) {
    char *c = (char *) le;

    char temp = *c;
    *c = *(c + 1);
    *(c + 1) = temp;


    return le;
}


