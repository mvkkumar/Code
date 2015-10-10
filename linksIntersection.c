//
//  stringMatch.c
//  
//
//  Created by Kiran Matturi on 10/5/15.
//
//  Given Two Arrays: find the values that occur in both the arrays
//
//

#include <stdio.h>


//int* getCommonArray( int a[], int b[], int * count ,int array1Len,int array2Len)
//{
////    int array1Len = sizeof(a)/sizeof(a[0]);
////    int array2Len = sizeof(b)/sizeof(b[0]);
//
//    return commonArray;
//}


int main ()
{
    int array1[] = {10,11,19,33,25,44};
    int array2[] = {99,3,65,4,9,56,31,73,11,19};
    int count = 0;
    
    int array1Len = sizeof(array1)/sizeof(array1[0]);
    int array2Len = sizeof(array2)/sizeof(array2[0]);
    int len = 5;
    //length = array1Len>array2Len?array2Len:array1Len;
    
    printf("%i",len);
    int commonArray[len] = {0};
    count = 0;
    for ( int i = 0 ; i<array1Len; i++)
    {
        
        int key = array1[i];
        for ( int j = 0; j< array2Len;j++)
        {
            if ( key == array2[j])
            {
                commonArray[count] = key;
                count++;
            }
        }
    }
    return 0;
}