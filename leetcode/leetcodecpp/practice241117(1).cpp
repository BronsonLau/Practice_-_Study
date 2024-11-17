// 825. 适龄的朋友
// 已解答
// 中等
// 相关标签
// 相关企业
// 在社交媒体网站上有 n 个用户。给你一个整数数组 ages ，其中 ages[i] 是第 i 个用户的年龄。

// 如果下述任意一个条件为真，那么用户 x 将不会向用户 y（x != y）发送好友请求：

// ages[y] <= 0.5 * ages[x] + 7
// ages[y] > ages[x]
// ages[y] > 100 && ages[x] < 100
// 否则，x 将会向 y 发送一条好友请求。

// 注意，如果 x 向 y 发送一条好友请求，y 不必也向 x 发送一条好友请求。另外，用户不会向自己发送好友请求。

// 返回在该社交媒体网站上产生的好友请求总数。

class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        vector<int> cnt(121);
        for (int age: ages) {
            ++cnt[age];
        }
        vector<int> pre(121);
        for (int i = 1; i <= 120; ++i) {
            pre[i] = pre[i - 1] + cnt[i];
        }
        int ans = 0;
        for (int i = 15; i <= 120; ++i) {
            if (cnt[i]) {
                int bound = i * 0.5 + 8;
                ans += cnt[i] * (pre[i] - pre[bound - 1] - 1);
            }
        }
        return ans;
    }
};

// 方法1：由于范围在1-120，采用计数排序的方式，统计每个年龄的人数
//       计算每个年龄段的前缀和，然后遍历每个年龄，计算符合条件的人数
// 时间复杂度：O(n)
// 空间复杂度：O(1)