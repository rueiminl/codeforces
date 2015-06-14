#include <iostream>
#include <map>
#include <vector>
using namespace std;

vector<int> sol(vector<int>& scores) {
	multimap<int, int, greater<int>> sorted;
	for (size_t i = 0; i < scores.size(); i++) {
		sorted.insert(make_pair(scores[i], i));
	}
	vector<int> ranks(scores.size());
	auto it = sorted.begin();
	int rank = 1;
	int count = 1;
	ranks[it->second] = rank;
	int score = it->first;
	it++;
	while (it != sorted.end()) {
		count++;
		if (it->first != score) {
			rank = count;
			score = it->first;
		}
		ranks[it->second] = rank;
		it++;
	}
	return ranks;
}

int main() {
	int N;
	cin >> N;
	vector<int> scores(N);
	for (int i = 0; i < N; i++)
		cin >> scores[i];
	auto ranks = sol(scores);
	for (auto rank : ranks)
		cout << rank << " ";
	return 0;
}
