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
* leb128.cpp file : LEB Encoding and Decoding algorithms.


## How To Use 

 * Try Online:
  
    [ Use Online link](https://onlinegdb.com/De5HV8GHT)

* From the Command Prompt (Windows) or Terminal (macOS):

  ```bash
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
- [x] Test Cases.



## Reference

* [LEB128](https://en.wikipedia.org/wiki/LEB128)
* [Medium](https://basicdrift.com/explore-encoding-base-128-varints-41665a0dca36)



