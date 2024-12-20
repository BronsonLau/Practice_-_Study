// 2545. 根据第 K 场考试的分数排序
// 中等

// 班里有 m 位学生，共计划组织 n 场考试。给你一个下标从 0 开始、大小为 m x n 的整数矩阵 score ，其中每一行对应一位学生，而 score[i][j] 表示第 i 位学生在第 j 场考试取得的分数。矩阵 score 包含的整数 互不相同 。

// 另给你一个整数 k 。请你按第 k 场考试分数从高到低完成对这些学生（矩阵中的行）的排序。

// 返回排序后的矩阵。

class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        sort(score.begin(), score.end(), [&](const vector<int>& u, const vector<int>& v) {
            return u[k] > v[k];
        });
        return score;
    }
};


// 复杂度分析

// 时间复杂度：O(mlogm)。排序需要的比较次数和行数有关，即 O(mlogm)，每一次比较仅比较第 k 列，时间为 O(1)。如果需要交换比较的两个行，在大部分现代语言中，都可以支持两个行进行无拷贝的交换（即在底层直接更换引用或指针），时间也为 O(1)。

// 空间复杂度：O(logm)，即为排序需要使用的栈空间。


