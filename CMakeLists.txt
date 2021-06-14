cmake_minimum_required(VERSION 3.19)
project(classFileParser)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_BUILD_TYPE Debug)

add_executable(classFileParser main.cpp jvm/hotspot/src/share/vm/classfile/BootClassLoader.cpp jvm/hotspot/src/share/vm/classfile/BootClassLoader.h jvm/hotspot/src/share/vm/oops/InstanceKlass.cpp jvm/hotspot/src/share/vm/oops/InstanceKlass.h jvm/hotspot/src/share/vm/oops/Klass.cpp jvm/hotspot/src/share/vm/oops/Klass.h jvm/hotspot/src/share/vm/oops/ConstantPool.cpp jvm/hotspot/src/share/vm/oops/ConstantPool.h jvm/hotspot/src/share/vm/oops/InterfaceInfo.cpp jvm/hotspot/src/share/vm/oops/InterfaceInfo.h jvm/hotspot/src/share/vm/oops/FieldInfo.cpp jvm/hotspot/src/share/vm/oops/FieldInfo.h jvm/hotspot/src/share/vm/oops/Method.cpp jvm/hotspot/src/share/vm/oops/Method.h jvm/hotspot/src/share/vm/oops/AttributeInfo.cpp jvm/hotspot/src/share/vm/oops/AttributeInfo.h jvm/hotspot/src/share/vm/classfile/ClassFileParser.cpp jvm/hotspot/src/share/vm/classfile/ClassFileParser.h jvm/hotspot/src/share/tools/Converter.cpp jvm/hotspot/src/share/tools/Converter.h jvm/hotspot/src/share/vm/oops/ConstantValueAttribute.cpp jvm/hotspot/src/share/vm/oops/ConstantValueAttribute.h jvm/hotspot/src/share/vm/oops/CodeAttribute.cpp jvm/hotspot/src/share/vm/oops/CodeAttribute.h jvm/hotspot/src/share/vm/oops/CodeAttributeException.cpp jvm/hotspot/src/share/vm/oops/CodeAttributeException.h jvm/hotspot/src/share/vm/oops/LineNumberTableAttribute.cpp jvm/hotspot/src/share/vm/oops/LineNumberTableAttribute.h)

