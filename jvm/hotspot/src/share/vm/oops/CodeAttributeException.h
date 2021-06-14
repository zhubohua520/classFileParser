//
// Created by zbh on 2021/6/14.
//

#ifndef CLASSFILEPARSER_CODEATTRIBUTEEXCEPTION_H
#define CLASSFILEPARSER_CODEATTRIBUTEEXCEPTION_H


class CodeAttributeException {
private:
    unsigned short *startPc; //u2

    unsigned short *endPc;  //u2

    unsigned short *handlePc;  //u2

    unsigned short *catchType;
public:
    unsigned short *getStartPc() const;

    void setStartPc(unsigned short *startPc);

    unsigned short *getEndPc() const;

    void setEndPc(unsigned short *endPc);

    unsigned short *getHandlePc() const;

    void setHandlePc(unsigned short *handlePc);

    unsigned short *getCatchType() const;

    void setCatchType(unsigned short *catchType);
    //u2


};


#endif //CLASSFILEPARSER_CODEATTRIBUTEEXCEPTION_H
