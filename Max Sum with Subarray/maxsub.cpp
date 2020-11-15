#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
	int n;
    cin>>n;
    vector<ll>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    ll curr=a[0];
    ll total=0;
    int flag=0;
    for(int i=1;i<n;i++){
        if(flag==0){
            if(a[i]>a[i-1])
                curr=a[i];
            else{
                total+=a[i-1];
                curr=a[i];
                flag=1;
            }
        }
        else{
            if(a[i]<a[i-1])
                curr=a[i];
            else{
                total-=a[i-1];
                curr=a[i];
                flag=0;
            }
        }
        
	}
	if(flag==0)
	total+=a[n-1];
	cout<<total<<"\n";

	return 0;
}
