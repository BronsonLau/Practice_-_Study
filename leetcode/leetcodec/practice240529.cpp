// 求出现的最大长度的连续相同元素子列
// 不大会
int maximumLength(char* s) 
{
    int answer = -1;
    int len = strlen(s);
    int chs[26][4];
    int chsSize[26];
    int count = 0;
    memset(chs , 0 , sizeof(chs));
    memset(chsSize , 0 , sizeof(chsSize));

    for (int i =0; i<len ;i++)
    {
        count++;
        if( i+1 == len || s[i] != s[i+1])
        {
            int ch = s[i] - 'a'; //
            chs[ch][chsSize[ch]] = count;
            chsSize[ch]++;
            count = 0;
            for (int j = chsSize[ch] - 1 ; j > 0 ;j--)
            {
                if(chs[ch][j] >chs[ch][j-1])
                {
                    int temp = chs[ch][j];
                    chs[ch][j] = chs[ch][j-1];
                    chs[ch][j-1] = temp;
                }
                else break;
            }
            if (chsSize[ch] > 3)
            {
                chsSize[ch]--;
            }
        }
    }
    for(int i =0 ; i < 26 ;i++)
    {
        if(chsSize[i] > 0 &&chs[i][0] > 2)
        {
            answer = fmax(answer , chs[i][0] -2);
        }
        if(chsSize[i] >1 && chs[i][0] >1)
        {
            answer = fmax(answer , fmin(chs[i][0]-1 , chs[i][1]));
        }
        if(chsSize[i] >2 )
        {
            answer = fmax(answer , chs[i][2]);
        }
        
    }
    return answer;
}