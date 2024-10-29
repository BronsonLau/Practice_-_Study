
// 3211. 生成不含相邻零的二进制字符串

// 给你一个正整数 n。

// 如果一个二进制字符串 x 的所有长度为 2 的
// 子字符串
// 中包含 至少 一个 "1"，则称 x 是一个 有效 字符串。

// 返回所有长度为 n 的 有效 字符串，可以以任意顺序排列

void dfs(char* arr, int index, int n, char** res, int* count)
{
    if(index == n)
    {
        res[*count] = strdup(arr);
        (*count)++;
        return;
    }

    if(index == 0 || arr[index-1] == '1')
    {
        arr[index] = '0';
        dfs(arr, index + 1, n, res, count);
    }

    arr[index] = '1';
    dfs(arr, index + 1, n, res, count);
}

char** validStrings(int n, int* returnSize)
{
    char** res = malloc(sizeof(char*) * (1 << n));
    char* arr = malloc(sizeof(char) * (n + 1));
    arr[n] = '\0';
    
    int count = 0;
    
    dfs(arr, 0, n, res, &count);
    free(arr);
    *returnSize = count;
    
    return res;
}

// 条件dfs 和求子集问题可比

// 时间复杂度与斐波那契数列有关

// 空间复杂度 O(n)