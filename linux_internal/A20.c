#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Structure to pass data to threads
struct thread_data {
    unsigned long int start;
    unsigned long int end;
    unsigned long int result;
};

void *calculate_partial(void *arg) {
    struct thread_data *data = (struct thread_data *)arg;
    unsigned long int partial_result = 1;
    
    // Calculate partial factorial for the given range
    for (unsigned long int i = data->start; i <= data->end; i++) {
        partial_result *= i;
    }
    
    data->result = partial_result;
    pthread_exit(NULL);
}

int main() {
    unsigned long int number;
    pthread_t threads[3];
    struct thread_data thread_args[3];
    
    // Get input from user
    printf("Enter the number: ");
    scanf("%lu", &number);
    
    if (number == 0 || number == 1) {
        printf("Factorial of %lu is 1\n", number);
        return 0;
    }
    
    // Calculate range for each thread
    unsigned long int range = number / 3;
    unsigned long int remainder = number % 3;
    
    // Create threads in a separate loop
    for (int i = 0; i < 3; i++) {
        thread_args[i].start = i * range + 1;
        thread_args[i].end = (i + 1) * range;
        
        // Adjust the last thread's end to include remainder
        if (i == 2) {
            thread_args[i].end += remainder;
        }
        
        if (pthread_create(&threads[i], NULL, calculate_partial, 
                          (void *)&thread_args[i]) != 0) {
            perror("pthread_create failed");
            exit(1);
        }
    }
    
    // Join threads in a separate loop
    for (int i = 0; i < 3; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            perror("pthread_join failed");
            exit(1);
        }
    }
    
    // Calculate final result by multiplying partial results
    unsigned long int final_result = 1;
    for (int i = 0; i < 3; i++) {
        final_result *= thread_args[i].result;
    }
    
    printf("Factorial of %lu is %lu\n", number, final_result);
    
    return 0;
}
