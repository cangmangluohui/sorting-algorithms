# Sorting Algorithms in C++
本项目包含常见排序算法的 C++ 手写实现，用于数据结构学习

## 环境要求
- GCC / G++
- C++ 11/14/17

## 算法列表
### 1. 堆排序 (Heap Sort)
- **时间复杂度**: O(n log n)
- **空间复杂度**: O(1)
- **特点**: 不稳定排序，利用大顶堆性质。
- **递归和迭代**：递归调用自身继续向下检查，迭代while循环直到当前节点最大值，或者越界break
- [查看代码](src/heap_sort.cpp)

### 2. 桶排序 (Bucket Sort)
- **时间复杂度**: O(n + k)
- **空间复杂度**: O(n + k)
- **特点**: 适用于数据分布均匀的场景。
- [查看代码](src/bucket_sort.cpp)

## 如何运行

编译产物已被忽略，首次运行需手动创建构建目录：

```bash
# 1. 创建并进入构建目录
mkdir -p build && cd build

# 2. 编译堆排序
g++ -std=c++17 ../src/heap_sort.cpp -o heap_sort

# 3. 运行
./heap_sort
```