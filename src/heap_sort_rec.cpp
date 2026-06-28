#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    //当前节点下标i，下标0-n-1，
    void heapify(vector<int>& nums, int n, int i){
        int maxIdx = i;//记录当前值最大节点下标，初始为当前节点
        int left = 2 * i + 1;//左子节点下标
        int right = 2 * i + 2;//右子节点下标
        //左节点下标合规，并且对应值大于当前节点值,maxIdx变为left对应下标
        if(left < n && nums[left] > nums[maxIdx]) maxIdx = left;
        //右节点相同
        if(right < n && nums[right] > nums[maxIdx]) maxIdx = right;
        if(maxIdx != i){//说明当前节点值不是最大的
            swap(nums[i], nums[maxIdx]);//节点值更大的上移
            heapify(nums, n, maxIdx);//递归继续向下调整
        }
    }
    //堆排序主程序
    void heapSort(vector<int>& nums){
        int n = nums.size();
        // 从最后一个非叶子节点开始，自底向上建大顶堆
        for(int i = n / 2 - 1; i >= 0; --i){
            heapify(nums, n, i);
        }
        //大顶堆建成后，堆顶元素（最大值）调换到数组末尾，使得数组从小到大输出
        for(int i = n - 1; i >= 0; --i){
            swap(nums[i], nums[0]);// 交换堆顶和末尾元素
            heapify(nums, i, 0);// 对剩下的 i 个元素重新调整堆
        }
    }
};
int main(){
    vector<int> nums = {12, 11, 15, 5, 6, 8, 19, 1};
    //排序前遍历
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