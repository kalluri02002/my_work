#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MIN_SIZE 500
#define NUM_THREADS 5

// Global variables
long global_sum = 0;
int global_max = -1;
pthread_mutex_t mutex;

// Structure to pass data to threads
struct thread_data {
    int *array;
    int start;
    int end;
};

void *process_array(void *arg) {
    struct thread_data *data = (struct thread_data *)arg;
    long local_sum = 0;
    int local_max = data->array[data->start];
    
    // Calculate local sum and max for this thread's portion
    for (int i = data->start; i < data->end; i++) {
        local_sum += data->array[i];
        if (data->array[i] > local_max) {
            local_max = data->array[i];
        }
    }
    
    // Critical section - update global variables
    pthread_mutex_lock(&mutex);
    global_sum += local_sum;
    if (local_max > global_max) {
        global_max = local_max;
    }
    pthread_mutex_unlock(&mutex);
    
    pthread_exit(NULL);
}

int main() {
    int size;
    
    // Get array size from user
    printf("Enter the size of array: ");
    scanf("%d", &size);
    
    if (size < MIN_SIZE) {
        printf("Size must be at least %d\n", MIN_SIZE);
        return 1;
    }
    
    // Initialize mutex
    if (pthread_mutex_init(&mutex, NULL) != 0) {
        perror("Mutex init failed");
        return 1;
    }
    
    // Allocate and initialize array
    int *array = (int *)malloc(size * sizeof(int));
    if (array == NULL) {
        perror("Memory allocation failed");
        return 1;
    }
    
    // Fill array with values (1 to size) for demonstration
    for (int i = 0; i < size; i++) {
        array[i] = i + 1;
    }
    
    pthread_t threads[NUM_THREADS];
    struct thread_data thread_args[NUM_THREADS];
    
    // Calculate range for each thread
    int range = size / NUM_THREADS;
    int remainder = size % NUM_THREADS;
    
    // Create threads in separate loop
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_args[i].array = array;
        thread_args[i].start = i * range;
        thread_args[i].end = (i + 1) * range;
        
        // Add remainder to last thread
        if (i == NUM_THREADS - 1) {
            thread_args[i].end += remainder;
        }
        
        if (pthread_create(&threads[i], NULL, process_array, 
                          (void *)&thread_args[i]) != 0) {
            perror("pthread_create failed");
            free(array);
            return 1;
        }
    }
    
    // Join threads in separate loop
    for (int i = 0; i < NUM_THREADS; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            perror("pthread_join failed");
            free(array);
            return 1;
        }
    }
    
    // Print results
    printf("max = %d Sum = %ld\n", global_max, global_sum);
    
    // Cleanup
    free(array);
    pthread_mutex_destroy(&mutex);
    
    return 0;
}
