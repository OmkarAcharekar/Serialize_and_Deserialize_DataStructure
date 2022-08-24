# Serialize_and_Deserialize_DataStructure

Implemented the concept of Serializing and Deserializing Data structure having LEB128 encoding and decoding.


## Serialized Format

  
```bash
* 1 x LEB (1-x) bytes        -        Int32
* 1 x LEB (1-x) bytes        -        Int64
* sizeof(float) bytes        -        Float
* sizeof(double)bytes        -        Double
* 1 x LEB (1-x) bytes        -        U8Array.size()
* U8Array.size() x LEB (0-x) bytes  - The `uint8_t`s in the vector
```
### Note :  

* All integer types use LEB128 for encoding and decoding.
* Float and Double is in platform dependent binary format.
* data.cpp file : Data structure , serialize and deserialize functions.
* leb128.cpp file : LEB128 Encoding and Decoding algorithms.

## Important

**The Implementation in this repo does not strictly follows the signature asked in the pretest**
To see that implementation : See [here](https://www.onlinegdb.com/3SO2uK-l3e) 

Difference : In the above implementation, instead of piping the encoded bytes of data members into stream, I have pushed them into a vector with a extra additional byte appended to each member encoded bytes to know type information so that it can be deserialized



## How To Use 

 * Try Online (You can directly edit the testcase) :
  
    [ Use Online link](https://onlinegdb.com/ifj9QX7RH)

* From the Command Prompt (Windows) or Terminal (macOS) (It contains 25 testcases) :

  
  
  ```bash
  # To clone and successfully run this project, you should have C++17 / above version and Git installed on your computer.
  # Clone this repository
  $ git clone https://github.com/OmkarAcharekar/Serialize_and_Deserialize_DataStructure.git

  # Go into the repository
  $ cd Serialize_and_Deserialize_DataStructure

  # Run the Main.cpp file
  $ g++ -o <name-you-want-to-give-to-executable-file> main.cpp
  $ ./<nameofexecutable-file>

  # output ( Result ::  YES : Passed (Implementation is correct) , NO : failed (Implementation is incorrect) 
  
  Test Case :   | int32_t :  float :  int64_t :  double :   vector<uint8_t> :{  }| Result : Is D1 and D2 equal? :   
  TestCases ::  | Passed :     Failed : 

  ```

## Tasks Progress

- [x] Basic Outline.
- [x] LEB128 Encoding and Decoding Algorithms (Signed).
- [x] LEB128 Encoding and Decoding Algorithms (UnSigned).
- [x] Designed the Serialize and Deserialize functions.
- [x] Described the Implementation and Usage in Readme.
- [x] Add Test Cases 



## Reference

* [LEB128](https://en.wikipedia.org/wiki/LEB128)
* [Medium](https://basicdrift.com/explore-encoding-base-128-varints-41665a0dca36)



