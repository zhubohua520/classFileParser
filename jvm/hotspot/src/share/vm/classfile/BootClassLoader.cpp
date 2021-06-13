//
// Created by zbh on 2021/6/7.
//

#include "BootClassLoader.h"
#include "ClassFileParser.h"
#include <fstream>

InstanceKlass BootClassLoader::loadClass(char *path) {
    char *p_absolute_path = buildAbsolutePath(path);
    printf("class路径为%s\n", p_absolute_path);

    ifstream in;
    InstanceKlass *p_instance_klass;
    in.open(p_absolute_path);
    if (in.is_open()) {
        ClassFileParser::parseClassFile(&in);


    }

    in.close();

//    map<char *, InstanceKlass>::iterator p_it;

//    p_it = class_loader_data.find(path);
//
//    if (p_it == class_loader_data.end()) {
//
//        buildAbsolutePath(path);
//
//        InstanceKlass instance_klass = InstanceKlass();
//
//        //TODO
//        return instance_klass;
//    } else {
//        return p_it->second;
//    }

    free(p_absolute_path);
    return *p_instance_klass;

}

char *BootClassLoader::buildAbsolutePath(char *path) {


    const char *p_prefix = "/Users/zbh/test/java/zbh-jvm/target/classes/";
    const char *p_suffix = ".class";

    char *p_path = (char *) malloc(strlen(path) + 1);
    strcpy(p_path, path);

    char *temp = p_path;

    while (*temp++ != '\0') {

        if (*temp == '.') {
            *temp = '/';
        }
    }


    char *result = (char *) malloc(strlen(p_prefix) + strlen(p_path) + strlen(p_suffix) + 1);

    strcpy(result, p_prefix);
    strcat(result, p_path);
    strcat(result, p_suffix);


    free(p_path);


    return result;
}



