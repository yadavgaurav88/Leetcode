class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int totalSum = 0;
        for (int num : nums)
            totalSum += num;

        int leftSum = 0;
        vector<int> answer;

        for (int num : nums) {
            totalSum -= num;                     // rightSum
            answer.push_back(abs(leftSum - totalSum));
            leftSum += num;
        }

        return answer;
    }
};