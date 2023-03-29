#include "enum.hh"

#include "TTree.h"
#include "TFile.h"

#include <vector>

int main()
{
    testStruct_t test_struct;
    std::vector<someEnum> vector_enum; 

    TFile file("enum_test.root","RECREATE");
    TTree tree("enum_tree","test tree for enum structures");
    tree.Branch("test_struct",&test_struct);
    tree.Branch("vector_enum",&vector_enum);

    vector_enum.push_back(kS1);
    test_struct.foo = 1;
    test_struct.e1 = kS1;
    test_struct.e2 = kA1;
    tree.Fill();
    vector_enum.push_back(kS2);
    test_struct.foo = 2;
    test_struct.e1 = kS2;
    test_struct.e2 = kA2;
    tree.Fill();
    vector_enum.push_back(kS3);
    test_struct.foo = 3;
    test_struct.e1 = kS2;
    test_struct.e2 = kA3;
    tree.Fill();
    vector_enum.push_back(kS4);
    test_struct.foo = 4;
    test_struct.e1 = kS3;
    test_struct.e2 = kA3;
    tree.Fill();

    file.cd();
    tree.Write();
    file.Close();
    return 0;
}
