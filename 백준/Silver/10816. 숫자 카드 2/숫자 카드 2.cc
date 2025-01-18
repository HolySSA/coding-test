#include <iostream>
#include <algorithm>

using namespace std;

int arr[500002];
int N, M, card;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
    
	cin >> N;
	for (int i=0; i<N; i++) {
		cin >> card;
		arr[i] = card;
	}
    
	sort(arr, arr + N); // 오름차순 정렬

	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> card;
        //이분 탐색
        //lower_bound(,,s)의 결과 : s 이상의 값이 처음 나타나는 위치
        //upper_bound(,,s)의 결과 : s를 초과하는 값이 처음 나타나는 위치
        //따라서 오름차순으로 정렬된 arr에서 card값이 입력되면 갯수가 나오게 된다
		cout << upper_bound(arr, arr + N, card) - lower_bound(arr, arr + N, card)<<" ";
	}
}