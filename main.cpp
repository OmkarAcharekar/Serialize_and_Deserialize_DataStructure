#include "data.cpp"
#include <cstring>
#include <sstream>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

// TestCase Data
int32_t arr1[] = {3434232, 878787878, 8643232u, 47678798, 455655229, 98812233, 87676767u, 243978776u, 1234444, 2147483647, 343443u, -2323232, 23, 9282717, 29999999, 3234423u, 993223, 232545, 34343434u, 1, 3232u, 864323, 754232, 56343, 2324u};
float arr2[] = {222323.44f, 232342.2322f, 1234991.23012f, 44.212f, 12.4412f, 12999.12132f, 2112.66996f, 11288.585f, 91299.944f, 237723.4521f, 323243.232f, 232.125, 99.12, 323.32, 33.5555, 434.22f, 343.55f, 22.2f, 1.1f, 116.666f, 34.43f, 2344.444444f, 342.55f, 43466.5f, 55.5f};
int64_t arr3[] = {9223372036854775807, 21243423245u, 125313243456, 92838592924u, 2328693929, 2993423223, 7711111u, 0, 1212323, 100000000000, 2232, 6323, 1213, 6666666, 123323243, 343234, 34232435354, 23435462, 343546782, 8888888888,
                  3434231, 7787866434u, 24657681, 5767432323, 7745343232u};
double arr4[] = {22.442323777, 287832.2324233, 12347799.23023343433, 44.23212778812, 99124.4787412, 1882.39922, 12.66999999999912, 112.58877232, 912.999778, 35623.22882111, 2322.2324366, 23232.3234, 12366.34, 244.44, 542.22434, 12.35544646, 454676.132436, 232232.66, 24.566777, 234.23333, 2323.23242323, 423323.2323, 232.1232443, 45323.2323, 243545.343};

// Function to generate random vector of vectors for testdata
void generate_random_vectors(const int num_of_rand_vectors, std::vector<std::vector<uint8_t>> &vec)
{
    for (int j = 0; j < num_of_rand_vectors; ++j)
    {
        // the vector size will be randomal: between 0 to 19
        int vec_size = (rand() % 20);
        std::vector<uint8_t> rand_vec(vec_size);
        for (int k = 0; k < vec_size; ++k)
        {
            // vec element will be random between 1-20
            rand_vec[k] = 1 + (rand() % 60);
        }

        vec.push_back(rand_vec);
    }
}

int main()
{

    srand(static_cast<unsigned int>(time(NULL)));
    std::vector<std::vector<uint8_t>> vec;
    generate_random_vectors(25, vec);

    int test(0), passed(0), failed(0), testcases(25);

    while (test < testcases)
    {
        std::cout << "---------------------------------------------------------------------------" << '\n';
        std::vector<uint8_t> vect;
        for (int i = 0; i < vec[test].size(); i++)
        {

            vect.push_back(unsigned(vec[test][i]));
        }
        // {int32_t, float, int64_t, double , vector<uint8_t>}
        Data D1{arr1[test], arr2[test], arr3[test], arr4[test], vect};
        std::stringstream ss;
        ss << D1;

        Data D2;
        ss >> D2;

        std ::string result = check(D1, D2) ? "YES" : "NO";
        if (result == "YES")
        {
            passed++;
        }
        else
        {
            failed++;
        }
        std::cout << "Test Case : " << test + 1 << " | ";
        std::cout << "int32_t :" << arr1[test] << " "
                  << "float :" << arr2[test] << " "
                  << "int64_t :" << arr3[test] << " "
                  << "double :" << arr4[test] << " "
                  << " vector<uint8_t> :";
        std::cout << "{ ";
        for (int i = 0; i < vect.size(); i++)
        {
            std::cout << unsigned(vect[i]) << " ";
        }
        std::cout << " }";
        std::cout << "| Result : ";

        // If D1 is equal to D2 then implementation is correct
        std::cout
            << std::boolalpha << "Is D1 and D2 equal? : " << result << '\n';
        test++;
        vect.clear();
        std::cout << "---------------------------------------------------------------------------" << '\n';
    }

    std::cout << "\n";
    std::cout << "TestCases :: " << testcases
              << " | ";
    std::cout << "Passed : " << passed << "\t"
              << "Failed : " << failed << "\n";
}