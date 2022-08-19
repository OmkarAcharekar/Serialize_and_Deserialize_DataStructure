#include "leb128.cpp"
#include <fstream>
#include <cstring>

class Data
{
    int32_t Int32;
    int64_t Int64;
    float Float;
    double Double;
    std::vector<uint8_t> U8Array;

    // serialize function : similar to std::vector<uint8_t> serialize(Data &D):
    friend std::ostream &operator<<(std::ostream &os, const Data &D)
    {
       
    }

    // deserialize function  : similar to Data deserialize(std::vector<uint8_t> &Bytes);
    friend std::istream &operator>>(std::istream &is, Data &l)
    {
        
    }
};

int main()
{

    Data h1;
    std::ofstream file("Data.bin");
    file << h1;
}