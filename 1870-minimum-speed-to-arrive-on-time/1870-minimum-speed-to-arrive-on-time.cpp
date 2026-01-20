class Solution {
    bool possible(int k, const vector<int>& dist, double hour) {
        double time = 0.0;
        int n = dist.size();

        for (int i = 0; i < n - 1; i++) {
             time += (dist[i] + k - 1) / k;  // integer ceil
            }
        time += (double)dist[n - 1] / k;   // exact fractional time

            return time<=hour;
    }

public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n = dist.size();

        // Impossible case
        if (hour <= n - 1) return -1;

        int lo = 1;
        int hi = 1e7;
        int ans = 0;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            if (possible(mid, dist, hour))
                {
                    ans = mid;
                    hi = mid-1;        // try smaller speed
                }
                
            else
                lo = mid + 1;    // need faster speed
        }

        return ans;
    }
};
