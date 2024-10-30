// 3216. 交换后字典序最小的字符串

// 给你一个仅由数字组成的字符串 s，在最多交换一次 相邻 且具有相同 奇偶性 的数字后，返回可以得到的
// 字典序最小的字符串
// 。

// 如果两个数字都是奇数或都是偶数，则它们具有相同的奇偶性。例如，5 和 9、2 和 4 奇偶性相同，而 6 和 9 奇偶性不同。

char* getSmallestString(char* s) {
    int l = strlen(s);
    for (int i = 0; i < l - 1; i++)
    {
        if(s[i] > s[i+1] && ((int)s[i]%2) == ((int)s[i+1]%2))
        {
            int temp = s[i];
            s[i] = s[i+1];
            s[i+1] = temp;
            break;
        }
    }

    return s;
}

