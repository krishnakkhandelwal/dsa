#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int INF = INT_MAX;
int n; // Number of cities
vector<vector<int>> dist; // Distance matrix
vector<vector<int>> dp;

// Recursive function to solve TSP
int tsp(int mask, int pos) {
    if (mask == (1 << n) - 1) {
        return dist[pos][0]; // Return to the starting point
    }

    if (dp[mask][pos] != -1) {
        return dp[mask][pos];
    }

    int ans = INF;

    for (int city = 0; city < n; city++) {
        if ((mask & (1 << city)) == 0) {
            int newAns = dist[pos][city] + tsp(mask | (1 << city), city);
            ans = min(ans, newAns);
        }
    }

    return dp[mask][pos] = ans;
}

int main() {
    cout << "Enter number of cities: ";
    cin >> n;

    dist = vector<vector<int>>(n, vector<int>(n));
    dp = vector<vector<int>>((1 << n), vector<int>(n, -1));

    cout << "Enter distance matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> dist[i][j];

    int result = tsp(1, 0); // Starting from city 0, visited only city 0
    cout << "The minimum cost to visit all cities: " << result << endl;

    return 0;
}
