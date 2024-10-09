
// 3171.找到按位或最接近 K 的子数组

// 给你一个数组 nums 和一个整数 k 。你需要找到 nums 的一个 
// 子数组
//  ，满足子数组中所有元素按位或运算 OR 的值与 k 的 绝对差 尽可能 小 。换言之，你需要选择一个子数组 nums[l..r] 满足 |k - (nums[l] OR nums[l + 1] ... OR nums[r])| 最小。

// 请你返回 最小 的绝对差值。

// 子数组 是数组中连续的 非空 元素序列。

static int cmp(const void *a , const void *b)
{
    return ((int*)b)[0] - ((int*)a)[0];
}
int minimumDifference(int* nums, int numsSize, int k) {
    int bits_pos[31];
    for (int i = 0 ; i < 31 ; i++)
    {
        bits_pos[i] = -1;
    }

    int res = INT_MAX;
    for (int i = 0 ; i < numsSize ; i++)
    {
        for (int j = 0; j < 30; j++)
        {
            if (nums[i] >> j&1)
            {
                bits_pos[j] = i;
            }
        }

        int pos_to_bit[31][2];
        int size = 0;

        for (int j = 0; j <= 30 ; j++)
        {
            if (bits_pos[j] != -1)
            {
                pos_to_bit[size][0] = bits_pos[j];
                pos_to_bit[size][1] = j;
                size++;
            }
        }

        qsort(pos_to_bit , size , sizeof(pos_to_bit[0]) , cmp);
        int val = 0;
        for (int j =0 , p = 0;j < size ; p = j)
        {
            while ( j < size && pos_to_bit[j][0] == pos_to_bit[p][0])
            {
                val |=1 << pos_to_bit[j][1] ;
                j++;
            }

            res = fmin(res , abs(val - k));
        }

    }

    return res;
}