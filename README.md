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


## How To Use 

 * Online:
  
    [ Use Online link](https://onlinegdb.com/Ho7_kj9vOz)

* From your command line:
  ```bash
  # Clone this repository
  $ git clone https://github.com/OmkarAcharekar/Serialize_and_Deserialize_DataStructure.git

  # Go into the repository
  $ cd Serialize_and_Deserialize_DataStructure

  # Run the Main.cpp file
  $ gcc main.cpp
  $ main

  # output ( Result ::  YES : Passed , NO : failed) 
  
  Test Case :  | int32_t :  float :  int64_t :  double :   vector<uint8_t> :{  }| Result : Is D1 and D2 equal? :   
  Passed :      Failed : 

  ```



## Tasks Progress

- [x] Basic Outline.
- [x] LEB128 Encoding and Decoding Algorithms (Signed).
- [x] LEB128 Encoding and Decoding Algorithms (UnSigned).
- [x] Designed the Serialize and Deserialize functions
- [x] Described the Implementation and Usage in Readme.
- [x] Test Cases.
