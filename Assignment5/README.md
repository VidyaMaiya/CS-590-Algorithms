# CS-590-Algorithms

Assignment5:
------------
1. We wish to implement a dictionary by using direct addressing on a huge array. At the start, the array
entries may contain garbage, and initializing the entire array is impractical because of its size. Describe a
scheme for implementing a direct-address dictionary on a huge array. Each stored object should use O(1)
space; the operations SEARCH, INSERT, and DELETE should take O(1) time each; and the initialization of
the data structure should take O(1) time. (Hint: Use an additional stack, whose size is the number of keys
actually stored in the dictionary, to help determine whether a given entry in the huge array is valid or not.)
The description should be detailed enough, so if a programmer reads the description, they should be able
to write the code with no further questions.
2. Consider a hash table of size m = 1000 and a corresponding hash function:
,h(k) =  floor[m(kAmod1)], A = (sqrt(5) - 1) /2
Compute the locations to which the keys 61, 62, 63, 64, and 65 are mapped.
