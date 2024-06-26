#include "linear_system.h"
#include <stdio.h>
#include <stdlib.h>
#include "solver.h"
#include <omp.h>

//main solveur de système 
int main(int argc, char const *argv[])
{

    if(argc < 2){
        printf("Utilisation : ./solver.exe PATH VERBOSE\nAvec :\n\tPATH : Chemin vers le fichier\n\tVERBOSE : Le niveau d'affichage du programme (optionnel, défaut = 1)\n");
        return EXIT_SUCCESS;
    }

    int verbose = 1;

    // Verbose arg ? 
    if (argc > 2)
    {
        verbose = atoi(argv[2]);
    }

    char read_path[64];
    snprintf(read_path,sizeof(read_path),"%s",argv[1]);
    
    
    //Lecture du fichier    
    linear_system* sys;
    
    sys = (linear_system *)malloc(sizeof(linear_system));

    if( ! (read_system(sys,read_path))){
        printf("Erreur lors de la lecture du fichier \n");
        return EXIT_SUCCESS;
    }
    
    char save_path[64];
    snprintf(save_path,sizeof(save_path),"%s_solved.txt",argv[1]); 

    //Calculs & sauvegarde
    
    solve_system(sys,save_path,verbose);
   
    //Libération de la mémoire
    free_system(sys);

    return 0;
}
