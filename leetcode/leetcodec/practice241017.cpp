// 684. 冗余连接
// 树可以看成是一个连通且 无环 的 无向 图。

// 给定往一棵 n 个节点 (节点值 1～n) 的树中添加一条边后的图。添加的边的两个顶点包含在 1 到 n 中间，且这条附加的边不属于树中已存在的边。
// 图的信息记录于长度为 n 的二维数组 edges ，edges[i] = [ai, bi] 表示图中在 ai 和 bi 之间存在一条边。

// 请找出一条可以删去的边，删除后可使得剩余部分是一个有着 n 个节点的树。如果有多个答案，则返回数组 edges 中最后出现的那个。

int find(int* parent, int index) { // 找到index的根节点
    if (parent[index] != index) { // 如果index不是根节点
        parent[index] = find(parent, parent[index]); // 路径压缩
    }
    return parent[index]; // 返回根节点
}

void unionSet(int* parent, int index1, int index2) { // 合并index1和index2所在的集合
    parent[find(parent, index1)] = find(parent, index2);  // 将index1的根节点指向index2的根节点
}

int* findRedundantConnection(int** edges, int edgesSize, int* edgesColSize, int* returnSize) {
    int* parent = (int*)malloc(sizeof(int) * (edgesSize + 1)); // 初始化并查集
    for (int i = 1; i <= edgesSize; i++) {
        parent[i] = i;
    }
    for (int i = 0; i < edgesSize; i++) {
        int node1 = edges[i][0], node2 = edges[i][1];
        if (find(parent, node1) != find(parent, node2)) { // 如果node1和node2不在同一个集合中
            unionSet(parent, node1, node2); // 合并node1和node2所在的集合
        } else {
            *returnSize = 2;
            int* ret = (int*)malloc(sizeof(int) * 2);
            ret[0] = node1;
            ret[1] = node2;
            return ret; // 原理：当找到第一个边时不会是多余的，只有到已经连接在同一个根节点上的边时才会是多余的。
        }
    }
    *returnSize = 0;
    return NULL;
    
    
        
}