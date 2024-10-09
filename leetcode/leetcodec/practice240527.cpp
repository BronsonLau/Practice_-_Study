int* missingRolls(int* rolls, int rollsSize, int mean, int n, int* returnSize){
    int m = rollsSize;
    int sum = mean * (n + m);
    int missingSum = sum;
    for (int i = 0; i < m; i++) {
        missingSum -= rolls[i];
    }

    if (missingSum < n || missingSum > 6 * n) {
        *returnSize = 0;
        return NULL;
    }

    int quotient = missingSum / n, remainder = missingSum % n;  // 此处思路优于个人原本完成的代码，可以省去一个循环的步骤
    int * missing = (int *)malloc(sizeof(int) * n); // 防止指针一直指在NULL上没法赋值
    for (int i = 0; i < n; i++) {
        missing[i] = quotient + (i < remainder ? 1 : 0);
    }
    *returnSize = n; // 和最后的输出数量有关，需要格外注意，否则会导致直接输出为0
    return missing;
}

