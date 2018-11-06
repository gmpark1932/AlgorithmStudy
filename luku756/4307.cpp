#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>

//https://www.acmicpc.net/problem/4307
/*
최단시간은, 가운데를 중점으로 개미들이 양쪽으로 걸어가는 것이 최단 시간이다.
이때 걸리는 시간은 가장 가운데에 있는 개미가 떨어지는 시간이다.

최장 시간은, 모든 개미가 한쪽으로 움직일 때 가장 마지막 개미가 떨어지는 시간이다.
개미가 움직이는 것이 1m/s 로 동일하므로, 아무리 충돌해도 이동 경로는 평행하다.(둘이 장소를 바꾼것 뿐이다)
1 거리에서 충돌이 일어날 경우, 둘이 0.5시점에서 충돌하므로 단순히 자리를 바꾼 것과 같다. 그러므로 사실상 충돌이 없는 것과 동일하다.

그렇게 가정하면 모든 개미는 각각의 L 길이의 막대 위에서 움직이는 것과 동일하다.
그러므로 가장 긴 시간은 가장 끝에 가까운 개미가 반대쪽 끝을 향해 움직이는 시간이다.

*/

using namespace std;

int ant[1000001];
int main() {

	int T;
	int N, L;

	cin >> T;
	while(T--) {

		cin >> L >> N;	//입력 받기

		for(int i=0; i<N; i++) {
			cin >> ant[i];
		}

		int cnt = 0;

		int minTime = 0;
		int maxTime = 0;

		for(int i=0; i<N; i++) {
			int mins = min(ant[i], L-ant[i]); //양쪽 끝과의 거리 중 가까운 것. 가장 빨리 떨어지는 경로
			minTime = max(minTime, mins);	//그 중의 최대(시간을 결정)

			int maxs = max(ant[i], L-ant[i]);//양쪽 끝과의 거리 중 가장 먼 것. 가장 느리게 떨어지는 경로
			maxTime = max(maxTime, maxs);//그 중의 최대(시간을 결정)
		}


		cout << minTime << " " << maxTime << endl;
	}

	return 0;
}
