//
// Created by zbh on 2021/6/7.
//

#ifndef CLASSFILEPARSER_BOOTCLASSLOADER_H
#define CLASSFILEPARSER_BOOTCLASSLOADER_H

#include <string>
#include <map>
#include "../oops/InstanceKlass.h"

using namespace std;


class BootClassLoader {
private:
//    static int a;
    static map<char *, InstanceKlass> class_loader_data;


private:
    static char *buildAbsolutePath(char *path);

public:

    static InstanceKlass loadClass(char *path);

};

//int BootClassLoader::a = 10;
//map<char *, InstanceKlass> BootClassLoader::class_loader_data = map<char *, InstanceKlass>();

#endif //CLASSFILEPARSER_BOOTCLASSLOADER_H
