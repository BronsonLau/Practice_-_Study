// C语言使用uthash库（哈希表的实现） 的典型案例

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>  //使用 fmin函数
#include <uthash.h>


typedef struct{
        int key;
        int val;
        UT_hash_handle hh;
    } HashItem;

HashItem *hashFineItem(HashItem **obj , int key)
{
    HashItem *pEntry = NULL;
    HASH_FIND_INT(*obj, &key, pEntry);
    return pEntry;
}

bool hashAddItem(HashItem **obj, int key, inr val)
{
    if (hashFindItem(obj, key))
    {
        return false;
    }
    HashItem *pEntry = (HashItem *)malloc(sizeof(HashItem));
    pEntry->key = key;
    pEntry->val = val;
    HASH_ADD_INT(*obj, key, pEntry);

    return true;
}

int hashGetItem(HashItem **obj, int key, int defaultVal)
{
    HashItem *pEntry = hashFindItem(obj, key);
    return pEntry ? pEntry->val : defaultVal;
}

void hashFree(HashItem **obj)
{
    HashItem *current_item, *tmp;
    HASH_ITER(hh, *obj, current_item, tmp)
    {
        HASH_DEL(*obj, current_item);
        free(current_item);
    }
}

int dfs(int i , int j ,int cur , int* nums, int numsSize , const int *andValues, int andValuesSize , HashItem** memo )
{
    int n = numsSize, m = andValuesSize, key = i * m + j;
    if (i == n && j == m) {
        return 0;
    }
    if (i == n || j == m) {
        return INF;
    }
    if (hashFindItem(&memo[key], cur)) {
        return hashGetItem(&memo[key], cur, 0);
    }

    cur &= nums[i];
    if ((cur & andValues[j]) < andValues[j]) {
        return INF;
    }
    int res = dfs(i + 1, j, cur, nums, numsSize, andValues, andValuesSize, memo);
    if (cur == andValues[j]) {
        res = fmin(res, dfs(i + 1, j + 1, INF, nums, numsSize, andValues, andValuesSize, memo) + nums[i]);
    }
    hashAddItem(&memo[key], cur, res);
    return res;
}


int minimumValueSum(int* nums, int numsSize, int* andValues, int andValuesSize) {
    int n = numsSize, m = andValuesSize;
    HashItem *memo[m * n];
    for (int i = 0; i < m * n; i++) {
        memo[i] = NULL;
    }
    int res = dfs(0, 0, INF, nums, numsSize, andValues, andValuesSize, memo);
    for (int i = 0; i < m * n; i++) {
        hashFree(&memo[i]);
    }

    return res < INF ? res : -1;
    
}