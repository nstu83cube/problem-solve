#include <stdio.h>
#include <math.h>
#define MAX 10000001
#define RANGE 20000001
#define POSITION_RANGE 100001
int prime[MAX+1],prime_number[MAX];
int TwinPrime1[POSITION_RANGE],TwinPrime2[POSITION_RANGE];
int k=0;
void seive()
{
    int i,j,root;
    root=sqrt(MAX);
    prime[0]=prime[1]=1;
    for(i=4;i<=MAX;i+=2) prime[i]=1;
    for(i=3;i<=root;i+=2){
        for(j=i*i;j<=MAX;j+=i)
            prime[j]=1;
    }
    for(i=2;i<=MAX;i++){
        if(!prime[i]) prime_number[k++]=i;
    }
}
void isprime()
{
    int i,j;
    for(i=MAX+1;i<=RANGE;i++){
        int check=0,root=sqrt(i);
        for(j=0;prime_number[j]<=root;j++){
            if(i%prime_number[j]==0){
                check=1;
                break;
            }
        }
        if(!check) prime_number[k++]=i;
    }
}
void twin_prime()
{
    int i,j=1,m=1;
    for(i=0;i<k,j<POSITION_RANGE,m<POSITION_RANGE;i++){
        if(prime_number[i]+2==prime_number[i+1]){
            TwinPrime1[j++]=prime_number[i];
            TwinPrime2[m++]=prime_number[i+1];
        }
    }
}
int main()
{
    seive();
    isprime();
    twin_prime();
    int S;
    while(scanf("%d",&S)!=EOF){
        printf("(%d, %d)\n",TwinPrime1[S],TwinPrime2[S]);
    }
    return 0;
}
