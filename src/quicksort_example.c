#include <stdio.h>
#include <stdlib.h>

// 定义结构体
typedef struct {
    int range;
} Element;

// 快速排序的分区函数
int partition(Element arr[], int low, int high) {
    int pivot = arr[high].range; // 选择最后一个元素作为基准
    int i = (low - 1);          // 指向小于基准的区域的末尾

    for (int j = low; j <= high - 1; j++) {
        if (arr[j].range < pivot) {
            i++;
            // 交换 arr[i] 和 arr[j]
            Element temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    // 交换 arr[i+1] 和 arr[high]（基准）
    Element temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

// 快速排序主函数
void quickSort(Element arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // 获取分区点
        quickSort(arr, low, pi - 1);        // 递归排序左子数组
        quickSort(arr, pi + 1, high);       // 递归排序右子数组
    }
}

int main() {
    const int SIZE = 800;
    Element elements[SIZE];

    // 初始化数组，range 从 800 倒序到 1
    for (int i = 0; i < SIZE; i++) {
        elements[i].range = SIZE - i;
    }

    // 打印排序前的数组（前10个元素）
    printf("Before sorting (first 10 elements):\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", elements[i].range);
    }
    printf("\n");

    // 调用快速排序
    quickSort(elements, 0, SIZE - 1);

    // 打印排序后的数组（前10个元素）
    printf("After sorting (first 10 elements):\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", elements[i].range);
    }
    printf("\n");

    return 0;
}
