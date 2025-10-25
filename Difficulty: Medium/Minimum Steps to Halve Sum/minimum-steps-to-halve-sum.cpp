class Solution {
public:
    int minOperations(vector<int>& arr) {
        priority_queue<double> pq;   // max-heap
        double sum = 0;
        
        for (auto x : arr) {
            sum += x;
            pq.push(x);
        }
        
        double target = sum / 2.0;
        int cnt = 0;
        
        while (sum > target) {
            double t = pq.top();
            pq.pop();
            
            double half = t / 2.0;
            sum -= half;
            pq.push(half);
            cnt++;
        }
        
        return cnt;
    }
};
