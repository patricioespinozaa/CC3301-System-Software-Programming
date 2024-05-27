#include <string.h>

int strCmp(char *s1, char *s2) {
    char c1;
    char c2;

    for (;;) {
        // We must ignore uppercase
        c1 = *s1; 
        c2 = *s2; 
        // If c1 is uppercase, convert it to lowercase
        if (c1 >= 'A' && c1 <= 'Z') {
            c1 = c1 + ('a' - 'A');
        }
        // If c2 is uppercase, convert it to lowercase
        if (c2 >= 'A' && c2 <= 'Z') {
            c2 = c2 + ('a' - 'A');
        }
        // If we reach the end of the string, break the loop
        if (c1 == 0) 
            break;
        // If the characters are different, break the loop
        if (c1 != c2)
            break;

        s1++;
        s2++;
    }
    // Return the difference between the characters
    // If the characters are the same, the difference will be 0
    // If the characters are different, the difference will be the difference between the characters
    return c1 - c2; 
}

void sort(char **a, int n) {
    char **ult = &a[n-1];                           // Pointer to the last element of the array
    char **p = a;                                   // Pointer to the first element of the array
    while (p < ult) {                               // While the pointer to the first element is less than the pointer to the last element
        // Start of the part that should change

        int t1 = strCmp(p[0], p[1]);                // Compare the two strings

        // End of the part that should change
        if (t1 <= 0) {                              // If the first string is less than or equal to the second string
            p++;                                    // Move the pointer to the next element
        } else {                                    // If the first string is greater than the second string
            char *tmp = p[0];                       // Swap the strings
            p[0] = p[1];
            p[1] = tmp;
            p = a;
        }
    }
}
