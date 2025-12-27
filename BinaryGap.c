/**
A binary gap within a positive integer N is any maximal sequence of consecutive zeros that is surrounded by ones at both ends in the binary representation of N.

For example, number 9 has binary representation 1001 and contains a binary gap of length 2. The number 529 has binary representation 1000010001 and contains two binary gaps: one of length 4 and one of length 3. The number 20 has binary representation 10100 and contains one binary gap of length 1. The number 15 has binary representation 1111 and has no binary gaps. The number 32 has binary representation 100000 and has no binary gaps.

Write a function:

class Solution { public int solution(int N); }

that, given a positive integer N, returns the length of its longest binary gap. The function should return 0 if N doesn't contain a binary gap.

For example, given N = 1041 the function should return 5, because N has binary representation 10000010001 and so its longest binary gap is of length 5. Given N = 32 the function should return 0, because N has binary representation '100000' and thus no binary gaps.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..2,147,483,647].

*/

#include <stdio.h>
#include <stdbool.h>
int longestBinaryGap(int N);

int main(void) {
    unsigned int num = 0;
    printf("Enter number: to find binary gap\n");
    scanf("%u", &num);
    printf("Longest binary gap: %d\n", longestBinaryGap(num));
    return 0;
}

int longestBinaryGap(int N) {
    int i = 0, j = 0;
    short int gp, lgp = 0;
    bool end = 0;
    for (i; i <= 31; i++) {
        gp = 0;
        if (N & (1U << i)) {
            for (j = i + 1; j <= 31; j++) {
                if (!(N & (0x1 << j))) {
                    gp++;
                    continue;
                } else
                    end = 1;
                i = j - 1;
                break;
            }
            if ((gp > lgp) && end)
                lgp = gp;
            // printf("gp: %d - lgp:%d - end:%d\n", gp,lgp, end);
            end = 0;
        }
    }
    return lgp;
}