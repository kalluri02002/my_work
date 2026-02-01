#include <stdio.h>
#include <stdlib.h>

void sortRowsByAverage(float data[][10], int rows, int columns[], float averages[]) {
    for (int i = 0; i < rows - 1; i++) {
        for (int j = i + 1; j < rows; j++) {
            if (averages[i] > averages[j]) {
                // Swap averages
                float tempAvg = averages[i];
                averages[i] = averages[j];
                averages[j] = tempAvg;

                // Swap row data
                float tempRow[10];
                int tempCols = columns[i];

                for (int k = 0; k < columns[i]; k++) {
                    tempRow[k] = data[i][k];
                }

                for (int k = 0; k < columns[j]; k++) {
                    data[i][k] = data[j][k];
                }

                for (int k = 0; k < tempCols; k++) {
                    data[j][k] = tempRow[k];
                }

                // Swap column sizes
                columns[i] = columns[j];
                columns[j] = tempCols;
            }
        }
    }
}

int main() {
    int rows;

    // Input number of rows
    //printf("Enter the number of rows: ");
    scanf("%d", &rows);

    float data[rows][10]; // Adjust based on maximum column size
    int columns[rows];
    float averages[rows];

    // Input column lengths for all rows at once
    //printf("Enter the number of columns for each row: ");
    for (int i = 0; i < rows; i++) {
        scanf("%d", &columns[i]);
    }

    // Input data for all rows
   // printf("Enter all row elements separated by spaces:\n");
    for (int i = 0; i < rows; i++) {
        printf("Row[%d]: ", i);
        for (int j = 0; j < columns[i]; j++) {
            scanf("%f", &data[i][j]);
        }
    }

    // Calculate averages for each row
    for (int i = 0; i < rows; i++) {
        float sum = 0;
        for (int j = 0; j < columns[i]; j++) {
            sum += data[i][j];
        }
        averages[i] = sum / columns[i];
    }

    // Before sorting output
    printf("\nBefore sorting output is:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns[i]; j++) {
            printf("%0.6f ", data[i][j]);
        }
        printf("%0.6f\n", averages[i]);
    }

    // Sorting rows based on averages
    sortRowsByAverage(data, rows, columns, averages);

    // After sorting output
    printf("\nAfter sorting output based on average is:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns[i]; j++) {
            printf("%0.6f ", data[i][j]);
        }
        printf("%0.6f\n", averages[i]);
    }

    return 0;
}
