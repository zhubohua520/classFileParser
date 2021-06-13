#include <iostream>
#include <fstream>
#include <string>
#include <fstream>
#include "jvm/hotspot/src/share/vm/classfile/BootClassLoader.h"

using namespace std;


int main() {

//
//    long c = 2;
//    printf("%d\n", sizeof(c));
//    printf("%d\n", sizeof(&c));

    char *path = "com.zbh.jvm.example.HelloWorld";

    BootClassLoader::loadClass(path);





//    std::ofstream out(absolute_path);


    return 0;
}



