#include <stdio.h>
#include <time.h>
long howmuchtimepassed(time_t now, time_t full);
long remainingtime(time_t target);
void fulllenght(time_t fulltime);
int main(void)
{
    time_t rnow = time(NULL);
    time_t target_time = 2147483647;
    howmuchtimepassed(rnow, target_time);

    printf("\n");
    remainingtime(target_time);
    printf("\n");
    fulllenght(target_time);

    return 0;

}
long howmuchtimepassed(time_t now, time_t full)
{
    long days = now / 86400;
    long hours = (now % 86400) / 3600;
    long minutes = (now % 3600) / 60;
    long seconds = now % 60;
    long years = days / 365;
    long remaining_days = days % 365;
    long months = remaining_days / 30; // Approximate month length
    long days_in_current_month = remaining_days % 30;

    printf("Time passed since epoch in seconds: %ld seconds\n", now);
    printf("\n");
    printf("Which is approximately %ld years %ld months %ld days %ld hours %ld minutes %ld seconds.\n",
           years, months, days_in_current_month, hours, minutes, seconds);
    printf("\n");
    printf("With 32bits we can count as high as: %ld signed integers\n", full);
}

long remainingtime(time_t target)
{
    time_t now = time(NULL);
    double remaining = difftime(target, now);
    if (remaining <= 0){
        printf("The target time has already passed, the 32bit limimit has been reached and the 2038 problem has been solevd, or we all went extinct\n");
    }
    long days = remaining / 86400;
    long hours = (remaining - (days * 86400)) / 3600;
    long minutes = (remaining - (days * 86400) - (hours * 3600)) / 60;
    long seconds = remaining - (days * 86400) - (hours * 3600) - (minutes * 60);
        // Print the remaining time
    long years = days / 365;
    long remaining_days = days % 365;
    long months = remaining_days / 30; // Approximate month length
    long days_in_current_month = remaining_days % 30;

    printf("Time remaining until we run out of bits to count integers: %ld years %ld months %ld days %ld hours %ld minutes %ld seconds\n",
           years, months, days_in_current_month, hours, minutes, seconds);

}
void fulllenght(time_t fulltime)
{
        // Total seconds in the given timestamp
    long total_seconds = fulltime;

    // Calculate the total number of days, hours, minutes, and seconds
    long days = total_seconds / 86400;
    long hours = (total_seconds % 86400) / 3600;
    long minutes = (total_seconds % 3600) / 60;
    long seconds = total_seconds % 60;

    // Calculate the number of years
    long years = days / 365;
    long remaining_days = days % 365;

    // Calculate the number of months (approximate)
    long months = remaining_days / 30;
    long days_in_current_month = remaining_days % 30;
        printf("We can track this much time with 32bits of memory: %ld years, %ld months, %ld days, %ld hours, %ld minutes, %ld seconds\n",
            years, months, days_in_current_month, hours, minutes, seconds);
}