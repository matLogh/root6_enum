#ifndef ENUM_HH
#define ENUM_HH

#include "TObject.h"

enum someEnum : unsigned int
{
    kS1 = (1u << 0),
    kS2 = (1u << 1),
    kS3 = (1u << 2),
    kS4 = (1u << 3)
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