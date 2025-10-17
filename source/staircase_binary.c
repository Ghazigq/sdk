#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// 辅助函数：计算阶梯值
int staircase_size(int n) {
  static int pow_arr[] = {-1, 1, 4, 27, 256, 3125, 46656, 823543, 16777216, 387420489};
  static int arr_size  = sizeof(pow_arr) / sizeof(pow_arr[0]);

  // 遍历数组，查找第一个大于或等于n的元素
  for (int i = 1; i < arr_size; i++) {
    if (pow_arr[i] >= n) return i;  // 找到后返回下标
  }

  // 如果没有找到，返回数组的大小
  return arr_size;
}

// 阶梯式二分法
int staircase_binary_search(int arr[], int n, int target, int staircase) {
  int left = 0, right = n - 1;

  if (n <= 0) return -1;

  // 阶梯式二分法
  while (left <= right) {
    // 计算每个阶梯选择的元素个数
    int remaining = right - left + 1;
    staircase     = remaining < staircase ? remaining : staircase;
    int step_size = remaining / staircase;  // 计算步长

    // 在当前范围内选取staircase个元素进行比较
    for (int i = 0; i < staircase - 1; i++) {
      int index     = left + i * step_size;
      int index_end = (i == staircase - 2) ? right : (index + step_size);

      if (target == arr[index]) return index;
      if (target == arr[index_end]) return index_end;
      if (target > arr[index] && target < arr[index_end]) {
        left  = index;
        right = index_end;
        break;
      }
    }
  }

  return -1;
}