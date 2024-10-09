// 原解不适用哈希表，内存会出现问题
typedef struct {
    int key;
    int val;
    UT_hash_handle hh;
} HashItem; 

HashItem *hashFindItem(HashItem **obj, int key) {
    HashItem *pEntry = NULL;
    HASH_FIND_INT(*obj, &key, pEntry);
    return pEntry;
}

bool hashAddItem(HashItem **obj, int key, int val) {
    if (hashFindItem(obj, key)) {
        return false;
    }
    HashItem *pEntry = (HashItem *)malloc(sizeof(HashItem));
    pEntry->key = key;
    pEntry->val = val;
    HASH_ADD_INT(*obj, key, pEntry);
    return true;
}

bool hashSetItem(HashItem **obj, int key, int val) {
    HashItem *pEntry = hashFindItem(obj, key);
    if (!pEntry) {
        hashAddItem(obj, key, val);
    } else {
        pEntry->val = val;
    }
    return true;
}

int hashGetItem(HashItem **obj, int key, int defaultVal) {
    HashItem *pEntry = hashFindItem(obj, key);
    if (!pEntry) {
        return defaultVal;
    }
    return pEntry->val;
}

void hashFree(HashItem **obj) {
    HashItem *curr = NULL, *tmp = NULL;
    HASH_ITER(hh, *obj, curr, tmp) {
        HASH_DEL(*obj, curr);  
        free(curr);
    }
}

static int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int** findWinners(int** matches, int matchesSize, int* matchesColSize, int* returnSize, int** returnColumnSizes) {
    HashItem *freq = NULL;
    for (int i = 0; i < matchesSize; i++) {
        int winner = matches[i][0], loser = matches[i][1];
        if (!hashFindItem(&freq, winner)) {
            hashAddItem(&freq, winner, 0);
        }
        hashSetItem(&freq, loser, hashGetItem(&freq, loser, 0) + 1);
    }

    int **ans = (int **)malloc(sizeof(int *) * 2); 
    *returnSize = 2;
    *returnColumnSizes = (int *)malloc(sizeof(int) * 2);
    int pos[2];
    memset(pos, 0, sizeof(pos));
    for (int i = 0; i < 2; i++) {
        ans[i] = (int *)malloc(sizeof(int) * HASH_COUNT(freq));
    }
    for (HashItem *pEntry = freq; pEntry; pEntry = pEntry->hh.next) {
        int key = pEntry->key, value = pEntry->val;
        if (value < 2) {
            ans[value][pos[value]++] = key;
        }
    }
  
    (*returnColumnSizes)[0] = pos[0];
    (*returnColumnSizes)[1] = pos[1];
    qsort(ans[0], pos[0], sizeof(int), cmp);
    qsort(ans[1], pos[1], sizeof(int), cmp);
    hashFree(&freq);
    return ans;
}

