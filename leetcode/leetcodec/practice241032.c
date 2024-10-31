// 3165. 不包含相邻元素的子序列的最大和
// 给你一个整数数组 nums 和一个二维数组 queries，其中 queries[i] = [posi, xi]。

// 对于每个查询 i，首先将 nums[posi] 设置为 xi，然后计算查询 i 的答案，该答案为 nums 中 不包含相邻元素 的 
// 子序列
//  的 最大 和。

// 返回所有查询的答案之和。

// 由于最终答案可能非常大，返回其对 109 + 7 取余 的结果。

// 子序列 是指从另一个数组中删除一些或不删除元素而不改变剩余元素顺序得到的数组。

typedef struct SegNode {
    long long v00, v01, v10, v11;
} SegNode;

SegNode* segNodeCreate() {
    SegNode* node = (SegNode*)malloc(sizeof(SegNode));
    node->v00 = node->v01 = node->v10 = node->v11 = 0;
    return node;
}

void setSegNode(SegNode* node, long long v) {
    node->v00 = node->v01 = node->v10 = 0;
    node->v11 = fmax(v, 0LL);
}

long long bestSegNode(SegNode* node) {
    return node->v11;
}

typedef struct SegTree {
    int n;
    SegNode** tree;
} SegTree;

SegTree* segTreeCreate(int n) {
    SegTree* tree = (SegTree*)malloc(sizeof(SegTree));
    tree->n = n;
    tree->tree = (SegNode**)malloc((n * 4 + 1) * sizeof(SegNode*));
    for (int i = 0; i < n * 4 + 1; i++) {
        tree->tree[i] = segNodeCreate();
    }
    return tree;
}

void freeSegTree(SegTree* tree) {
    for (int i = 0; i <= tree->n * 4; i++) {
        free(tree->tree[i]);
    }
    free(tree->tree);
    free(tree);
}

void initSegTree(SegTree* tree, int* nums) {
    internalInit(tree, nums, 1, 1, tree->n);
}

void updateSegTree(SegTree* tree, int x, int v) {
    internalUpdate(tree, 1, 1, tree->n, x + 1, v);
}

long long querySegTree(SegTree* tree) {
    return bestSegNode(tree->tree[1]);
}

void internalInit(SegTree* tree, int* nums, int x, int l, int r) {
    if (l == r) {
        setSegNode(tree->tree[x], nums[l - 1]);
        return;
    }
    int mid = (l + r) / 2;
    internalInit(tree, nums, x * 2, l, mid);
    internalInit(tree, nums, x * 2 + 1, mid + 1, r);
    pushup(tree, x);
}

void internalUpdate(SegTree* tree, int x, int l, int r, int pos, int v) {
    if (l > pos || r < pos) {
        return;
    }
    if (l == r) {
        setSegNode(tree->tree[x], v);
        return;
    }
    int mid = (l + r) / 2;
    internalUpdate(tree, x * 2, l, mid, pos, v);
    internalUpdate(tree, x * 2 + 1, mid + 1, r, pos, v);
    pushup(tree, x);
}

void pushup(SegTree* tree, int x) {
    int l = x * 2, r = x * 2 + 1;
    tree->tree[x]->v00 = fmax(tree->tree[l]->v00 + tree->tree[r]->v10, tree->tree[l]->v01 + tree->tree[r]->v00);
    tree->tree[x]->v01 = fmax(tree->tree[l]->v00 + tree->tree[r]->v11, tree->tree[l]->v01 + tree->tree[r]->v01);
    tree->tree[x]->v10 = fmax(tree->tree[l]->v10 + tree->tree[r]->v10, tree->tree[l]->v11 + tree->tree[r]->v00);
    tree->tree[x]->v11 = fmax(tree->tree[l]->v10 + tree->tree[r]->v11, tree->tree[l]->v11 + tree->tree[r]->v01);
}

#define MOD 1000000007

int maximumSumSubsequence(int* nums, int numsSize, int** queries, int queriesSize, int* queriesColSize) {
    SegTree* tree = segTreeCreate(numsSize);
    initSegTree(tree, nums);

    long long ans = 0;
    for (int i = 0; i < queriesSize; i++) {
        updateSegTree(tree, queries[i][0], queries[i][1]);
        ans = (ans + querySegTree(tree)) % MOD;
    }
    freeSegTree(tree);
    return (int)ans;
}


// 算法：线段树
