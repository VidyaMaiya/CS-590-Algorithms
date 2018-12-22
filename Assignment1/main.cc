#include <cstdio>
#include <cstdlib>

#include <sort.h>
#include <timer.h>
#include <random_generator.h>

int main(int argc, char* argv[])
{
  random_generator rg;
  timer t;
  int n, m, d, a;
  
  if (argc > 1)
    { 
      m = atoi(argv[1]);
      m = (m < 1) ? 1 : m;
    }
  else
    {
      cout << "hw1: [m] [n] [direction]" << endl;
      cout << "[m]              size of the random integer vector array" << endl;
      cout << "[n]              dimension of integer vector array" << endl;
      cout << "[direction]      0: random" << endl;
      cout << "                 1: sorted" << endl;
      cout << "                 -1: reverse sorted" << endl;
      cout << endl;
      return 0;
    }

  if (argc > 2)
    {
      n = atoi(argv[2]);
      n = (n < 0) ? 0 : n;
    }
  else
    n = 0;

  if (argc > 3)
    d = atoi(argv[3]);
  else
    d = 0;

  int** input_array;


/*
 * create input array sorted/reverse sorted/random 
 * depending on program argument
 * -> input_array is allocated!
 */
  t.start();
  if (d == 0)
    input_array = create_random_ivector(n, m, true);
  else
    {
      if (d < 0)
	input_array = create_reverse_sorted_ivector(n, m);
      else
	input_array = create_sorted_ivector(n, m);
    }
  t.stop();

  cout << "Timer (generate): " << t << endl;

/*
 * output the first 20 elements for debugging purposes
 */
  for (int i = 0; (i < m) && (i < 20); i++)
    {
      cout << "[ ";
      for (int j = 0; j < n; j++)
	cout << input_array[i][j] << " ";
      cout << "]" << endl;
    }
  cout << endl;



/*
 * Do naiv insertion sort
 */

  cout << "Running insertion sort algorithm: " << endl;
  t.start();
  insertion_sort(input_array, n, 0, m-1);
  t.stop();

  cout << "Timer (sort): " << t << endl;


/*
 * check whether or not the algorithm sorted the array
 */
  if (check_sorted(input_array, n, 0, m-1))
    cout << "The output is sorted!" << endl;
  else
    cout << "ERROR: The output is not sorted!" << endl;

/*
 * output the first 20 elements for debugging purposes
 */
  for (int i = 0; (i < m) && (i < 20); i++)
    {
      cout << "[ ";
      for (int j = 0; j < n; j++)
	cout << input_array[i][j] << " ";
      cout << "]" << endl;
    }
  cout << endl;


/* Do improved insertion sort
 */
  cout << "Running Improved Insertion sort algorithm: " << endl;
  t.start();
  insertion_sort_im(input_array, n, 0, m-1);
  t.stop();

  cout << "Timer (sort): " << t << endl;



/*
  * check whether or not the algorithm sorted the array
  */
  if (check_sorted(input_array, n, 0, m-1))
    cout << "The output is sorted!" << endl;
  else
    cout << "ERROR: The output is not sorted!" << endl;

/*
 * output the first 20 elements for debugging purposes
 */
  for (int i = 0; (i < m) && (i < 20); i++)
    {
      cout << "[ ";
      for (int j = 0; j < n; j++)
        cout << input_array[i][j] << " ";
      cout << "]" << endl;
    }
  cout << endl;

/*
* Do  Merge sort
 */
  cout << "Running Merge sort algorithm: " << endl;
  t.start();
/*
 * temp_array is the temporary array created for input_array to store the sorted data.
 * temp_SumA is the temporary array created to store sorted sum values of vector lengths.
*/
  int** temp_array = new int*[m];
  int*temp_SumA = new int[m];;
  merge_sort(input_array,temp_array,temp_SumA, n, 0, m-1);
 
/* 
  * De-allocating the dinamically created arrays.
*/
  delete[] temp_SumA;
  delete[] temp_array;
  t.stop();
  cout << "Timer (sort): " << t << endl;

/*
 * check whether or not the algorithm sorted the array
 */
  if (check_sorted(input_array, n, 0, m-1))
    cout << "The output is sorted!" << endl;
  else
    cout << "ERROR: The output is not sorted!" << endl;

/*
 * output the first 20 elements for debugging purposes
 */
  for (int i = 0; (i < m) && (i < 20); i++)
    {
      cout << "[ ";
      for (int j = 0; j < n; j++)
        cout << input_array[i][j] << " ";
      cout << "]" << endl;
    }
  cout << endl;

/*
 * free the allocated storage
 */
  remove_ivector(input_array, m);

  return 0;
}

