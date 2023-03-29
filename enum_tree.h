//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Mon Mar 27 14:28:51 2023 by ROOT version 6.26/10
// from TTree enum_tree/test tree for enum structures
// found on file: enum_test.root
//////////////////////////////////////////////////////////

#ifndef enum_tree_h
#define enum_tree_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>
#include <TTreeReader.h>
#include <TTreeReaderValue.h>
#include <TTreeReaderArray.h>


#include <TRandom3.h>
#include <TROOT.h>
#include <TTree.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>
#include <TTreeReader.h>
#include <TTreeReaderValue.h>
#include <TTreeReaderArray.h>
#include <TF1.h>
#include <TVector3.h>

// Headers needed by this particular selector
#include "enum.hh"



class enum_tree : public TSelector {
public :
   TTreeReader     fReader;  //!the tree reader
   TTree          *fChain = 0;   //!pointer to the analyzed TTree or TChain

   // Readers to access the data (delete the ones you do not need).
   TTreeReaderValue<testStruct_t> test_struct = {fReader, "test_struct"};
   TTreeReaderArray<int> test_foo = {fReader, "test_struct.foo"};
   // TTreeReaderArray<someEnum> vector_enum_someEnum = {fReader, "vector_enum"};
   TTreeReaderArray<someEnum> test_someEnum = {fReader, "test_struct.e1"};
   TTreeReaderArray<anotherEnum> test_anotherEnum = {fReader, "test_struct.e2"};

   // enum_tree() {};
   enum_tree(TTree * /*tree*/ =0) :TSelector() { };
   virtual ~enum_tree()  { }
   virtual Int_t   Version() const  { return 2; }
   virtual void    Begin(TTree *tree) ;
   virtual void    SlaveBegin(TTree *tree) ;
   virtual void    Init(TTree *tree) ;
   virtual Bool_t  Notify() ;
   virtual Bool_t  Process(Long64_t entry) ;
   virtual Int_t   GetEntry(Long64_t entry, Int_t getall = 0) { return fChain ? fChain->GetTree()->GetEntry(entry, getall) : 0; }
   virtual void    SetOption(const char *option) { fOption = option; }
   virtual void    SetObject(TObject *obj) { fObject = obj; }
   virtual void    SetInputList(TList *input) { fInput = input; }
   virtual TList  *GetOutputList() const { return fOutput; }
   virtual void    SlaveTerminate();
   virtual void    Terminate();

   ClassDef(enum_tree,1);

};

// #endif

// #ifdef enum_tree_cxx
void enum_tree::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the reader is initialized.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   fReader.SetTree(tree);
}

Bool_t enum_tree::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}


#endif // #ifdef enum_tree_cxx
