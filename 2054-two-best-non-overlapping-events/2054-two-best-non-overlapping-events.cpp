class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();
        
        sort(events.begin(), events.end());

        // suffix array
        vector<int> mx(n);

        mx[n - 1] = events[n - 1][2];

        for (int i = n - 2; i >= 0; i--) {
            mx[i] = max(events[i][2], mx[i + 1]);
        }
        // mx[2] = 2;
        // mx[1] = 3;
        // mx[0] = 3;

        int ans =0;
        for(int i=0;i<n;i++){
            ans = max(ans, events[i][2]);

            // binary search algo

            int l = i+1; // l =1
            int r = n-1; // r = 2
            int idx = -1;
            while(l<=r){
                int mid = l+(r-l)/2;

                if(events[mid][0]>events[i][1]){

                    idx = mid;
                    r = mid-1;
                } else{
                    l = mid+1;
                }
            }

            if(idx!=-1){
                ans = max(ans, events[i][2]+mx[idx]);
            }
        }
        return ans;

    }
};