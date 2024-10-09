// 数据结构时间测量（Not Able）

#include <uthash.h>

typedef struct {
    int key;
    struct ListNode *val;
    UT_hash_handle hh;
} HashMapItem; 

typedef struct {
    int key;
    UT_hash_handle hh;
} HashSetItem; 

struct ListNode* creatListNode(int val) {
    struct ListNode *obj = (struct ListNode*)malloc(sizeof(struct ListNode));
    obj->val = val;
    obj->next = NULL;
    return obj;
}

HashMapItem *hashMapFindItem(HashMapItem **obj, int key) {
    HashMapItem *pEntry = NULL;
    HASH_FIND_INT(*obj, &key, pEntry);
    return pEntry;
}

struct ListNode* hashMapGetItem(HashMapItem **obj, int key) {
    HashMapItem *pEntry = NULL;
    HASH_FIND_INT(*obj, &key, pEntry);
    if (!pEntry) {
        return NULL;
    } else {
        return pEntry->val;
    }
}

bool hashMapAddItem(HashMapItem **obj, int key, int val) {
    HashMapItem *pEntry = NULL;
    HASH_FIND_INT(*obj, &key, pEntry);
    struct ListNode *node = creatListNode(val);
    if (pEntry) {
        node ->next = pEntry->val;
        pEntry->val = node;
    } else {
        pEntry = (HashMapItem *)malloc(sizeof(HashMapItem));
        pEntry->key = key;
        pEntry->val = node;
        HASH_ADD_INT(*obj, key, pEntry);
    }
    return true;
}

void freeList(struct ListNode *list) {
    while (list) {
        struct ListNode *p = list;
        list = list->next;
        free(p);
    }
}

void hashMapFree(HashMapItem **obj) {
    HashMapItem *curr = NULL, *tmp = NULL;
    HASH_ITER(hh, *obj, curr, tmp) {
        HASH_DEL(*obj, curr);  
        freeList(curr->val);
        free(curr);
    }
}

HashSetItem *hashSetFindItem(HashSetItem **obj, int key) {
    HashSetItem *pEntry = NULL;
    HASH_FIND_INT(*obj, &key, pEntry);
    return pEntry;
} 

void hashSetAddItem(HashSetItem **obj, int key) {
    HashSetItem *pEntry = hashSetFindItem(obj, key);
    if (!pEntry) {
        pEntry = (HashSetItem *)malloc(sizeof(HashSetItem));
        pEntry->key = key;
        HASH_ADD_INT(*obj, key, pEntry);
    }
}

void hashSetFree(HashSetItem **obj) {
    HashSetItem *curr = NULL, *tmp = NULL;
    HASH_ITER(hh, *obj, curr, tmp) {
        HASH_DEL(*obj, curr);  
        free(curr);
    }
}

void dfs(struct TreeNode *node, HashMapItem **graph) {
    if (node == NULL) {
        return;
    }
    struct TreeNode *arr[2] = {node->left, node->right};
    for (int i = 0; i < 2; i++) {
        if (arr[i] != NULL) {
            hashMapAddItem(graph, node->val, arr[i]->val);
            hashMapAddItem(graph, arr[i]->val, node->val);
            dfs(arr[i], graph);
        }
    }
};

typedef struct Pair {
    int node;
    int time;
} Pair;

int amountOfTime(struct TreeNode *root, int start) {
    HashMapItem *graph = NULL;
    dfs(root, &graph);

    int nodeSize = HASH_COUNT(graph)  + 1;
    Pair q[nodeSize];
    int head = 0, tail = 0;
    q[tail].node = start;
    q[tail].time = 0;
    tail++;

    HashSetItem *visited = NULL;
    hashSetAddItem(&visited, start);
    int time = 0;
    while (head != tail) {
        int nodeVal = q[head].node;
        time = q[head].time;
        head++;
        for (struct ListNode *p = hashMapGetItem(&graph, nodeVal); p != NULL; p = p->next) {
            int childVal = p->val;
            if (!hashSetFindItem(&visited, childVal)) {
                int childVal = p->val;
                q[tail].node = childVal;
                q[tail].time = time + 1;
                tail++;
                hashSetAddItem(&visited, childVal);
            }
        }
    }
    hashMapFree(&graph);
    hashSetFree(&visited);
    return time;
}