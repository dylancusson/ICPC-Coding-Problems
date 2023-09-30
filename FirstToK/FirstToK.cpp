/*	@author [Dylan Cusson](https://github.com/dylancusson)
	@brief Solution to Problem 1, "First-to-K", from the SoCal Regional Competition of ICPC 2022
	@details
	Given a sequence of points won by Alice and Bob, determine all values of k such that Alice would have
	won more games than Bob under the first-to-k rule.
	Both Alice and Bob start with zero points in the beginning of a game. As soon as a player reaches k
	points, that player wins the game, and a new game starts. Neither player wins a game that is interrupted
	by the gym closing before either player reaches k points. Alice wins the match if she wins more games than
	Bob.
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

//Function that simulates who wins in a first-to-k match
bool simulateGames(const string& points, int k) {
	int aliceScore = 0;
	int bobScore = 0;
	int aliceWins = 0;
	int bobWins = 0;

	//Check who won each point and increment their score
	for (char winner : points) {
		if (winner == 'A') {
			aliceScore++;
		}
		else {
			bobScore++;
		}
		//Check if their score is enough to win a first-to-k match
		if (aliceScore >= k || bobScore >= k) {
			if (aliceScore > bobScore) {
				aliceWins++;
			}
			else {
				bobWins++;
			}
			//Reset score when someone wins
			aliceScore = 0;
			bobScore = 0;
		}
	}
	return aliceWins > bobWins;
}
//Vector that tracks the number of possible wins with various k values
vector<int> FindPossibleWins(const string& points) {
	vector<int> possibleWins;
	for (int k = 1; k <= points.length(); k++) {
		if (simulateGames(points, k)) {
			possibleWins.push_back(k);
		}
	}
	return possibleWins;
}

int main() {
	//String that holds who got each point
	string points;
	cin >> points;

	vector<int> possibleWins = FindPossibleWins(points);

	cout << possibleWins.size() << endl;
	if (!possibleWins.empty()) {
		for (int k : possibleWins) {
			cout << k << " ";
		}
		cout << endl;
	}
	return 0;
}
