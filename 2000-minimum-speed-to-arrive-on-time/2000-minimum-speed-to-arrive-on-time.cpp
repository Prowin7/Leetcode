class Solution {
    bool possible(int speed, vector<int>& dist, double hour) {
        double time = 0.0;
        int n = dist.size();

        for (int i = 0; i < n; i++) {
            double t = (double)dist[i] / speed;

            // For all but the last segment, round up to next integer hour
            if (i != n - 1)
                time += ceil(t);
            else
                time += t; // last segment can be fractional
        }

        return time <= hour;
    }

public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int left = 1, right = 1e7;
        int ans = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (possible(mid, dist, hour)) {
                ans = mid;         // mid works, try smaller speed
                right = mid - 1;
            } else {
                left = mid + 1;    // mid too slow, need higher speed
            }
        }

        return ans;
    }
};
