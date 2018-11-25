//William Ambrozic 2018
//This code was used to answer a question on the puzzling stack exchange
//Solutions are in the form [A,B,C,D,E,F,G,H,I,J,K,L,M,N,O] based on the diagram in the readme
#include <stdio.h>

#define N 15

int AeqB(int data[]);
int BeqC(int data[]);
int CeqD(int data[]);
void printA(int data[]);
void permutation(int data[], int size, int n);
void swap(int *a, int *b);

int main(void) {
  int data[N] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
  int tmp = 0, n = N;

  permutation(data, N, N);
  printf("\nEND OF SOLUTIONS.\n");
}

void swap(int *a, int *b) {
   int tmp;
   tmp  = *b;
   *b = *a;
   *a = tmp;
}

//Using Heap's algorithm, can be found at https://www.geeksforgeeks.org/heaps-algorithm-for-generating-permutations/
void permutation(int data[], int size, int n) {
    if (size == 1) {
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

int AeqB(int data[]) {
  if (data[0] + data[2] + data[3] + data[4] + data[5] + data[6] + data[7] == data[8] + data[9] + data[12] + data[2] + data[4] + data[7] + data[13])
    return 1;
  return 0;
}
int BeqC(int data[]) {
  if (data[10] + data[11] + data[5] + data[3] == data[8] + data[7] + data[13] + data[1])
    return 1;
  return 0;
}
int CeqD(int data[]) {
  if (data[10] + data[11] + data[9] + data[12] + data[2] + data[4] + data[5] + data[3] == data[11] + data[14] + data[12] + data[4] + data[13] + data[7] + data[6] + data[5])
    return 1;
  return 0;
}

void printA(int data[]) {
  printf("Possible Solution: ");
  for (int i = 0; i < N; i++)
    printf("%d ", data[i]);
  printf("\n");
}
