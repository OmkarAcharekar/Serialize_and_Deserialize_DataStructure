# Serialize_and_Deserialize_DataStructure
Implemented  the concept of Serializing and Deserializing having IEB128 encoding and decoding.

# Serialized Format

  

* 1 x LEB (1-x) bytes        -        Int32
* 1 x LEB (1-x) bytes        -        Int64
* sizeof(float) bytes        -        Float
* sizeof(double)bytes        -        Double
* 1 x LEB (1-x) bytes        -        U8Array.size()
* U8Array.size() x LEB (0-x) bytes  - The `uint8_t`s in the vector


### Tasks

- [x]  Basic Outline.
- [x] LEB128 Encoding and Decoding Algorithms.
- [ ] Describe the Implementation and Usage in Readme
- [ ] Test Cases
