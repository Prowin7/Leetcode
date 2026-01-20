class Solution {
    bool possible(int k, const vector<int>& dist, double hour) {
        double time = 0.0;
        int n = dist.size();

        for (int i = 0; i < n; i++) {
            double t = (double)dist[i] / k;

            if (i != n - 1)
                time += ceil(t);
            else
                time += t;

            if (time > hour) return false;
        }
        return true;
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
