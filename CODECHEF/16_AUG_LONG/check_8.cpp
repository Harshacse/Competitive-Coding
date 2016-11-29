#include "new_5.cpp"
#include "8.cpp"
#include <iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;

int main()
{
	srand(time(NULL));
	int t=1;
	while(t--)
	{
		node *head = NULL;
	    int i,n,bits[16];    
	    long ans;
	    n = rand()%100+1;
	    long max[n],arr[n];
	    for(i=0;i<n;i++)
	        arr[i] = rand()%32768;
	    pre_handle(arr,n);
	    ans = 0;
	    head = insertnode(head,arr[0],0);
	    for(i=1;i<n;i++)
	    {
	        calculate(head,arr[i],&ans,i,n);
	        head = insertnode(head,arr[i],i);
	        int_bin(arr[i],bits);
	    }
	    long ans1;
	    ans1 = temp(arr,n);
	    if(ans!=ans1)
	    	cout<<"Error found"<<endl;
	    else
	    	cout<<"working"<<endl;
	}
}