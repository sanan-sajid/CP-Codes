#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to check if player p1 can defeat player p2
bool canDefeat(const vector<int> &p1, const vector<int> &p2)
{
  vector<int> sorted_p1 = p1;
  vector<int> sorted_p2 = p2;

  // Sort both players' power boosters
  sort(sorted_p1.begin(), sorted_p1.end());
  sort(sorted_p2.begin(), sorted_p2.end());

  // Count how many rounds p1 wins
  int win_count = 0;
  for (int i = 0; i < 3; i++)
  {
    if (sorted_p1[i] > sorted_p2[i])
    {
      win_count++;
    }
  }

  // Return true if p1 wins at least 2 rounds
  return win_count >= 2;
}

// Function to count the number of capable players
int countCapablePlayers(int n, const vector<vector<int>> &players)
{
  int capable_count = 0;

  for (int i = 0; i < n; i++)
  {
    bool capable = true;
    for (int j = 0; j < n; j++)
    {
      if (i != j && !canDefeat(players[i], players[j]))
      {
        capable = false;
        break;
      }
    }
    if (capable)
    {
      capable_count++;
    }
  }

  return capable_count;
}

int main()
{
  int n;
  cout << "Enter the number of players: ";
  cin >> n;

  vector<vector<int>> players(n, vector<int>(3));
  cout << "Enter the power boosters for each player:\n";
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      cin >> players[i][j];
    }
  }

  int result = countCapablePlayers(n, players);
  cout << "Number of capable players: " << result << endl;

  return 0;
}