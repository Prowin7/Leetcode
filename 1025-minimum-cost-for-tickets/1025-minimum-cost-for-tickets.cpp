class Solution {
    vector<int> dp;
    int solve(int curInd, vector<int>& days, vector<int>& costs) {
        if (curInd >= days.size())
            return 0;
        if (dp[curInd] != -1)
            return dp[curInd];
        int option1 = costs[0] + solve(curInd + 1, days, costs);
        int nextInd = curInd;
        while (nextInd < days.size() && days[nextInd] < days[curInd] + 7)
            nextInd++;
        int option2 = costs[1] + solve(nextInd, days, costs);
        nextInd = curInd;
        while (nextInd < days.size() && days[nextInd] < days[curInd] + 30)
            nextInd++;
        int option3 = costs[2] + solve(nextInd, days, costs);
        return dp[curInd] = min(min(option1, option2), option3);
    }

public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        dp = vector<int>(n, -1);
        return solve(0, days, costs);
    }
};