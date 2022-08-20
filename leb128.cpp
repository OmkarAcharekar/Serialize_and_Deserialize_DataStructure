#include <cstdint>
#include <iostream>
#include <iterator>
#include <type_traits>
#include <vector>

class LEB128
{

public:
    std::vector<uint8_t> data;
    LEB128() = default;

    // a constructor taking an integer and  encodes in the `data` member variable having LEB128 encoded data
    template <class T, std::enable_if_t<std::is_integral_v<T>, int> = 0>
    explicit LEB128(T v)
    { // checking if the number is signed
        if constexpr (std::is_signed_v<T>)
        {
            // signed LEB128 encoding
            bool more = true;

            while (more)
            {
                T byte = v & 0x7f;
                v >>= 7;
                if (v == 0 && (byte & 0x40) == 0)
                    more = false;
                else if (v == -1 && (byte & 0x40) > 0)
                    more = false;
                else
                {
                    byte |= 0x80;
                }

                data.push_back(byte);
            }
        }
        else
        {
            // unsigned LEB128 encoding
            do
            {
                T x = v & 0b01111111;
                v >>= 7;
                if (v)
                    x |= 0b10000000;
                data.push_back(x);
            } while (v);
        }
    }

    // decodes the LEB128 encoded data  from data member vaiable
    template <class T>
    std::enable_if_t<std::is_integral_v<T>, T> to() const
    {
        T result = 0;
        // checking if the number signed
        if constexpr (std::is_signed_v<T>)
        {
            // signed LEB128 decoding
            T result = 0;
            T shift = 0;
            T i = 0;
            int n = 64;
            while (true)
            {
                T byte = data[i];
                result |= ((byte & 0x7f) << shift);
                shift += 7;
                if ((byte & 0x80) == 0)
                {
                    break;
                }
                else
                {
                    i += 1;
                }
            }
            if ((shift < n) && (data[i] & 0x40) != 0)
            {
                result |= (~0 << shift);
            }

            return result;
        }
        else
        {
            // unsigned LEB128 decoding

            T res = 0, shift = 0;
            T i = 0;
            T len = data.size();
            while (true)
            {

                if (i < len)
                {
                    uint8_t b = data[i++];
                    res |= (b & 0x7F) << shift;
                    if (!(b & 0x80))
                    {
                        break;
                    }
                    shift += 7;
                }
            }

            return res;
        }
    }

    // write a LEB128 to a stream
    friend std::ostream &operator<<(std::ostream &os, const LEB128 &l)
    {
        return os.write(reinterpret_cast<const char *>(l.data.data()),
                        static_cast<std::streamsize>(l.data.size()));
    }

    // read a LEB128 from a stream
    friend std::istream &operator>>(std::istream &is, LEB128 &l)
    {
        l.data.clear();
        uint8_t x;
        while (is.read(reinterpret_cast<char *>(&x), 1))
        {
            l.data.push_back(x);
            if (!(x & 0b10000000))
                break;
        }
        return is;
    }
};