#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int k;

void peg3(int n,char S,char D,char A1){

if (n == 1)
{
//if you access the value of s here just write s+1 instead of 4
//here s = 3 for n=4 so i directly wrote 3+1=4
printf("\nMove disk 4 from peg %c to peg %c ", S, D);
return;
}
peg3(n-1, S, A1, D);
//here n+3 is actually n+s
printf("\nMove disk %d from peg %c to peg %c ", n+3, S, D);
peg3(n-1, A1, D, S);

}

//peg 4 function uses all 4 pegs to transfer
//disks from source to dstination
void peg4(int n,char S,char D,char A1,char A2){
//if n<=3 simply do the following operation

if(n<=3){
/*
when n<=3 we simply use normal algorithm for
Tower of Hanoi
*/

if (n == 0)
return;
if (n == 1) {
	
printf("\nMove Disk %d from peg %c to peg %c ", n, S, D);

return;
}

peg4(n - 2, S, A1, A2,D);

printf("\nMove Disk %d from peg %c to rod %c ", n - 1, S, A2);
printf("\nMove Disk %d from peg %c to rod %c ", n, S, D);
printf("\nMove Disk %d from peg %c to rod %c ",n - 1, A2, D);
peg4(n - 2, A1, D, S,A2);

}
else{


peg4(k,S,A2,D,A1);
peg3(n-k,S,D,A1);
peg4(k,A2,D,S,A1);

}

}
//peg 3 function uses only 3 pegs for
//transfering disks from source to destination
//because one peg holds the k disks in proper order

int main()
{
int n;
int pegs=4;
printf("Enter no of Disks");
scanf("%d",&n);
k=int(floor(sqrt(double(8*n)+1)-1)/2);

printf("value of k is%d\n",k);
printf("For %d disks and 4 pegs Tower of Hanoi Algorithm is as ",n);
peg4(n, 'S', 'D', 'A', 'B');
scanf("%d",n);

   return 0;
}