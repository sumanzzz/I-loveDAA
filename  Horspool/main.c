/*
# ALGORITHM
ShiftTable(P[0..m – 1])

//Fills the shift table used by Horspool's and Boyer-Moore algorithms
//Input: Pattern P[0..m – 1] and an alphabet of possible characters
//Output: Table[0..size – 1] indexed by the alphabet's characters and
//    filled with shift sizes computed by formula (7.1)

    for i ← 0 to size - 1 do Table[i] ← m
    for j ← 0 to m - 2 do Table[P[j]] ← m - 1 - j
    return Table






# ALGORITHM
HorspoolMatching(P[0..m – 1], T[0..n – 1])

//Implements Horspool's algorithm for string matching
//Input: Pattern P[0..m – 1] and text T[0..n – 1]
//Output: The index of the left end of the first matching substring or –1 if there are no matches

ShiftTable(P[0..m – 1])
i ← m - 1
while i ≤ n - 1 do
    k ← 0
    while k ≤ m - 1 and P[m – 1 – k] = T[i – k] do
        k ← k + 1
    if k = m
        return i – m + 1
    else i ← i + Table[T[i]]
return –1



Time complexity:
Best case: Ω(m)
worst case: O(mn)
Average case : θ(n)
*/






#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 256

int table[TABLE_SIZE];

void shift(char P[], int m) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        table[i] = m;
    }
    for (int i = 0; i < m - 1; i++) {
        table[(unsigned char)P[i]] = m - 1 - i;
    }
}

int horspool(char T[], char P[]) {
    int m = strlen(P);
    int n = strlen(T);

    shift(P, m);

    int i = m - 1;
    while (i < n) {
        int k = 0;
        while (k < m && P[m - 1 - k] == T[i - k]) {
            k++;
        }
        if (k == m) {
            return i - m + 1;
        } else {
            i += table[(unsigned char)T[i]];
        }
    }
    return -1;
}

int main() {
    char T[100], P[100];

    printf("Enter the text:\n");
    gets(T);
    printf("Enter the pattern:\n");
    gets(P);

    int pos = horspool(T, P);

    if (pos == -1) {
        printf("Pattern not found!\n");
        printf("Text: %s\n", T);
        printf("Pattern: %s\n", P);
    } else {
        printf("Pattern found at position: %d\n", pos + 1);
        printf("Text: %s\n", T);
        printf("      ");
        for (int i = 0; i < pos; i++) printf(" ");
        printf("%s\n", P);
    }

    return 0;
}
