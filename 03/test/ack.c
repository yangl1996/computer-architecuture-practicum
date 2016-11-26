#include<stdio.h>
long long ack(long long m,long long n);
int main(){
	long long n, m;
	scanf("%lld %lld", &m, &n);
	printf("a(m,n) = %lld\n",ack(m,n));
	return 0;
}
long long ack(long long m,long long n)  
{  
    if(m == 0)  
        return n+1;  
    else if(n == 0)  
        return ack(m-1,1);  
    else  
        return ack(m-1,ack(m,n-1));  
}  
