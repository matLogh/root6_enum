#ifndef ENUM_HH
#define ENUM_HH

#include "TObject.h"

enum someEnum : unsigned int
{
    kS1,
    kS2,
    kS3,
    kS4
};

enum anotherEnum : unsigned int
{
    kA1,
    kA2,
    kA3,
    kA4
};

struct testStruct_t
{
    int foo;
    someEnum e1;
    anotherEnum e2;

    ClassDef(testStruct_t, 1);
};

#endif