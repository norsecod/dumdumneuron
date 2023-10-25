#include <time.h>
#define Neuron_implement
#include "Neuron.h"

int main(void)
{
    srand(time(0)); //seed for randomizer
    matrix x = matrix_allocation(10, 10);
    matrix_random(x,0,10);
    matrix_print(x);
 
    return 0;
}