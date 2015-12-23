/*
 * John Muchovej
 * COP 3502C-0001
 * Prime Sum
 * Lab 1
 * 8/31/2015
 *
<<<<<<< HEAD
 * Aided David Waters during our Recitation -- not sure how similar ours will be though...
 *
 */

#define MAX_TST 20000
#define MAX_KEY 10000
#define DEBUG 0
#define MIN_PRIME 2

#include <stdio.h>
#include <stdlib.h>

int main(void) {

    int tst = 0,            // # test cases
            pri = 0,        // int bool val for if !/= prime
            pos = 0,        // for loop "indexer"
            num = 0,        // ^
            key = 0;        // index to check
    int *ppNums,            // [pointer] primeNums holder
            *ppSums;        // [pointer] primeSums holder
    int val = MIN_PRIME,    // current number val to check for priminess(? is that a word?)
            tot = 0;        // total # primes

    // setup prime nums holder
    ppNums = malloc(sizeof(int) * MAX_KEY);

    // begin the arduous process of finding the first 10K primes
    while (tot < MAX_KEY) {
        ppNums[tot] = 0;

        // check for primacy
        for (num = MIN_PRIME; num <= val; num++) {
            if (val != num && val % num == 0) {
                pri = 0;
                break;
            }
            pri = 1;
        }

        // have fun if prime
        if (pri) {
            if (DEBUG == 0)
                ppNums[tot++] = val;

            if (DEBUG > 2) {
                ppNums[tot] = val;
                printf("prime @ %04d, val = %d06", tot, ppNums[tot]);
                tot++;
            }
        }

        // move on to next val
        val++;
    }

    // setup prime sums holder
    ppSums = malloc(sizeof(int) * MAX_KEY);

    // additions
    for (num = 0; num < MAX_KEY; num++) {
        ppSums[num] = 0;

        // summations
        for (pos = 0; pos <= num; pos++)
            ppSums[num] += ppNums[pos];

        if (DEBUG > 1)
            printf("prime @ %04d, val = %d06", num, ppSums[num]);
    }

    // don't need this anymore *throws away*
    free(ppNums);


    // how many opportunities will be given to break your machine? :?
    // ^ i.e. # test cases
    scanf("%d", &tst);

    // checking to see if you're cheeky
    if (tst > -1 && tst <= MAX_TST) {
        // now for the part that REALLY matters
        for (num = 0; num < tst; num++) {
            scanf("%d", &key);

            // checking to see if you're cheeky, again
            if (key > -1 && key <= MAX_KEY)
                printf("%d\n", ppSums[key - 1]);
        }
    }

    // just to iterate that I know what free does...
    free(ppSums);

    return 0;

}