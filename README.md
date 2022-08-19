# Serialize_and_Deserialize_DataStructure
Implemented  the concept of Serializing and Deserializing having IEB128 encoding and decoding.

# Serialized Format

  

* 1 x LEB (1-x) bytes        -        Int32
* 1 x LEB (1-x) bytes        -        Int64
* sizeof(float) bytes        -        Float
* sizeof(double)bytes        -        Double
* 1 x LEB (1-x) bytes        -        U8Array.size()
* U8Array.size() x LEB (0-x) bytes  - The `uint8_t`s in the vector


# How To Use 

From your command line:
```bash
# Clone this repository
$ git clone https://github.com/OmkarAcharekar/Serialize_and_Deserialize_DataStructure.git

# Go into the repository
$ cd Serialize_and_Deserialize_DataStructure


# Run the Main.cpp file
$ gcc main.cpp
$ main
   
# output ( Yes : test case passed , No :  failed) 
Is h1 and h2 equal?  

```



### Tasks Progress

- [x]  Basic Outline.
- [x] LEB128 Encoding and Decoding Algorithms.
- [x] Describe the Implementation and Usage in Readme
- [ ] Test Cases
