class Solution {
public:
    int maxScore(vector<int>& card, int k) {
        int n=card.size();
        int sum=0;
        int best;
        for(int i=0;i<k;i++){
            sum+=card[i];
        }
        best=sum;
        for(int i=0;i<k;i++){
            sum-=card[k-1-i];
            sum+=card[n-1-i];
            best=max(sum,best);
        }
        return best;
    }
};