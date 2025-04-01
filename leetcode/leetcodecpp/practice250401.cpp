// 2140. 解决智力问题
// 给你一个下标从 0 开始的二维整数数组 questions ，其中 questions[i] = [pointsi, brainpoweri] 。

// 这个数组表示一场考试里的一系列题目，你需要 按顺序 （也就是从问题 0 开始依次解决），针对每个问题选择 解决 或者 跳过 操作。解决问题 i 将让你 获得  pointsi 的分数，但是你将 无法 解决接下来的 brainpoweri 个问题（即只能跳过接下来的 brainpoweri 个问题）。如果你跳过问题 i ，你可以对下一个问题决定使用哪种操作。

// 比方说，给你 questions = [[3, 2], [4, 3], [4, 4], [2, 5]] ：
// 如果问题 0 被解决了， 那么你可以获得 3 分，但你不能解决问题 1 和 2 。
// 如果你跳过问题 0 ，且解决问题 1 ，你将获得 4 分但是不能解决问题 2 和 3 。
// 请你返回这场考试里你能获得的 最高 分数。

class Solution {
    public:
        long long mostPoints(vector<vector<int>>& questions) {
            // 动态规划
            int n = questions.size();
            vector<long long> dp(n + 1);
            for (int i = n - 1; i >= 0; i--){
                dp[i] = max(dp[i + 1],  questions[i][0] + dp[min(n, i + questions[i][1] + 1)]);
    
            }
            return dp[0];
        }
    };

// 动态规划方法 *反向版本*
// 并且通过反向遍历，可以保证每次计算 dp[i] 时，dp[i + 1] 和 dp[i + questions[i][1] + 1] 都已经计算出来了。
// 并且不需要记录到底是从哪里跳到状态i的

// 时间复杂度：O(n)，其中 n 是数组 questions 的长度。
// 空间复杂度：O(n)。