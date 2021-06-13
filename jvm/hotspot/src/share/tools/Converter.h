//
// Created by zbh on 2021/6/10.
//

#ifndef CLASSFILEPARSER_CONVERTER_H
#define CLASSFILEPARSER_CONVERTER_H


class Converter {

public:
    static char *toUnsignedChar(char *c, int capacity);


    static int little2Big(int *le);

    static int big2Little(int *le);

    static int *little2BigSwap(int *le);

    static unsigned short * little2BigSwap2(unsigned short *le);
};


#endif //CLASSFILEPARSER_CONVERTER_H
