#include<iostream>
#include<algorithm>
using namespace std;

#define MAX 10000

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int num[MAX];

	int n; cin>>n;
	for (int i=0; i<n; i++)
		cin>>num[i];

	if(next_permutation(num, num+n))
	{
		for(int i=0; i<n; i++)
			cout<<num[i]<<' ';
		cout<<'\n';
	}
	else
		cout<<-1;

	return 0;
}