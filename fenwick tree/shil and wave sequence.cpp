#include<stdio.h>
#define s(x) scanf("%d",&x)
#define f(i,a,b) for(i=a;i<b;i++)
#define B 1000000007
#define N 100004
int bit0[N],bit1[N],n,f[N][2];
 
void update(int bit[], int pos, int val)
{
    for(;pos<N;pos+=pos&-pos)
        bit[pos]=(bit[pos]+val)%B;
}
int query(int bit[], int pos)
{
    int ans=0;
    for(;pos>0;pos-=pos&-pos)
        ans=(ans+bit[pos])%B;
    return ans;
}
int main()
{
    s(n);
    int a[n+1],ans=0,i,j;
    f(i,0,n)
        s(a[i]);
    f(i,0,n)
    {
         f(j,0,2) {
            if (j == 1) {
                f[i][j] = (f[i][j] + query(bit0, a[i] - 1) + 1) % B;
            }
            else  f[i][j] = (f[i][j] + query(bit1, N - a[i]) + 1) % B;
            ans = (ans + f[i][j]) % B;
        }
        update(bit1, N - a[i] + 1, f[i][1]);
        update(bit0, a[i], f[i][0]);
    }
    printf("%d\n",ans-2*n);
    return 0;
}
