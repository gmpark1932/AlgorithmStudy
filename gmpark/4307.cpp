#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int T;
	cin >> T;
	vector<int> ants;
	for(int t=0; t<T; t++) {
		int L, N;
		cin >> L >> N;

		ants.clear();
		for(int i=0; i<N; i++) {
			int p;
			cin >> p;
			ants.push_back(p);
		}

		int min_time, max_time;
		
		int temp_max = 0;
		int left_ant = L;
		int right_ant = 0;
		for(vector<int>::iterator itr = ants.begin(); itr!=ants.end(); itr++) {
			int min_fall = min(*itr, L-*itr);
			if(temp_max < min_fall) temp_max = min_fall;

			if(left_ant > *itr) left_ant = *itr;
			if(right_ant < *itr) right_ant = *itr;
		}
		min_time = temp_max;

		max_time = max(L-left_ant, right_ant);

		cout << min_time << " " << max_time << endl;
	}


	return 0;
}
