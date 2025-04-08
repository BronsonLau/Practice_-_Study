// 3396. 使数组元素互不相同所需的最少操作次数

// 给你一个整数数组 nums，你需要确保数组中的元素 互不相同 。为此，你可以执行以下操作任意次：

// 从数组的开头移除 3 个元素。如果数组中元素少于 3 个，则移除所有剩余元素。
// 注意：空数组也视作为数组元素互不相同。返回使数组元素互不相同所需的 最少操作次数 。

// 方法1：模拟
class Solution {
    public:
        int minimumOperations(vector<int>& nums) {
            auto checkUnique = [&](int start) {
                unordered_set<int> seen;
                for (int i = start; i < nums.size(); i++) {
                    if (seen.count(nums[i])) {
                        return false;
                    }
                    seen.emplace(nums[i]);
                }
                return true;
            };
    
            int ans = 0;
            for (int i = 0; i < nums.size(); i += 3, ans++) {
                if (checkUnique(i)) {
                    return ans;
                }
            }
            return ans;
        }
    };
    
    // 时间复杂度：O(n^2)，n 表示给定数组 nums 的长度。每次检测剩余的数组中是否存在重复元素，需要时间最多为 O(n)，一共最多需要检测 n 次，因此总的时间为 O(n^2)。
    // 空间复杂度：O(n)，n 表示给定数组 nums 的长度。每次检测数组是否含有重复元素时，需要用哈希表记录已经出现的元素，最多存在 n 个元素需要记录，因此需要的空间为 O(n)。
        
// 方法2:倒序遍历
class Solution {
    public:
        int minimumOperations(vector<int>& nums) {
            vector<bool> seen(128);
            for (int i = nums.size() - 1; i >= 0; i--) {
                if (seen[nums[i]]) {
                    return i / 3 + 1;
                }
                seen[nums[i]] = true;
            }
            return 0;
        }
    };
    
    // 时间复杂度：O(n)，n 表示给定数组 nums 的长度。只需遍历一遍数组即可，需要的时间为 O(n)。
    // 空间复杂度：O(n)，n 表示给定数组 nums 的长度。需要使用哈希表保存已经遍历过的数据，最多需要保存 n 个元素，需要的空间为 O(n)。
    
