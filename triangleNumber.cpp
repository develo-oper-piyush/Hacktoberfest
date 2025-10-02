class Solution {
public:
    int BS(vector<int> &arr, int low, int high, int target){
        int ans = -1;
        while (low <= high){
            int mid = low + (high - low)/2;
            if (arr[mid] < target){
                ans = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return ans;
    }

    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0;

        sort(nums.begin(), nums.end());

        int cnt = 0;

        for (int i = 0; i < n; i++){
            if (nums[i] == 0) continue;

            for (int j = i + 1; j < n; j++){
                int sum = nums[i] + nums[j];

                int k = BS(nums, j+1, n-1, sum);

                if (k != -1) cnt += (k-j);
            }
        }
        return cnt;
    }
};
