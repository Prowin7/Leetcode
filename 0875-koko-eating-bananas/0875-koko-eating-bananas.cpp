class Solution {
    long long possible(int k, vector<int>& piles){   // FIX 1: return type
        long long cnt = 0;
        int n = piles.size();
        for(int i = 0; i < n; i++){
            cnt += ((long long)piles[i] + k - 1) / k; // unchanged logic
        }
        return cnt;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int lo = 1;
        int hi = INT_MIN;

        for(int i = 0; i < n; i++){
            hi = max(piles[i], hi);
        }

        int ans = 0;
        while(lo <= hi){
            int mid = lo + (hi - lo) / 2;

            if(possible(mid, piles) <= h){
                ans = mid;
                hi = mid - 1;
            }
            else {
                lo = mid + 1;
            }
        }
        return ans;
    }
};
