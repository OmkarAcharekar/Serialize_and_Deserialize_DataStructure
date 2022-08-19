#include "leb128.cpp"
#include <cstring>
#include <fstream>
#include <sstream>
class Data
{

public:
    int32_t Int32;
    float Float;
    std::vector<uint8_t> U8Array;

    // serialize function : similar to std::vector<uint8_t> serialize(Data &D):
    friend std::ostream &operator<<(std::ostream &os, const Data &D)
    {
        os << LEB128(D.Int32);
        // the float is in platform dependent binary format here:
        os.write(reinterpret_cast<const char *>(&D.Float), sizeof D.Float);
        os << LEB128(D.U8Array.size());
        for (auto val : D.U8Array)
            os << LEB128(val);
        return os;
    }

    // deserialize function  : similar to Data deserialize(std::vector<uint8_t> &Bytes);
    friend std::istream &operator>>(std::istream &is, Data &l)
    {
        LEB128 lebInt32, lebSize;
        char buf[sizeof l.Float];

        // the float is in platform dependent binary format here:
        if ((is >> lebInt32).read(buf, sizeof buf) &&
            (std::memcpy(&l.Float, buf, sizeof buf), is >> lebSize))
        {
            l.Int32 = lebInt32.to<int32_t>();
            size_t size = lebSize.to<size_t>();
            l.U8Array.resize(size);
            LEB128 tmp;
            for (auto &val : l.U8Array)
            {
                is >> tmp;
                val = tmp.to<uint8_t>();
            }
        }
        return is;
    }
};

bool check(Data x, Data y)
{
    return x.Int32 == y.Int32 && x.Float == y.Float && x.U8Array == y.U8Array;
}

int main()
{
    Data h1{212538, 2.2743, {1, 1, 43, 14, 65, 26, 77, 98, 29, 6, 6, 21}};
    std::stringstream ss;
    ss << h1;

    Data h2;
    ss >> h2;

    // If h1 is equal to h2 then implementation is correct
    std::cout << std::boolalpha << "Is h1 and h2 equal? " << check(h1, h2) << '\n';

    // Data h1;
    // std::ofstream file("Data.bin");
    // file << h1;

    // Data h2;
    // std::ifstream file("Hello.bin");
    // file >> h2;
}
