/*****
William Ambrozic 2018

This code was used to answer a question on the puzzling stack exchange
Solutions are in the form [A,B,C,D,E,F,G,H,I,J,K,L,M,N,O] based on the diagram in the readme

Each elipse can be looked at as 4 sets:
  The first set is comprised of (A, B, C, D, E, F, G, H) or (data[0], data[1], data[2], data[3], data[4], data[5], data[6], data[7])
  The second set is comprised of (B, C, E, H, I, J, M, N) or (data[1], data[2], data[4], data[7], data[8], data[9], data[12], data[13])
  The third set is comprised of (C, D, E, F, J, K, L, M) or (data[2], data[3], data[4], data[5], data[9], data[10], data[11], data[12])
  The fourth set is comprised of (E, F, G, H, L, M, N, O) or (data[4], data[5], data[6], data[7], data[11], data[12], data[13], data[14])

The data indecies are based on their alphabetical index
i.e.
=>[A,B,C,D,E,F,G,H,I,J,K ,L ,M ,N ,O ]
=>[0,1,2,3,4,5,6,7,8,9,10,11,12,13,14]
*****/

#include <stdio.h>

#define N 15

int AeqB(int data[]);
int BeqC(int data[]);
int CeqD(int data[]);
void printA(int data[]);
void permutation(int data[], int size, int n);
void swap(int *a, int *b);

int main(void) {
  int data[N] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15}; //initializing data in the form [A,B,C...]

  permutation(data, N, N);
  
  printf("\nEND OF SOLUTIONS.\n");
}

//This function simply swaps two integer pointers
void swap(int *a, int *b) {
   int tmp;
   tmp  = *b;
   *b = *a;
   *a = tmp;
}

//Using Heap's algorithm, can be found at https://www.geeksforgeeks.org/heaps-algorithm-for-generating-permutations/
//This recursive function looks at every possible arangment of the dataset and determines if the four sums of the sets are equal
void permutation(int data[], int size, int n) {
    if (size == 1) {
      //Determining if all sums are equal
      if(AeqB(data) == 1 && BeqC(data) == 1 && CeqD(data) == 1)
        printA(data);
      return;
    }
    for (int i = 0; i < size; i++) {
        permutation(data,size-1,n);
        if (size%2==1)
            swap(&data[0], &data[size-1]);
        else
            swap(&data[i], &data[size-1]);
    }
}

//This function checks if set A is eqaul to set B
int AeqB(int data[]) {
  //Values present on both sides of the equation cancel out so they are not included
  if (data[0] + data[2] + data[3] + data[4] + data[5] + data[6] + data[7] == data[8] + data[9] + data[12] + data[2] + data[4] + data[7] + data[13])
    return 1;
  return 0;
}

//This function checks if set B is equal to set C
int BeqC(int data[]) {
  //Values present on both sides of the equation cancel out so they are not included
  if (data[10] + data[11] + data[5] + data[3] == data[8] + data[7] + data[13] + data[1])
    return 1;
  return 0;
}

//This function checks if set C is equal to set D
int CeqD(int data[]) {
  //Values present on both sides of the equation cancel out so they are not included
  if (data[10] + data[11] + data[9] + data[12] + data[2] + data[4] + data[5] + data[3] == data[11] + data[14] + data[12] + data[4] + data[13] + data[7] + data[6] + data[5])
    return 1;
  return 0;
}

//This function simply prints the possible solutions
void printA(int data[]) {
  printf("Possible Solution: ");
  for (int i = 0; i < N; i++)
    printf("%d ", data[i]);
  printf("\n");
}
