//
// Created by zbh on 2021/6/9.
//

#include "ClassFileParser.h"
#include "../../tools/Converter.h"
#include "../oops/ConstantValueAttribute.h"
#include "../oops/CodeAttribute.h"
#include "../oops/LineNumberTableAttribute.h"
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

    char *p_access_flags = readBytes(p_in, 2);
    instanceKlass->setAccessFlags(p_access_flags);
    printf("类的访问控制权限：%d\n", instanceKlass->getAccessFlags());

    char *p_this_class = readBytes(p_in, 2);
    instanceKlass->setThisClass(p_this_class);
    printf("类索引：%d\n", instanceKlass->getThisClass());

    char *p_super_class = readBytes(p_in, 2);
    instanceKlass->setSuperClass(p_super_class);
    printf("父类索引：%d\n", instanceKlass->getSuperClass());

    char *p_interface_count = readBytes(p_in, 2);
    instanceKlass->setInterfacesCount(p_interface_count);
    printf("接口长度：%d\n", instanceKlass->getInterfacesCount());

    ClassFileParser::parseInterface(p_in, instanceKlass);

    char *p_fields_count = readBytes(p_in, 2);
    instanceKlass->setFieldsCount(p_fields_count);
    printf("字段长度：%d\n", instanceKlass->getFieldsCount());

    ClassFileParser::parseFieldsInfo(p_in, instanceKlass);

    char *p_method_count = readBytes(p_in, 2);
    instanceKlass->setMethodCount(p_method_count);
    printf("方法长度：%d\n", instanceKlass->getMethodCount());

    ClassFileParser::parseMethodInfo(p_in, instanceKlass);


    return instanceKlass;
}


void ClassFileParser::parseConstantPool(ifstream *p_in, InstanceKlass *instanceKlass) {
    printf("开始解析常量池\n");

    short count = instanceKlass->getConstantPoolCount();

    if (count < 0) {
        return;
    }

//    int i = ConstantPool::JVM_CONSTANT_Class;
    ConstantPool *p_constantPool = new ConstantPool(count);
    int i = 1;
    while (i < count) {


        int *p_tag = readByteToInt(p_in);

        switch (*p_tag) {
            case ConstantPool::JVM_CONSTANT_Methodref: {
                char *p_class_index = readBytes(p_in, 2);
                char *p_name_and_type_index = readBytes(p_in, 2);

                unsigned short *p_class_index_short = (unsigned short *) p_class_index;
                Converter::little2BigSwap2(p_class_index_short);
                unsigned short *p_name_and_type_index_short = (unsigned short *) p_name_and_type_index;
                Converter::little2BigSwap2(p_name_and_type_index_short);
                int *p_int = (int *) malloc(4);
                *p_int = *p_class_index_short;
                *(((unsigned short *) p_int) + 1) = *p_name_and_type_index_short;

                p_constantPool->put(i, (char **) &p_int);

                unsigned short *classIndex = p_constantPool->getClassIndex(i);
                unsigned short *nameAndTypeIndex = p_constantPool->getNameAndTypeIndex(i);

                printf("解析第%d个:%s,值:%u,%u\n", i, "JVM_CONSTANT_Methodref", *classIndex, *nameAndTypeIndex);

                break;
            }
            case ConstantPool::JVM_CONSTANT_Fieldref: {
                char *p_class_index = readBytes(p_in, 2);
                char *p_name_and_type_index = readBytes(p_in, 2);

                unsigned short *p_class_index_short = (unsigned short *) p_class_index;
                Converter::little2BigSwap2(p_class_index_short);
                unsigned short *p_name_and_type_index_short = (unsigned short *) p_name_and_type_index;
                Converter::little2BigSwap2(p_name_and_type_index_short);
                int *p_int = (int *) malloc(4);
                *p_int = *p_class_index_short;
                *(((unsigned short *) p_int) + 1) = *p_name_and_type_index_short;

                p_constantPool->put(i, (char **) &p_int);

                unsigned short *classIndex = p_constantPool->getClassIndex(i);
                unsigned short *nameAndTypeIndex = p_constantPool->getNameAndTypeIndex(i);

                printf("解析第%d个:%s,值:%u,%u\n", i, "JVM_CONSTANT_Fieldref", *classIndex, *nameAndTypeIndex);

                break;
            }
            case ConstantPool::JVM_CONSTANT_String: {
                char *p_string_index = readBytes(p_in, 2);

                unsigned short *p_string_index_short = (unsigned short *) p_string_index;
                Converter::little2BigSwap2(p_string_index_short);

                short *p_short = (short *) malloc(2);
                *p_short = *p_string_index_short;


                p_constantPool->put(i, (char **) &p_short);

                unsigned short *stringIndex = p_constantPool->getStringIndex(i);

                printf("解析第%d个:%s,值:%u\n", i, "JVM_CONSTANT_String", *stringIndex);

                break;
            }
            case ConstantPool::JVM_CONSTANT_Class: {

                char *p_name_index = readBytes(p_in, 2);

                unsigned short *p_name_index_short = (unsigned short *) p_name_index;
                Converter::little2BigSwap2(p_name_index_short);

                short *p_short = (short *) malloc(2);
                *p_short = *p_name_index_short;


                p_constantPool->put(i, (char **) &p_short);

                unsigned short *classInfoIndex = p_constantPool->getClassInfoIndex(i);

                printf("解析第%d个:%s,值:%u\n", i, "JVM_CONSTANT_Class", *classInfoIndex);

                break;
            }
            case ConstantPool::JVM_CONSTANT_Utf8: {
                char *p_length = readBytes(p_in, 2);

                unsigned short *p_length_short = (unsigned short *) p_length;
                Converter::little2BigSwap2(p_length_short);
                char *p_content = readBytesToString(p_in, *p_length_short);


                p_constantPool->put(i, (char **) &p_content);

                char *content = p_constantPool->getUtf8Info(i);


                printf("解析第%d个:%s,值:%s\n", i, "JVM_CONSTANT_Utf8", content);

                break;

            }
            case ConstantPool::JVM_CONSTANT_NameAndType: {
                char *p_name_index = readBytes(p_in, 2);
                char *p_descriptor_index = readBytes(p_in, 2);

                unsigned short *p_name_index_short = (unsigned short *) p_name_index;
                Converter::little2BigSwap2(p_name_index_short);
                unsigned short *p_descriptor_index_short = (unsigned short *) p_descriptor_index;
                Converter::little2BigSwap2(p_descriptor_index_short);
                int *p_int = (int *) malloc(4);
                *p_int = *p_name_index_short;
                *(((unsigned short *) p_int) + 1) = *p_descriptor_index_short;

                p_constantPool->put(i, (char **) &p_int);

                unsigned short *nameIndex = p_constantPool->getNameIndex(i);
                unsigned short *descriptorIndex = p_constantPool->getDescriptorIndex(i);

                printf("解析第%d个:%s,值:%u,%u\n", i, "JVM_CONSTANT_NameAndType", *nameIndex, *descriptorIndex);

                break;
            }
            default:
                throw runtime_error("未知的常量池类型");
        }
        i++;
    }
    instanceKlass->setConstantPool(p_constantPool);
    printf("常量池解析完毕\n");

}

