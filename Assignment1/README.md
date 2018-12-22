# CS-590-Algorithms
Computer Science Graduate Elective Course

Assignment1:
--------------
1. Develop an improved implementation of insertion sort for integer vector (insertion_sort_im) that
precomputes the length of each vector before the sorting. Keep in mind that the vectors are sorted
according to their length (see ivector_length function). You can test the correctness of your sorting
algorithm using the provided check_sorted function.
2. Implement a merge sort for an array of integer vectors. As for the improved insertion sort algorithm,
you should precompute the length of the vectors before the sorting and the sorting is done according to
the vector length. Test the correctness of your merge sort implementation using the provided
check_sorted function.
3. Measure the runtime performance of insertion sort (naive and improved) and merge sort for random,
sorted, and inverse sorted inputs of size n = 10000; 25000; 50000; 100000; 250000; 500000; 1000000;
2500000 and vector dimension m = 10; 25; 50. You can use the provided functions create_random_ivector,
create_sorted_ivector, create reverse_sorted_ivector.
Repeat each test a number of times (usually at least 10 times) and compute the average running time for
each combination of algorithm, input, and size n. Report and comment on your results.
