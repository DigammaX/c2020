#include <stdio.h>
#include <time.h>
#include <string.h>

#define maxn 1000

int main()
{
    int prime[maxn];
    int Prime[maxn];
    memset(prime,0,sizeof(int)*maxn);
    int tail = -1;
    clock_t start,finish;
    start = clock();
    //欧拉筛
    for(int i=2;i<=maxn ;i++){
        if(prime[i]==0){
            Prime[++tail] = i;}
        for(int j=0;j<=tail;j++ ){
                if(i*Prime[j]>maxn) {break;}   //越界,break
                prime[i*Prime[j]]=1;           //筛去这个数和之前所有素数的乘积
                if((i%Prime[j]) == 0) {break;} //每个合数只被它的最小质因子筛选一次，所以如果i=k*p[j],i*p[j+1]是被更大的素因子p[j+1]筛去的，违背了算法的思想
        }               
    }
    //下面证明这个算法的正确性
    //设n=p1*k,p1是n的最小素因子,那么经过数n时,在遍历素数时,至少再遍历到p1时才会退出循环,也就是n一定会被p1筛去
    printf("2是素数\n");
    for(int k=0;k<=tail;k++){
        printf("%d\n", Prime[k]);
    }
    finish = clock();
    double time = (double)(finish-start)/CLOCKS_PER_SEC;
    printf("时间是%0.3fs",time);
}
