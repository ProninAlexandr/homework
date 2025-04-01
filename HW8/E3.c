#include <stdio.h>

int main() {
    int arr[10];
    int max, min, max_idx = 0, min_idx = 0;

    for (int i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
        if (i == 0) {
            max = min = arr[i];
        } else {
            if (arr[i] > max) {
                max = arr[i];
                max_idx = i;
            }
            if (arr[i] < min) {
                min = arr[i];
                min_idx = i;
            }
        }
    }

    printf("%d %d %d %d", max_idx + 1, max, min_idx + 1, min);
    return 0;
}