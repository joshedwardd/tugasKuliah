#include <stdio.h>
#include <stdlib.h>

#define MAX_SKILL 4000

int main() {
    int N;
    if (scanf("%d", &N) != 1) {
        return 1;
    }
    int total_students = 3 * N;
    int *count = (int *)calloc(MAX_SKILL + 1, sizeof(int));
    if (!count) {
        return 1;
    }

    for (int i = 0; i < total_students; ++i) {
        int skill;
        if (scanf("%d", &skill) != 1) {
            free(count);
            return 1;
        }
        count[skill]++;
    }

    int cum = 0;
    int result = 0;
    for (int i = 0; i <= MAX_SKILL; ++i) {
        cum += count[i];
        if (cum >= N + 1) {
            result = i;
            break;
        }
    }

    printf("%d\n", result);

    free(count);
    return 0;
}

