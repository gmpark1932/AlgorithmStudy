#include<cstdio>
#include<cstdlib>
#include<iostream>

//https://www.acmicpc.net/problem/11399

//가장 앞 사람의 시간이 N회, 두번째의 시간이 N-1 회, ... 마지막의 시간이 1회 들어간다.
//즉 시간합을 최소로 하기 위해서는 시간이 짧은 순으로 정렬하면 된다.

using namespace std;

int main() {

	int N;
	int P[1002];

	cin >> N;	//입력 받기

	for(int i=0; i<N; i++) {
		cin >> P[i];
	}

	int cnt = 0;

	//역순으로 정렬
	for(int i=0; i<N; i++) {
		for(int j=i; j<N; j++) {
			if(P[i] < P[j]) {
				int tmp = P[i];
				P[i] = P[j];
				P[j] = tmp;
			}
		}
	}

	//가장 긴 시간이 1회 사용되므로, 역순이니 i+1을 곱한다.
	for(int i=0; i<N; i++) {
		cnt += (i+1) * P[i];
	}

	cout << cnt;

	return 0;
}
