#include "linear_system.h"
#include <stdio.h>
#include <stdlib.h>
int main(void){
    linear_system * syst;
    syst = (linear_system *)malloc(sizeof(linear_system));

    //Récupération du système dans sys1.txt
    read_system(syst,"./sys1.txt");

    print_system(syst);

    free(syst);
}