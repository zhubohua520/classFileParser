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

    long l = 2;
    long *p_l = &l;
    char c = 10;
    char *p_c = &c;

    char *path = "com.zbh.jvm.example.HelloWorld";

    try {
        BootClassLoader::loadClass(path);
    } catch (const std::exception &e){
        cout << e.what() << endl;
    }






//    std::ofstream out(absolute_path);


    return 0;
}



