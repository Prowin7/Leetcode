class Solution {
    // Helper function to check if we can finish within 'hour' using speed = k
    bool possible(int k, const vector<int>& dist, double hour) {
        double time = 0.0;
        int n = dist.size();

        for (int i = 0; i < n; ++i) {
            double t = (double)dist[i] / k;

            // For all but last segment, we must take the ceiling
            if (i != n - 1)
                time += ceil(t);
            else
                time += t;

            // Early stop if already exceeding hour
            if (time > hour)
                return false;
        }
        return time <= hour;
    }

public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n = dist.size();

        // Impossible case: need at least (n - 1) full hours to travel n-1 segments
        if (hour <= n - 1) return -1;

        int l = 1;
        int r = 1e7;  // upper bound for speed

        // Binary search with (r - l > 1) condition
        while (r - l > 1) {
            int mid = l + (r - l) / 2;

            if (possible(mid, dist, hour))
                r = mid;   // mid works, try smaller
            else
                l = mid + 1;  // mid too slow, need faster
        }

        // Check both l and r since the loop stops when r - l == 1
        if (possible(l, dist, hour)) return l;
        if (possible(r, dist, hour)) return r;
        return -1;
    }
};
