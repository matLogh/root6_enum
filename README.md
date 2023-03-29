# root6_enum
Issue with TTreeReaderArray&lt;some_enum_type> 

Minimal working example for the enum type loading issue using the TreeReaderArray in TSelector. I am using ROOT 6.26/10

To run:
```
git clone https://github.com/matLogh/root6_enum.git
mkdir root6_enum/build
cd root6_enum/build
cmake ../
make 

./enumgenerate
./enumselector
```

The error I am getting:
```
Error in <TTreeReaderArrayBase::CreateProxy()>: The template argument type T of T accessing branch test_struct.e1 (which contains data of type Int_t) is not known to ROOT. You will need to create a dictionary for it.
```
