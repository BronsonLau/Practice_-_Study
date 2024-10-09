// 薄弱点：贪心算法 与 哈希表的操作
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <uthash.h>

typedef struct 
{
    int key;
    int val;
    UT_hash_handle hh; // 哈希表处理可使用的小技巧

}HashItem;

HashItem *hashFindItem(HashItem **object , int key)
{
    HashItem *pEntry = NULL;
    HASH_FIND_INT(*object, &key, pEntry);
    return pEntry;
}

bool hashAddItem(HashItem **object, int key, int val)
{
    if (hashFindItem(object , key))   return false; //如果已经有，不添加
    HashItem *pEntry = (HashItem*)malloc(sizeof(HashItem));
    pEntry -> key = key;
    pEntry -> val = val;
    HASH_ADD_INT(*object , key , pEnrty);
    return true;
}

bool hashSetItem(HashItem **object , int key ,int val)
{
    HashItem *pEntry = hashFindItem(object , key);
    if(!pEntry)
    {
        hashAddItem(object, key, val);
    }
    else
    {
        pEntry->val = val;
    }

    return true;
}

int hashGetItem(HashItem **object , int key ,int defaultVal)
{
    HashItem *pEntry = hashFindItem(object , key);
    if(!pEntry)
    {
        return defaultVal;
    }

    return pEntry->val;
}

void hashFree(HashItem **object)
{
    HashItem *curr = NULL, *tmp = NULL;
    HASH_ITER(hh, *object, curr,tmp);
    {
        HASH_DEL(*object , curr);
        free(curr);
    }
}

int minimumRounds(int* tasks , int tasksSize)
{
    HashItem *cnt = NULL;
    for (int i = 0; i < tasksSize; i++) 
    {
        hashSetItem(&cnt, tasks[i], hashGetItem(&cnt, tasks[i], 0) + 1);
    }
    int res = 0;
    for (HashItem *pEntry = cnt; pEntry; pEntry = pEntry->hh.next) {
        int v = pEntry->val;
        if (v == 1) {
            return -1;
        } else if (v % 3 == 0) {
            res += v / 3;
        } else {
            res += v / 3 + 1;
        }
    }
    hashFree(&cnt);
    return res;

}