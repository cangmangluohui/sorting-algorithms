//单向Lomuto和双向Hoare
#include <iostream>
#include <vector>
#include <utility>
using namespace std;
class SolutionLomuto
{
public:
    //partitionLomuto()函数可与quicksort合并
    int partitionLomuto(vector<int>& nums, int l, int r){
        int pivot = nums[r];//基准定为最后一个元素
        int pos = l;
        for(int i = l; i < r; ++i){
            if(nums[i] <= pivot){
                swap(nums[i], nums[pos]);// 将较小元素交换到左侧区域,pos处为界限
                pos++;//先交换，然后再加
            } 
        }
        swap(nums[pos], nums[r]);// 将基准元素放到正确的位置
        return pos;
    }
    void quickSort(vector<int>& nums, int l, int r){//单向递归排序
        if(l >= r) return;
        int pos = partitionLomuto(nums, l , r);
        quickSort(nums, l, pos - 1);// 递归排序左半部分
        quickSort(nums, pos + 1, r);// 递归排序右半部分
    }
    void sort(vector<int>& nums){
        int n = nums.size();
        quickSort(nums, 0, n - 1);
    }
    void print(vector<int>& nums){//打印
        for(int x : nums){
            cout << x << " ";
        }
        cout << endl;
    }
};
class SolutionHoare
{
public:
    void quickSort(vector<int>& nums, int l, int r){
        if(l >= r) return;
        int mid = l + (r - l) / 2;//防止溢出
        int pivot = nums[mid];//取中间元素为基准，左右双指针向中间逼近，相遇时结束

        int i = l, j = r;
        while (i <= j)
        {
            while(nums[i] < pivot) i++;//必须是while，一直找，找到不合适的进入if调换顺序
            while(nums[j] > pivot) j--;//不能写等于号，防止越界访问
            //调换顺序
            if(i <= j){
                swap(nums[i], nums[j]);
                i++;j--;
            }
        }
        //此时必然有i > j ,划分区间 [l,j]  [i,r]
        quickSort(nums, l, j);
        quickSort(nums, i, r);
    }
    void sort(vector<int>& nums){
        int n = nums.size();
        quickSort(nums, 0, n - 1);
    }
    void print(vector<int>& nums){
        for(int x : nums){
            cout << x << " ";
        }
        cout << endl;
    }
};
int main(){
    vector<int> nums1 = {5, 2, 9, 3, 7, 6, 1, 8, 4};
    vector<int> nums2 = {5, 2, 9, 3, 7, 6, 1, 8, 4};
    //单向lomuto
    SolutionLomuto sol1;
    cout << "原数组1： " << endl;
    sol1.print(nums1);
    sol1.sort(nums1);//排序
    cout << "排序后数组1： " << endl;
    sol1.print(nums1);
    //双向hoare
    SolutionHoare sol2;
    cout << "原数组2： " << endl;
    sol2.print(nums2);
    sol2.sort(nums2);//排序
    cout << "排序后数组2： " << endl;
    sol2.print(nums2);
}