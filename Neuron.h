#ifndef NEURON_H_
#define NEURON_H_ //header part

#include <stddef.h>
#include <stdio.h>

#ifndef NEURON_MALLOC
#include <stdlib.h>
#define NEURON_MALLOC malloc
#endif //NEURON_MALLOC

#ifndef NEURON_ASSERT
#include <assert.h>
#define NEURON_ASSERT assert
#endif //NEURON_ASSERT

typedef struct
{
    size_t rows;       //size_t = 64bit on my system
    size_t collums;
    float *st; //pointer for the linear element          

}matrix;

#define matrix_at(a,i,j) (a).st[(i)*(a).collums + (j)]

float rand_float(void);

matrix matrix_allocation(size_t rows, size_t collums); //function to allocate memory for matrixes
void matrix_random(matrix a, float min, float max);                          //randomize the numbers inside a matrix, used to jump start a nevron
void matrix_dot(matrix dest, matrix a, matrix b);      //prototype function for matrix dot product
void matrix_sum(matrix dest, matrix a);                //prototype function for matrix sum
void matrix_print(matrix a);                           //prototype function to print the matrix values 

#endif // NEURON_H_

#ifdef Neuron_implement //c part

float rand_float(void)
{
   return (float) rand() / (float) RAND_MAX; //gives a random float value
}

matrix matrix_allocation(size_t rows, size_t collums)
{
    matrix mx;
    mx.rows = rows;
    mx.collums = collums;
    mx.st = NEURON_MALLOC(sizeof(*mx.st)*rows*collums); //should allocate enough memory for all of the floats
    NEURON_ASSERT(mx.st != NULL); //check that the value in pointer is not 0
    return mx;
}
/*
void matrix_dot(matrix dest, matrix a, matrix b)    
{
    void(dest);
    void(a);
    void(b);
}  

void matrix_sum(matrix dest, matrix a)
{
    void(dest);
    void(a);
}   
*/
void matrix_print(matrix a)
{  
     for (size_t i = 0; i < a.rows; ++i){
        for (size_t j = 0; j < a.collums; ++j){
            printf("%f  ", matrix_at(a, i, j) ); 
        }
        printf("\n");                                   
     }                                     
}

void matrix_random(matrix a, float min, float max)
{
     for (size_t i = 0; i < a.rows; ++i){
        for (size_t j = 0; j < a.collums; ++j){
            matrix_at(a, i, j) = rand_float()*(max - min) + min;
        }
     }    
}


#endif // Neuron_implement