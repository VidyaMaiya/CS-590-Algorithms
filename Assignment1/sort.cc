#include <cstdio>
#include <cstdlib>
#include<iostream>
using namespace std;

#include <sort.h>

int ivector_length(int* v, int n)
{
  int sum;

  sum = 0;
  for (int i = 0; i < n; i++)
    sum += (v[i] < 0) ? -v[i] : v[i];

  return sum;
}

/*
 * insertion sort
 */
void insertion_sort(int** A, int n, int l, int r)
{ 
  register int i;
  int* key;

  for (int j = l+1; j <= r; j++)
    {
      key = A[j];
      i = j - 1;

      while ((i >= l) && (ivector_length(A[i], n) > ivector_length(key, n)))
        {
	  A[i+1] = A[i];
	  i = i - 1;
	}

      A[i+1] = key;
    }
}
/*
 * Improved Insertion Sort
*/
void insertion_sort_im(int** A, int n, int l, int r)
{
  int* key;
  int*sum_array = new int[r+1];
  /*
   * sum_array stores the length of each vectors in an array.
   */
  for(int i=0;i<=r;i++)
  {

     sum_array[i]=ivector_length(A[i], n);

  }
  int sKey,i,j;
  for(int j=l+1;j<=r;j++)
  {
     sKey=sum_array[j];
     key=A[j];
     i=j-1;
     /*
      * Sorting vector sum array and original array
        simultaneously.
      */

     while(i>=0 && sum_array[i]>sKey)
     {
     
        sum_array[i+1]=sum_array[i];
        A[i+1]=A[i];
        i--;
     }
     sum_array[i+1]=sKey;
     A[i+1]=key;

  }

  delete[] sum_array;
}
/* 
 * Merge Sort
*/
void calSMerge_Sort(int isum_array[],int** A,int** temp_array,int temp_SumA[], int start,int end)
{  
      int mid;
      if(start<end)
      {
        mid=(start+end)/2;
        calSMerge_Sort(isum_array,A,temp_array,temp_SumA,start,mid);
        calSMerge_Sort(isum_array,A,temp_array,temp_SumA,mid+1,end);
        merge(isum_array,A,temp_array,temp_SumA,start,mid,end);
      }
 }

void merge_sort(int** A,int** temp_array,int temp_SumA[],int n, int start,int end)
{
   int* isum_array = new int[end+1];
   /*
   * sum_array stores the length of each vectors in an array.
   */
      for(int i=0;i<=end;i++)
      {

       isum_array[i]=ivector_length(A[i], n);

      }
     /*
      * calSMerge_Sort() divides the vector sum array 
      */
      calSMerge_Sort(isum_array,A,temp_array,temp_SumA,start,end);
      delete[] isum_array;
}  
  
void  merge(int isum_array[],int** A,int** temp_array,int temp_SumA[],int start,int mid,int end)
{
   int i=start,j=mid+1;
   int k=0;
   /*
    * Creating Temporary array for vector sum array and input array.
    * Sorting vector sum array and input array simultaneously.
    */
    while(i<=mid && j<=end)
    {
	    if(isum_array[i] < isum_array[j])
	    {
                temp_SumA[k]=isum_array[i];
                temp_array[k]=A[i];
		        k++;
		        i++;
   	    }
 	    else
        {
                temp_SumA[k]=isum_array[j];
                temp_array[k]=A[j];
                k++;
                j++;
	    }   
    }
    while(i<=mid)
   {
         temp_SumA[k]=isum_array[i];
         temp_array[k]=A[i];
	     k++;
	     i++;
   }
   while(j<=end)
   {
        temp_SumA[k]=isum_array[j];
        temp_array[k]=A[j];
	    k++;
	    j++;
   }
   /* 
    * Updating vector sum array and input array with sorted values.
    */
   for(int k=0,i=start;i<=end;i++,k++)
  {
     isum_array[i]=temp_SumA[k];
     A[i]=temp_array[k];
  }
}

/*
 * Simple function to check that our sorting algorithm did work
 * -> problem, if we find position, where the (i-1)-th element is
 *    greater than the i-th element.
 */
bool check_sorted(int** A, int n, int l, int r)
{
  for (int i = l+1; i <= r; i++)
    if (ivector_length(A[i-1], n) > ivector_length(A[i], n))
      return false;
  return true;
}


/*
 * generate sorted/reverse/random arrays of type hw1type
 */
int** create_ivector(int n, int m)
{
  int** iv_array;

  iv_array = new int*[m];
  for (int i = 0; i < m; i++)
    iv_array[i] = new int[n];

  return iv_array;
}

void remove_ivector(int** iv_array, int m)
{
  for (int i = 0; i < m; i++)
    delete[] iv_array[i];
  delete[] iv_array;
}

int** create_sorted_ivector(int n, int m)
{
  int** iv_array;

  iv_array = create_ivector(n, m);
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      iv_array[i][j] = (i+j)/n;

  return iv_array;
}

int** create_reverse_sorted_ivector(int n, int m)
{
  int** iv_array;

  iv_array = create_ivector(n, m);
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      iv_array[i][j] = ((m-i)+j)/n;

  return iv_array;
}

int** create_random_ivector(int n, int m, bool small)
{
  random_generator rg;
  int** iv_array;

  iv_array = create_ivector(n, m);
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      {
	rg >> iv_array[i][j];
	if (small)
	  iv_array[i][j] %= 100;
	else
	  iv_array[i][j] %= 65536;
      }

  return iv_array;
}

