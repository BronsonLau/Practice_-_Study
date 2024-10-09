// 下方注释掉的函数存在 逻辑问题 和 过于复杂的问题
// 逻辑问题在于 前后数组的起始点是不一样的，导致在有些情况下会出现少算的情况
// 过于复杂在于 保存后使用了mergesort，多此一举；且有副函数的情况下不如先算出原本的顾客数之后再进行补充
#include <stdio.h>
#include <stdlib.h>

// void MergeSort(int* a, int begin, int end, int* tmp);

// void _MergeSort(int* a, int begin, int end, int* tmp) {
//     if (begin >= end)
//         return;

//     int mid = (begin + end) / 2;

//     _MergeSort(a, begin, mid, tmp);
//     _MergeSort(a, mid + 1, end, tmp);

//     int i = begin, j = mid + 1, k = begin;

//     while (i <= mid && j <= end) {
//         if (a[i] <= a[j])
//             tmp[k++] = a[i++];
//         else
//             tmp[k++] = a[j++];
//     }

//     while (i <= mid)
//         tmp[k++] = a[i++];
//     while (j <= end)
//         tmp[k++] = a[j++];

//     for (int p = begin; p <= end; ++p)
//         a[p] = tmp[p];
// }

// void MergeSort(int* a, int begin, int end, int* tmp) {
//     _MergeSort(a, begin, end, tmp);
// }

// int subfunction(int* customers, int customersSize, int* grumpy, int grumpySize) {
//     int count = 0;
//     for (int i = 0; i < customersSize; i++) {
//         if (!grumpy[i]) {
//             count += customers[i];
//         }
//     }
//     return count;
// }

// int maxSatisfied(int* customers, int customersSize, int* grumpy, int grumpySize, int minutes) {
//     int n = customersSize;
//     int* saving = (int*)malloc(sizeof(int) * (n - minutes + 1));
//     if (saving == NULL) {
//         printf("分配内存失败\n");
//         exit(-1);
//     }

//     for (int j = i; j < i + minutes && j < n; j++) {
//         int* temp_grumpy = (int*)malloc(sizeof(int) * n);
//         if (temp_grumpy == NULL) {
//             printf("分配内存失败\n");
//             exit(-1);
//         }
//         for (int k = 0; k < n; k++) {
//             temp_grumpy[k] = grumpy[k];
//         }
//         for (int k = j; k < j + minutes; k++) {
//             temp_grumpy[k] = 0;
//         }
//         saving[j] = subfunction(customers, customersSize, temp_grumpy, grumpySize);
//         free(temp_grumpy);
//     }

//     MergeSort(saving, 0, n - minutes, saving);
//     int maxSatisfiedCustomers = saving[n - minutes];
//     free(saving);
//     return maxSatisfiedCustomers;
// }

int maxSatisfied(int* customers, int customersSize, int* grumpy, int grumpySize, int minutes) {
    int n = customersSize;
    int totalSatisfied = 0; 

    for (int i = 0; i < n; i++) {
        if (grumpy[i] == 0) { 
            totalSatisfied += customers[i]; 
        }
    }

    int maxAdditionalSatisfied = 0; 

    for (int i = 0; i <= n - minutes; i++) {
        int additionalSatisfied = 0;
        for (int j = i; j < i + minutes; j++) { 
            if (grumpy[j] == 1) { 
                additionalSatisfied += customers[j]; 
            }
        }
        maxAdditionalSatisfied = maxAdditionalSatisfied < additionalSatisfied ? additionalSatisfied : maxAdditionalSatisfied; 
    }

    return totalSatisfied + maxAdditionalSatisfied; 
}


int main() {
    int customers[] = {4, 10, 10};
    int grumpy[] = {1, 1, 0};
    int minutes = 2;
    int result = maxSatisfied(customers, sizeof(customers) / sizeof(customers[0]), grumpy, sizeof(grumpy) / sizeof(grumpy[0]), minutes);
    printf("%d", result);
    return 0;
}
