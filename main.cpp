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
        os << LEB128(D.Int32);
        os << LEB128(D.Int64);
        // note that the float and double is in platform dependent binary format here:
        os.write(reinterpret_cast<const char *>(&D.Float), sizeof D.Float);
        os.write(reinterpret_cast<const char *>(&D.Double), sizeof D.Double);
        os << LEB128(D.U8Array.size());
        for (auto val : D.U8Array)
            os << LEB128(val);
        return os;
    }

    // deserialize function  : similar to Data deserialize(std::vector<uint8_t> &Bytes);
    friend std::istream &operator>>(std::istream &is, Data &l)
    {
        LEB128 lebInt32, lebInt64, lebSize;
        char buf[sizeof l.Float];   // used to deserialize the float
        char bufd[sizeof l.Double]; // used to deserialize the double

        if ((is >> lebInt32).read(buf, sizeof buf) && (is >> lebInt64).read(buf, sizeof buf) &&
            (std::memcpy(&l.Float, buf, sizeof buf), is >> lebSize) && (std::memcpy(&l.Double, bufd, sizeof bufd), is >> lebSize))
        {
            l.Int32 = lebInt32.to<int32_t>();
            l.Int64 = lebInt64.to<int64_t>();
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

int main()
{

    Data h1;
    std::ofstream file("Data.bin");
    file << h1;
}