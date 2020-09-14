#include<iostream>
#include<math.h>
using namespace std;


// defination of different types of search algorithims
// Liner Search
// Jump Search
// Binary Search
// Interpolation Search


//-----------------------------------------------------------------------------------------------------------------------


template < typename T >
int linear_search ( T arr [], int n, T val )
{

    // looking for the element in the whole array
    for(int i = 0; i < n; i++)
    {

         // if element found return the index of the element 
        if( arr[ i ] == val )
        {   return i;   }
    }

    return -1;
}


//-----------------------------------------------------------------------------------------------------------------------

template < typename T >
int jump_search ( T arr[], int n, T val )
{

    // finding best value for the jump 
    int jmp = sqrt( n );

    // setting bounds for intial block
    int ind = jmp;
    int prev = 0;

    // finding block which might have the value
    while( arr[ min( ind, n ) - 1 ] < val )
    {
        prev = ind;
        ind += jmp;

        // if lower bound of block equals to last index return not found(-1)
        if( prev >= n )
        {   return -1;  }
    }

    // looking for the value in the block
    while( arr[ prev ] < val )
    {
        prev++;

        // if lower bound of block equals to upper bound of block return not found(-1)
        if( prev == min( ind, n ) )
        {   return -1;  }
    }

    // if element found return the index of the element 
    if( arr[ prev ] == val )
    {   return prev; }


    return -1;

}


//-----------------------------------------------------------------------------------------------------------------------


template < typename T>
int binary_search ( T arr[], int s, int e, T val )
{

    // if start is greater than end return not found(-1)
    if( s > e )
    {   return -1;    }

    int mid = (s + e) / 2 ;

    // if mid value is equal to desire value then return the index
    if( arr[ mid ] == val )
    {   return mid; }

    // if mid val is greater than desired value search in the left section with bound( s, mid-1 )
    if( arr[ mid ] > val )
    {   return binary_search( arr, s, mid - 1, val ); }

    // else 
    // mid val is less than desired value search in the right section with bound( mid+1, e )
    return binary_search( arr, mid + 1, e, val );

}


//-----------------------------------------------------------------------------------------------------------------------

template < typename T >
int interpolation_search( T arr[], int n, T val )
{

    // to setthe bounds
    int s = 0, e = n - 1;

    // run the loop till start is lest than equal to end and val is b/w the bounds
    while( s <= e && val >= arr[ s ] && val <= arr[ e ] )
    {

        // finding a possible index for the value while keeping uniform distribution in mind
        int ind = s + ( double( ( e - s ) / ( arr[s] - arr[e] ) ) * ( val - arr[ s ] ) );

        // if value at ind is equal to desire value then return the index
        if( arr[ ind ] == val )
        {   return ind; }

        // if value at ind is greater than desired value search in the left section with bound( s, ind-1 )
        if( arr[ ind ] > val )
        {   e = ind - 1;    }

        // else 
        // mid val is less than desired value search in the right section with bound( ind+1, e )
        else
        {   s = ind + 1;    }

    }

    return -1;

}

//-----------------------------------------------------------------------------------------------------------------------