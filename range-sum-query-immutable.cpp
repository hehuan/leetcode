//https://leetcode.com/problems/range-sum-query-immutable/

class NumArray {
public:
    vector<int> array;
    NumArray(vector<int> &nums) {
        int sum = 0;
        for (vector<int>::iterator iter = nums.begin(); iter != nums.end(); ++iter)
        {
            sum += *iter;
            array.push_back(sum);
        }
    }

    int sumRange(int i, int j) {
        return i==0 ? array[j] : array[j]-array[i-1];
    }
};




// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);
