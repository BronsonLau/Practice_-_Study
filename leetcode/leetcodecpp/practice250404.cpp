// 1123. 最深叶节点的最近公共祖先

// 给你一个有根节点 root 的二叉树，返回它 最深的叶节点的最近公共祖先 。

// 叶节点 是二叉树中没有子节点的节点
// 树的根节点的 深度 为 0，如果某一节点的深度为 d，那它的子节点的深度就是 d+1
// 如果我们假定 A 是一组节点 S 的 最近公共祖先，S 中的每个节点都在以 A 为根节点的子树中，且 A 的深度达到此条件下可能的最大值。

// 思路：递归遍历找二叉树最深的叶子节点，返回当前节点和深度。

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    public:
        pair<TreeNode*, int> f(TreeNode* root) {
            if (!root) {
                return {root, 0};
            }
    
            auto left = f(root->left);
            auto right = f(root->right);
    
            if (left.second > right.second) {
                return {left.first, left.second + 1};
            }
            if (left.second < right.second) {
                return {right.first, right.second + 1};
            }
            return {root, left.second + 1};
    
        }
    
        TreeNode* lcaDeepestLeaves(TreeNode* root) {
            return f(root).first;
        }
    };
    
    
// 时间复杂度：O(n)，其中 n 是二叉树的节点数。我们遍历了每个节点一次。
// 空间复杂度：O(h)，其中 h 是二叉树的高度。递归调用栈的空间开销。最坏情况下，二叉树是完全不平衡的，h = n。最好的情况下，h = log(n)。