class Solution {
public:
    const int M=1e9+7;
    int numOfSubarrays(vector<int>& arr) {
        //brute Tc-O(n3)
        // int n = arr.size();
        // int count = 0;
        
        // for (int i = 0; i < n; i++) {
        //     for (int j = i; j < n; j++) {
        //         int sum = 0;
        //         for (int k = i; k <= j; k++) {
        //             sum += arr[k];
        //         }
        //         if (sum % 2 != 0) {
        //             count++;
        //         }
        //     }
        // }
        // return count % M;
        //better Tc-O(n2)
        int n = arr.size();
        int count = 0;
        
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += arr[j];
                if (sum % 2 != 0) {
                    count = (count+1)%M;
                }
            }
        }
        
        return count % M;
    }
};