/*
 *
 * Author: Preeti Malakar
 * Affiliation: Argonne National Laboratory
 * Email: pmalakar@anl.gov
 *
 */

#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include <math.h>
#include <string.h>
#include <mpi.h>
#include <queue>
#include <unistd.h>
#include <inttypes.h>

#include "path.h"

int NUMLNETS;
int NUMNODES;

int main (int argc, char *argv[]) {
  
  int myrank, commsize; 
  int a,b,c,d,e,f;

  MPI_Init (&argc, &argv);
  MPI_Comm_rank (MPI_COMM_WORLD, &myrank);
	MPI_Comm_size (MPI_COMM_WORLD, &commsize);

  int lnetnodeid;
  char LNETFile[64], ComputeFile[64];  

  //NUMNODES = atoi (argv[1]);
  //NUMLNETS = atoi (argv[2]);
  strcpy(LNETFile, argv[1]);
  strcpy(ComputeFile, argv[2]);

  NUMLNETS=0;

  if (myrank == 0) {
    FILE *lnetfp = fopen(LNETFile, "r");
    if(lnetfp==NULL) exit(1);
    while (fscanf(lnetfp, "%d %d %d %d %d %d\n", &a,&b,&c,&d,&e,&f) > 0) {
#ifdef DEBUG
     printf ("%d %d %d %d %d %d\n", &a,&b,&c,&d,&e,&f);
#endif
     NUMLNETS ++;
    }
    fclose(lnetfp);
    FILE *computefp = fopen(ComputeFile, "r");
    fclose(computefp);
  }

  MPI_Bcast (&NUMLNETS, 1, MPI_INT, 0, MPI_COMM_WORLD);

  //LNETNode *lnetnode = new LNETNode (lnetnodeid);

  MPI_Finalize ();
}


