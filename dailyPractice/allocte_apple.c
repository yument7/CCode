/**
 * 问题描述： 一堆苹果2520个，分给兄弟6人，首次分配之后，每个分到的苹果数都不相等。然后进行二次分配，老大将分到的苹果的1/8分给老二，
 *           老二拿到后，连同原来的苹果分1/7给老三，老三同理分1/6给老四，依次类推到老六，最后老六连同原来的苹果分1/3给老大，这样，每个
 *           分到的苹果就一样多。求兄弟六人原来持有的苹果数。
 * 
 * 思路：
 *      1. 求出平均数，
 *      2. 平均数等于每人分完之后的苹果数
 *         老大 ： 7/8*S0 + 1/3*S6 = avg
 *         老二 ： 6/7*S1  = avg
 *         老三 ： 5/6*S2 = avg
 *         ......
 *         得出公式 ： avg = S[i] * (8 - i - 1)/(8 - i)  => S[i] = avg * (8 - i)/(8 - i - 1)   老大除外即 i > 0
 *      3. 此时算出的是从哥哥手中分了苹果之后的数据， 所以再根据从哥哥手中分苹果的关系，依次计算出实际情况
 *         s1 + 1/8*s0 = S1   (s0 == S0)
 *         s2 + 1/7*S1 = S2
 *         s3 + 1/6*S2 = S3
 *         ......
 *         推出公式：s[i] = S[i] - 1/(9-i)*S[i-1]  大哥除外即 i > 0 
 **/
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int s[6], S[6], sum = 2520, avg, i;
    avg = sum / 6;

    // 计算分苹果之后的数
    for (i = 1; i < 6; i++)
    {
        S[i] = avg * (8 - i) / (7 - i);
    }
    S[0] = (avg - S[5] / 3) * 8 / 7;  // 计算大哥的苹果

    s[0] = S[0];
    // 计算原先持有
    for (i = 1; i < 6; i++)
    {   
        s[i] =  S[i] - S[i-1]/(9-i);
    }

    // 输出打印
    for(i=0; i < 6; i++){
        printf("s[%d] = %d\n", i, s[i]);
    }
    return 0;
}
 