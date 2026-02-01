#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <time.h>
#include <unistd.h>

volatile sig_atomic_t alarm_triggered = 0;

void alarm_handler(int sig) {
    alarm_triggered = 1;
}

int validate_time(int hours, int minutes) {
    return (hours >= 0 && hours <= 23 && minutes >= 0 && minutes <= 59);
}

time_t calculate_time_difference(int target_hours, int target_minutes, struct tm *target_date) {
    time_t now;
    struct tm *current_time;
    
    time(&now);
    current_time = localtime(&now);
    
    target_date->tm_hour = target_hours;
    target_date->tm_min = target_minutes;
    target_date->tm_sec = 0;
    
    time_t target_time = mktime(target_date);
    double diff = difftime(target_time, now);
    
    return (diff > 0) ? (time_t)diff : -1;
}

int main(int argc, char *argv[]) {
    struct sigaction sa;
    struct tm target_date;
    time_t now;
    int hours, minutes;
    time_t seconds_to_alarm;

    // Check command line arguments
    if (argc < 2) {
        printf("Error: No arguments passed\nUsage: ./alarm <hh:mm> [dd/mm/yy]\n");
        return 1;
    }

    // Parse time
    if (sscanf(argv[1], "%d:%d", &hours, &minutes) != 2 || !validate_time(hours, minutes)) {
        printf("Error: Invalid time\n");
        return 1;
    }

    // Get current time
    time(&now);
    target_date = *localtime(&now);

    // Parse date if provided
    if (argc > 2) {
        int day, month, year;
        if (sscanf(argv[2], "%d/%d/%d", &day, &month, &year) == 3) {
            target_date.tm_mday = day;
            target_date.tm_mon = month - 1;
            target_date.tm_year = year + 100; // Assuming 20xx years
        }
    }

    // Calculate time difference
    seconds_to_alarm = calculate_time_difference(hours, minutes, &target_date);
    if (seconds_to_alarm == -1) {
        printf("Error: Time is in the past\n");
        return 1;
    }

    // Set up signal handler
    sa.sa_handler = alarm_handler;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGALRM, &sa, NULL);

    // Set initial alarm
    printf("Set alarm for %02d:%02d on %02d/%02d/%02d\n", 
           hours, minutes, 
           target_date.tm_mday, target_date.tm_mon + 1, target_date.tm_year + 1900);
    
    alarm(seconds_to_alarm);

    while (1) {
        pause(); // Wait for signal

        if (alarm_triggered) {
            alarm_triggered = 0;
            
            printf("\nWake-up...Alarm..!!\n");
            printf("1. Snooze    2. Exit\n");
            
            int choice;
            scanf("%d", &choice);

            if (choice == 2) {
                printf("Exiting...\n");
                return 0;
            }
            else if (choice == 1) {
                int snooze_time;
                printf("Enter snooze time in minutes: ");
                if (scanf("%d", &snooze_time) != 1 || snooze_time <= 0) {
                    snooze_time = 1; // Default to 1 minute
                    printf("Invalid input, using default 1 minute\n");
                }
                alarm(snooze_time * 60); // Convert to seconds
            }
        }
    }

    return 0;
}