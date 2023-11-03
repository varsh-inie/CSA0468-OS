#include <stdio.h>

int main() {
    int processes = 4;
    int resources = 3;

    int available[3] = {9, 3, 6};

    int max[4][3] = {
        {3, 2, 2},
        {6, 1, 3},
        {3, 1, 4},
        {4, 2, 2}
    };

    int allocation[4][3] = {
        {1, 0, 0},
        {6, 1, 2},
        {2, 1, 1},
        {0, 0, 2}
    };

    int need[4][3];

    for (int i = 0; i < processes; i++) {
        for (int j = 0; j < resources; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    int finish[4] = {0, 0, 0, 0};
    int safeSequence[4];
    int work[3];

    for (int i = 0; i < resources; i++) {
        work[i] = available[i];
    }

    int count = 0;
    int safe = 0;

    while (count < processes) {
        int found = 0;

        for (int i = 0; i < processes; i++) {
            if (finish[i] == 0) {
                int j;
                for (j = 0; j < resources; j++) {
                    if (need[i][j] > work[j]) {
                        break;
                    }
                }

                if (j == resources) {
                    for (int k = 0; k < resources; k++) {
                        work[k] += allocation[i][k];
                    }

                    safeSequence[count] = i;
                    finish[i] = 1;
                    count++;
                    found = 1;
                }
            }
        }

        if (found == 0) {
            safe = 0;
            break;
        }
    }

    if (count == processes) {
        safe = 1;
    }

    if (safe) {
        printf("System is in a safe state. Safe sequence: ");
        for (int i = 0; i < processes; i++) {
            printf("%d ", safeSequence[i]);
        }
        printf("\n");
    } else {
        printf("System is in an unsafe state.\n");
    }

    return 0;
}
