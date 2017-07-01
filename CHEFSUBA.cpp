#include <iostream>
using namespace std;
char q[100001];
bool num[200002];
int win[200002];
int LR[200002]={0};
int RL[200002]={0};
int maxx(int a, int b)
{
    return(a>b?a:b);
}
int main() {
	// your code goes here
	int n,k,p;
	cin>>n>>k>>p;
	//if(k>n)
	//k=n;
	for(int i=1;i<=n;i++)
	{
	    cin>>num[i];
	 //   cout<<num[i];
	}
	for(int i=n+1;i<=2*n;i++)
	{
	    num[i]=num[i-n];
	}
	cin>>q;
//	cout<<q;
	
	int count = 0, index=1;
	while(index<=k)
	{
	    if(num[index])
	        count++;
	    index++;
	}
	win[1]=count;
	for(int i=2;i<=2*n-k+1;i++)
	{
	    if(num[i+k-1]>num[i-1])
	        win[i]=win[i-1]+1;
	    else if(num[i+k-1]<num[i-1])
	        win[i]=win[i-1]-1;
	   else 
	        win[i]=win[i-1];
	}
	for(int i=2*n-k+2;i<=2*n;i++)
	    win[i]=0;
	   /* 
    for(int i=1;i<=2*n;i++)
        cout<<" "<<win[i]<<" ";
     */
    int size = n-k+1;
    for(int i=1;i<=2*n;i++)
    {
        if(i%size==1 || i==1)
        {
           // cout<<i<<" i%size==1"<<endl;
            LR[i]=win[i];
        }
        else
        {
           // cout<<i<<" i%size==0"<<endl<<win[i]<<" " <<LR[i-1]<<endl;
            LR[i]= maxx(win[i], LR[i-1]);
        }
    }
  //  cout<<endl;
    /*
    for(int i=1;i<=2*n;i++)
        cout<<" "<<LR[i]<<" ";
    */
     for(int i=2*n;i>=1;i--)
    {
        if(i==2*n)
            RL[i]=win[i];
        else if(i%size==0)
            RL[i]=win[i];
        else
            RL[i]=maxx(RL[i+1], win[i]);
       
    }
    for(int i=1;i<=2*n;i++)
    {
        win[i]=maxx(LR[i+size-1], RL[i]);
    }
    
    count = 0;
 //   cout<<endl;
	 for(int i=0;i<p;i++ )
	 {
	    if(q[i]=='?')
	        cout<<win[n+1-count]<<endl;
	 
	     else
	         count++;
	    count%=n;
	 }
	 
	return 0;
}
 
