#include "leb128.cpp"
#include <cstring>
#include <sstream>
#include <iostream>
#include <fstream>

class Data
{

public:
    int32_t Int32;
    float Float;
    int64_t Int64;
    double Double;
    std::vector<uint8_t> U8Array;

    // serialize function : similar to std::vector<uint8_t> serialize(Data &D):
    friend std::ostream &operator<<(std::ostream &os, const Data &D)
    {
        os << LEB128(D.Int32);
        // the float is in platform dependent binary format here:
        os.write(reinterpret_cast<const char *>(&D.Float), sizeof D.Float);
        os << LEB128(D.Int64);
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
        char buf[sizeof l.Float];
        char buff[sizeof l.Double];

        // the float is in platform dependent binary format here:
        (is >> lebInt32).read(buf, sizeof buf);
        std::memcpy(&l.Float, buf, sizeof buf);
        (is >> lebInt64).read(buff, sizeof buff);
        std::memcpy(&l.Double, buff, sizeof buff);
        is >> lebSize;
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

        l.Int64 = lebInt64.to<int64_t>();

        return is;
    }
};

bool check(Data x, Data y)
{

    return x.Int32 == y.Int32 && x.Float == y.Float && x.U8Array == y.U8Array && x.Double == y.Double && x.Int64 == y.Int64;
}
