#include<iostream>
#include<math.h>
using namespace std;


// defination of different sort algorithms
// Selection Sort
// Insertion Sort
// Bubble Sort
// Shell sort
// Merge Sort



//-----------------------------------------------------------------------------------------------------------------------


template < typename T >
void  swap ( T *a, T *b )
{
    T temp = *a;
    *a = *b;
    *b = temp;
}



//-----------------------------------------------------------------------------------------------------------------------


template < typename T >
void selection_sort ( T arr[], int n )
{

    // move the boundary of unsorted array
    for(int i = 0; i < n - 1; i++)
    {
        int min_ind = i;
        for(int j = i + 1; j < n; j++)
        {
            // find the index of the min val in unsorted part
            if( arr[ j ] < arr[ min_ind ] ) 
            {   min_ind = j;    }    
        }

        // swap i and min_ind
        swap<T>( &arr[ i ], &arr[ min_ind ] );

    }

}


//-----------------------------------------------------------------------------------------------------------------------


template < typename T >
void insertion_sort ( T arr[], int n )
{
    
    // iterate in the array 
    for(int i = 1; i < n; i++)
    {
        // insertion of new element in the sorted part
        T new_ele = arr[ i ];
        for(int j = i - 1; j >= 0 && arr[j] > new_ele; j--)
        {   
            arr[ j + 1 ] = arr[ j ]; 
            arr[ j ] = new_ele;
        }
    }
}


//-----------------------------------------------------------------------------------------------------------------------


template < typename T >
void bubble_sort( T arr[], int n )
{

    // decreasing the upperboud of unsorted part
    for(int i = n - 1; i > 0; i--)
    {
        // creating a flag to check if we swapped a element 
        // swapping all neighbouring  elements in unsorted part if there order is wrong
        // result the largest value will reach the correc position 
        bool flag = true;
        for(int j = 0; j < i; j++)
        {
            if( arr[ j ] > arr[ j + 1 ] )
            {   
                swap< T >( &arr [ j ], &arr[ j + 1 ] );   
                flag = false;
            }
        }

        // break from the loop if there was no swap as rest of array is sorted already
        if( flag )
        {   break;  }
    }
}


//-----------------------------------------------------------------------------------------------------------------------


template < typename T >
void shell_sort ( T arr[], int n )
{

    // finding the intial gap using Knuth's formula
    int gap = 1;
    while( ( gap * 3 + 1 ) < n)
    {   gap = gap * 3 + 1;  }

    //  starting with initial gap and dcreassing the gap
    for( ; gap > 0; gap = ( gap - 1 ) / 3)
    {

        // sorting element with gapusing insertion sort
        // performing insertion sort on gapped elements
        for( int i = gap; i < n; i++)
        {

            T temp = arr[ i ];
            for(int j = i; j >= gap && arr[ j - gap ] > temp; j-=gap)
            {
                arr[ j ] = arr[ j - gap ];
                arr[ j - gap ] = temp;
            }
        }
    }
}


//-----------------------------------------------------------------------------------------------------------------------


template < typename T >
void merge( T arr[], int l, int r, int m)
{
    // size of left and right part
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[ n1 ], R[ n2 ];

    // coping left and right part of the array to be merge
    for(int i = 0; i < n1; i++)
    {   L[ i ] = arr[ l + i ];   }
    for(int i = 0; i < n2; i++)
    {   R[ i ] = arr[ m + i + 1 ];   }


    // merging left and right part into the array such that is is sorted
    int i = 0, j = 0, k = l;
    while( i < n1 || j < n2)
    {
        if( j == n2 || ( i < n1 && L[ i ] < R[ j ] ) )
        {
            arr[ k ] = L[ i ];
            i++;
        }

        else 
        {
            arr[ k ] = R[ j ];
            j++;
        }
        k++;
    }
}

template < typename T >
void merge_sort ( T arr[], int l, int r )
{

    // check left bound is less than right
    if( l < r )
    {
        int m = ( l + r ) / 2;

        // sorting left and right part
        merge_sort< T >( arr, l, m );
        merge_sort< T >( arr, m + 1, r );

        // merging left and right sorted part into a sorted array
        merge< T >( arr, l, r, m );
    }

}




//-----------------------------------------------------------------------------------------------------------------------


