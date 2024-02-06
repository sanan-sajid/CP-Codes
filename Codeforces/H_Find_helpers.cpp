#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// a c g t
char dx[4] = {'A', 'C', 'G', 'T'};
vector<string> possibleMove(string &s)
{
    // length of each string is 10
    vector<string> res;
    for (int i = 0; i < s.size(); i++)
    {
        for (int j = 0; j < 4; j++)
        {
            string temp = s;
            temp[i] = dx[j];
            res.push_back(temp);
        }
    }

    return res;
}
int minMutation(string startGene, string endGene, vector<string> &bank)
{
    unordered_set<string> s(bank.begin(), bank.end());
    if (s.find(endGene) == s.end())
        return -1;
    queue<pair<string, int>> q;
    unordered_set<string> vis;
    q.push({startGene, 0});
    vis.insert(startGene);
    while (!q.empty())
    {
        string currString = q.front().first;
        int moves = q.front().second;
        q.pop();
        if (currString == endGene)
            return moves;
        vector<string> posMoves = possibleMove(currString);
        for (auto it : posMoves)
        {
            if (vis.find(it) == vis.end())
            {
                q.push({it, moves + 1});
            }
        }
    }

    return -1;
}

int main()
{

    return 0;
}
