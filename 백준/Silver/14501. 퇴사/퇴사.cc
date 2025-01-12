#include <iostream>
using namespace std;

int n;
int T[15], P[15];
int res[15];

void Dp(){
	int sum;
	for(int i=n-1; i>=0; i--){
		sum = i+T[i];
		if(sum > n){
			res[i] = res[i+1];
		}
		else {
			res[i] = max(res[i+1], res[sum]+P[i]);
		}
	}
}

int main() {
    cin>>n;
	for (int i=0; i<n; i++)
		cin>>T[i]>>P[i];
    
	Dp();
	
	cout <<res[0]<<'\n';
	return 0;
}