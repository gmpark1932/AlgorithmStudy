#include<cstdio>
#include<cstdlib>
#include<iostream>

//https://www.acmicpc.net/problem/11047

//다음 동전이 이전 동전의 배수임이 정해져 있으므로, 상위 동전은 무조건 하위 동전 x개라고 정의할 수 있다.
//그러니 뒤에서부터 체크하고 나머지를 체크하면 된다.

using namespace std;

int main() {

	int N, K;
	int A[12];

	cin >> N >> K;	//입력 받기

	for(int i=0; i<N; i++) {
		cin >> A[i];
	}

	int border = N-1;	//뒤에서부터 체크

	int cnt = 0;

	while(border >= 0) {	

		if(A[border] <= K) {

			int local_cnt = K / A[border];
			cnt += local_cnt;
			K = K % A[border];
		}
		border--;
	}
	cout << cnt;

	return 0;
}
