#ifndef __path__
#define __path__

//#define prnl printf("\n")
//#define __STDC_FORMAT_MACROS 1 // In C++ the macros are not automatically defined just by including the file. 

//#define MAXBUF (1024*32)
//#define xMicroSec 1000000

using namespace std;

// Variables
//extern int myrank, commsize, mode, fileSize;
extern int NUMLNETS, NUMNODES;

class LNETNode {
   
   private:

		int nodeId;
    int coords[5];
		int *hops;	

   public:

    LNETNode() { nodeId = 0; }
		~LNETNode() {}

    LNETNode (int nodeid, int b,int c,int d,int e,int f) {
      nodeId = nodeid;
      coords[0]=b;
      coords[1]=c;
      coords[2]=d;
      coords[3]=e;
      coords[4]=f;
      hops = (int *) malloc(NUMNODES * sizeof(int));
    }

    int getHops (int rank) {
      return hops[rank];
    }

};

class ComputeNode {

   private:

		int nodeId, rank;
		int *hopstoLNET;

   public:

    ComputeNode() { nodeId = 0; }
		~ComputeNode() {}

    ComputeNode (int nodeid, int rank) {
      nodeId = nodeid, rank = rank;
      hopstoLNET = (int *) malloc(NUMLNETS * sizeof(int));
    }

    int getHopsToLNET (int lnetnodeId) {
      return hopstoLNET[lnetnodeId];
    }


};

#endif