void ClassFileParser::parseInterface(ifstream *p_in, InstanceKlass *instance_klass) {

    unsigned short count = instance_klass->getInterfacesCount();
    if (count <= 0) {
        return;
    }
}

void ClassFileParser::parseFieldsInfo(ifstream *p_in, InstanceKlass *instance_klass) {
    unsigned short count = instance_klass->getFieldsCount();
    if (count <= 0) {
        return;
    }
}

void ClassFileParser::parseMethodInfo(ifstream *p_in, InstanceKlass *instance_klass) {
    unsigned short count = instance_klass->getMethodCount();
    if (count <= 0) {
        return;
    }

    instance_klass->setMethods(
            (char **) malloc(sizeof(count * sizeof(instance_klass->getMethods()))));

    for (int i = 0; i < count; ++i) {
        unsigned short *p_access_flags = readBytesToUnsignedShort(p_in, 2);

        unsigned short *p_name_index = readBytesToUnsignedShort(p_in, 2);

        unsigned short *p_descriptor_flags = readBytesToUnsignedShort(p_in, 2);

        unsigned short *p_attributes_count = readBytesToUnsignedShort(p_in, 2);

        Method *method = new Method(p_attributes_count);
        method->setAccessFlags(p_attributes_count);
        method->setNameIndex(p_name_index);
        method->setDescriptorIndex(p_descriptor_flags);
        method->setAttributesCount(p_attributes_count);
        method->setPBelongKlass((char **) &instance_klass);


        if (*p_attributes_count > 0) {

        }
    }


}


char *ClassFileParser::readBytes(ifstream *p_in, size_t capacity) {

    char *c2 = (char *) malloc(capacity);

    if (!p_in->eof()) {
        p_in->read(c2, capacity);


    }


    return c2;
}

char *ClassFileParser::readByte(ifstream *p_in) {
    return readBytes(p_in, 1);
}

int *ClassFileParser::readByteToInt(ifstream *p_in) {

    char *c = readBytes(p_in, 1);

    int *i = (int *) malloc(4);

    char *temp = (char *) i;

    *(temp) = *c;

    free(c);

    return i;
}

