#include "enum.hh"
#include "enum_tree.h"
#include "TTree.h"
#include "TFile.h"

int main()
{
    testStruct_t test_struct;

    enum_tree selector(0);


    TFile file("enum_test.root","read");
    TTree* tree = (TTree*)file.Get("enum_tree");
    tree->Process(&selector);
    return 0;
}
