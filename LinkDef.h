#include <vector>
#include <list>
#include <TTreeReaderArray.h>
#ifdef __ROOTCLING__


#pragma link C++ nestedclass;
#pragma link C++ nestedtypedefs;

#pragma link C++ enum someEnum;
#pragma link C++ enum anotherEnum;
#pragma link C++ class testStruct_t+;
#pragma link C++ class std::vector<someEnum>++;
#pragma link C++ class std::vector<anotherEnum>++;
#pragma link C++ class testStruct_t::someEnum+;
#pragma link C++ class testStruct_t::anotherEnum+;

// #pragma link C++ class ROOT::Internal::TTreeReaderArray<someEnum>++;
// #pragma link C++ class ROOT::Internal::TTreeReaderArray<anotherEnum>++;

#endif