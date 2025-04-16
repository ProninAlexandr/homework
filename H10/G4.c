#include <stdio.h>
#include <string.h>

int main() {
    FILE *in = fopen("input.txt", "r");
    FILE *out = fopen("output.txt", "w");
    if (!in || !out) return 1;

    char s[202], *w1, *w2;
    int c1[26] = {0}, c2[26] = {0}, f = 0;
    
    fgets(s, 202, in);
    s[strcspn(s, "\n")] = 0;
    
    w1 = strtok(s, " ");
    w2 = strtok(NULL, " ");
    if (!w2) return 1;

    for (int i = 0; w1[i]; i++) c1[w1[i]-'a']++;
    for (int i = 0; w2[i]; i++) c2[w2[i]-'a']++;

    for (char c = 'a'; c <= 'z'; c++) {
        if (c1[c-'a'] == 1 && c2[c-'a'] == 1) {
            if (f) fprintf(out, " ");
            fprintf(out, "%c", c);
            f = 1;
        }
    }
    
    fclose(in);
    fclose(out);
    return 0;
}
