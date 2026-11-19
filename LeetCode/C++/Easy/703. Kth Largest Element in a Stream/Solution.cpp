class KthLargest {
public:
    int k;
    vector<int> nums;
    KthLargest(int k, vector<int>& nums) {
        this->k=k;
        this->nums=nums;
    }
    
    int add(int val) {
        priority_queue<int> pq;
        for(int& i: nums) pq.push(i);
        nums.emplace_back(val);
        pq.push(val);
        int cnt=k;
        while(cnt>1){
            pq.pop();
            cnt--;
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */