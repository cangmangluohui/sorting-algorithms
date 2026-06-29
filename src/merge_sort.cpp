#include <iostream>
#include <vector>
using namespace std;
class Solution{
public:
    //两个有序区间合并
    void merge(vector<int>& nums, int l, int mid, int r){
        // 关键第一步：先把当前区间复制到辅助数组temp
        for(int p = l; p <= r; p++){
            temp[p] = nums[p];
        }
        int i = l, j = mid + 1;
        int k =l;//当前下标
        //双指针选小往nums里填
        while (i <= mid && j <= r)
        {
            if(temp[i] <= temp[j]) nums[k++] = temp[i++];
            else nums[k++] = temp[j++];
        }
        //补区间剩余，此处注意右区间剩余则不用动
        while(i <= mid) nums[k++] = temp[i++];
    }
    void mergeSort(vector<int>& nums, int l, int r){
        if(l >= r) return;
        int mid = l + (r - l) / 2;
        mergeSort(nums, l, mid);
        mergeSort(nums, mid + 1, r);
        merge(nums, l, mid, r);
    }
    void sort(vector<int>& nums){
        if(nums.empty()) return;//空数组单独讨论，否则nums.size() - 1越界
        temp.resize(nums.size());//提前开辟空间
        mergeSort(nums, 0, nums.size() - 1);
    }
    void print(vector<int>& nums){
        for(int x : nums){
            cout << x << " ";
        }
        cout << endl;
    }
private:
    vector<int> temp;//创建临时数组,只是临时，最后输出的还是nums
};
int main(){
    vector<int> nums = {8, 3, 5, 4, 7, 6, 2, 1};
    Solution sol;
    cout << "原数组1： " << endl;
    sol.print(nums);
    sol.sort(nums);//排序
    cout << "排序后数组1： " << endl;
    sol.print(nums);
}
