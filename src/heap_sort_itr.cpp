#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    void heapify(vector<int>& nums, int n, int i){
        while (true)
        {
            int maxIdx = i;
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            //如果maxIdx对应值不是最大值，把最大值对应的下标赋值给maxIdx
            if(left < n && nums[left] > nums[maxIdx]) maxIdx = left;
            if(right < n && nums[right] > nums[maxIdx]) maxIdx = right;
            if(maxIdx == i) break;
            swap(nums[i], nums[maxIdx]);
            i = maxIdx;//以便向下调整
        }
    }
    void heapSort(vector<int>& nums){
        int n = nums.size();
        for(int i = n / 2 - 1; i >= 0; --i){//下标从最后一个非叶子节点开始向上递减，构造大堆顶
            heapify(nums, n, i);
        }
        //每一次堆顶最大值与最后一个叶子节点调换，使得数组从小到大
        for(int i = n - 1; i >= 0; --i){
            swap(nums[i], nums[0]);
            heapify(nums, i, 0);//注意此处i,因为剩余需讨论顺序个数恰好等于下标
        }
    }
};
int main(){
    vector<int> nums = {12, 11, 15, 5, 6, 8, 19, 1};
    cout << "原始数组： " << endl;
    for(int x : nums){
        cout << x << " ";
    }
    cout << endl;
    //堆排序后
    Solution sol;
    sol.heapSort(nums);
    cout << "排序结果： "  << endl;
    for(int x : nums){
        cout << x << " ";
    }
    cout << endl;
    return 0; 
}