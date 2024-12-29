#include<iostream>
#include<vector>
using namespace std;

int GCD(int a, int b){
    if(b==0)
        return a;
    else
        return GCD(b, a%b);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int t; cin>>t;
    
	while(t--){
		int n; cin>>n;

		vector<int> arr;
		for(int i=0; i<n; i++) {
			int value; cin>>value;
			arr.push_back(value);
		}

		long long sum=0;
        
		for(int i=0; i<n-1; i++) {
			for(int j=i+1; j<n; j++) {
				sum += GCD(arr[i], arr[j]);
			}
		}
		cout<<sum<<"\n";
	}
    
    return 0;
}