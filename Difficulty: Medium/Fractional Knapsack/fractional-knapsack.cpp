class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        vector<pair<double,int>> ratio(n); 

        // store ratio and index
        for (int i = 0; i < n; i++) {
            ratio[i] = { (double)val[i] / wt[i], i };
        }

        // sort by ratio descending
        sort(ratio.rbegin(), ratio.rend());

        double maxValue = 0.0;
        int remaining = capacity;

        for (int i = 0; i < n; i++) {
            int idx = ratio[i].second;
            if (wt[idx] <= remaining) {
                // take whole item
                maxValue += val[idx];
                remaining -= wt[idx];
            } else {
                // take fraction
                maxValue += ratio[i].first * remaining;
                break;
            }
        }

        return maxValue;
    }
};
