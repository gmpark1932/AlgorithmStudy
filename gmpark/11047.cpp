#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int N, K;

	cin >> N >> K;

	vector<int> Ki;

	for(int i=0; i<N; i++) {
		int c;
		cin >> c;
		Ki.push_back(c);
	}

	vector<int>::reverse_iterator ritr = Ki.rbegin();
	int result = 0;

	while(K > 0 && ritr != Ki.rend()) {
		if((K / *ritr) > 0) {
			result += (K / (*ritr));
		}
		K %= *ritr;
		ritr++;
		//cout << result << endl;
	}

	cout << result << endl;

	//system("pause");

	return 0;
}