unsigned int *ClassFileParser::readBytesToUnsignedInt(ifstream *p_in, size_t capacity) {

    char *c = readBytes(p_in, capacity);

    int *result = (int *) malloc(4);

    int *temp = (int *) c;

    Converter::little2BigSwap(temp);

    int i = 0;
    char *dest = (char *) result;
    char *src = (char *) temp;
    while (i++ < 4) {
        *dest++ = *src++;
    }


    free(c);

    return (unsigned int *) result;
}

short *ClassFileParser::readBytesToShort(ifstream *p_in, size_t capacity) {

    char *c = readBytes(p_in, capacity);

    short *s = (short *) malloc(2);

    int i = 0;
    char *src = (char *) c;
    char *dst = (char *) s;
    while (i++ < 2) {

        *dst++ = *src++;
    }

    dst = (char *) s;
    char temp = *dst;

    *dst = *(dst + 1);
    *(dst + 1) = temp;

    free(c);
    return s;
}

unsigned short *ClassFileParser::readBytesToUnsignedShort(ifstream *p_in, size_t capacity) {

    short *s = readBytesToShort(p_in, capacity);
    unsigned short *result = (unsigned short *) s;
    return result;
}


char *ClassFileParser::readBytesToString(ifstream *p_in, size_t capacity) {

    char *c = readBytes(p_in, capacity);

    char *str = (char *) malloc(capacity + 1);


    char *src = c;
    char *dst = str;

    int i = 0;
    while (i < capacity) {
        *dst++ = *src++;

        i++;
    }

    *dst = '\0';

    free(c);

    return str;
}

AttributeInfo ** ClassFileParser::parseAttributeInfo(ifstream *p_in, ConstantPool *constant_pool) {

    unsigned short *p_attribute_name_index = readBytesToUnsignedShort(p_in, 2);

    char *attribute_str = constant_pool->getUtf8Info(*p_attribute_name_index);
    AttributeInfo *p_base_attribute;
    if (attribute_str == "ConstantValue") {
        p_base_attribute = new ConstantValueAttribute();
        ConstantValueAttribute *attribute = (ConstantValueAttribute *) p_base_attribute;
        attribute->setAttributeNameIndex(p_attribute_name_index);

        unsigned int *p_attribute_length = readBytesToUnsignedInt(p_in, 4);

        attribute->setAttributeLength(p_attribute_length);

        unsigned short *p_constant_value_index = readBytesToUnsignedShort(p_in, 2);

        attribute->setConstantValueIndex(p_constant_value_index);

    } else if (attribute_str == "Code") {
        p_base_attribute = new CodeAttribute();
        CodeAttribute *attribute = (CodeAttribute *) p_base_attribute;
        attribute->setAttributeNameIndex(p_attribute_name_index);
        attribute->setAttributeLength(readBytesToUnsignedInt(p_in, 4));
        attribute->setMaxStack(readBytesToUnsignedShort(p_in, 2));
        attribute->setMaxLocals(readBytesToUnsignedShort(p_in, 2));
        attribute->setCodeLength(readBytesToUnsignedInt(p_in, 4));
        char *content = readBytes(p_in, *attribute->getCodeLength());
        attribute->setCode(&content);


        attribute->setExceptionTableLength(readBytesToUnsignedShort(p_in, 2));

        if (*attribute->getExceptionTableLength() > 0) {

            CodeAttributeException **tables = (CodeAttributeException **) malloc(
                    *attribute->getExceptionTableLength() * sizeof(CodeAttributeException));

            int i = 0;
            CodeAttributeException *temp = *tables;
            while (i++ < *attribute->getExceptionTableLength()) {
                CodeAttributeException *codeException = new CodeAttributeException();
                codeException->setStartPc(readBytesToUnsignedShort(p_in, 2));
                codeException->setEndPc(readBytesToUnsignedShort(p_in, 2));
                codeException->setHandlePc(readBytesToUnsignedShort(p_in, 2));
                codeException->setCatchType(readBytesToUnsignedShort(p_in, 2));
                *temp++ = *codeException;

            }

            attribute->setExceptionTable(tables);

        }


        attribute->setAttributesCount(readBytesToUnsignedShort(p_in, 2));

        if (*attribute->getAttributesCount() > 0) {
            AttributeInfo **attributeInfos = (AttributeInfo **) malloc(
                    *attribute->getAttributesCount() * sizeof(attribute->getAttributes()));

            int i = 0;
            AttributeInfo **temp = attributeInfos;
            while (i++ < *attribute->getAttributesCount()) {
                AttributeInfo **p_attribute = parseAttributeInfo(p_in, constant_pool);
                *temp++ = *p_attribute;
            }


            attribute->setAttributes(attributeInfos);
        }
    } else if (attribute_str == "LineNumberTable") {

        LineNumberTableAttribute::LineNumber* lineNumber=new LineNumberTableAttribute::LineNumber();
    } else if (attribute_str == "LocalVariableTable") {

    } else {
        throw runtime_error("未解析的参数类型");
    }


}













