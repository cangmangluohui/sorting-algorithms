#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution{
public:
    void bucketSort(vector<int>& nums, int bucketSize = 3){
        if(nums.empty()) return;
        //找最大最小值，确定值域
        int minVal = nums[0], maxVal = nums[0];
        for(int x : nums){
            minVal = min(x, minVal);
            maxVal = max(x, maxVal);
        }
        //确定桶的数量并初始化桶
        int bucketCnt = (maxVal - minVal) / bucketSize + 1;
        vector<vector<int>> buckets(bucketCnt);
        //将原数组元素对应入桶.此时桶内元素无序。但是后面的桶元素肯定比前面的桶元素大
        for(int x : nums){
            int idx = (x - minVal) / bucketSize;
            buckets[idx].push_back(x);
        }
        //桶内部排序
        int pos = 0;
        for(auto& bucket : buckets){
            sort(bucket.begin(),bucket.end());
            //最后关键一步：回填原数组，注意下标
            for(int num : bucket){
                nums[pos++] = num;
            }
        }
    }
};
int main(){
    vector<int> nums = {10, 5, 6, 4, 1, 3, 2, 9, 7, 8};
    cout << "原始数组： " << endl;
    for(int x : nums){
        cout << x << " ";
    }
    cout << endl;
    Solution sol;
    sol.bucketSort(nums);
    cout << "排序结果： "  << endl;
    for(int x : nums){
        cout << x << " ";
    }
    cout << endl;
    return 0; 
}