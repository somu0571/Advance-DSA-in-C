#include <stdio.h>

int main()
{
    int bucket_size, output_rate;
    int incoming, stored = 0;
    int time;
    printf("Enter bucket capacity: ");
    scanf("%d", &bucket_size);
    printf("Enter output rate: ");
    scanf("%d", &output_rate);
    printf("Enter number of time intervals: ");
    scanf("%d", &time);
    for (int i = 1; i <= time; i++)
    {
        printf("\nEnter incoming packets at time %d: ", i);
        scanf("%d", &incoming);

        printf("Incoming packets: %d\n", incoming);

        if (incoming + stored > bucket_size)
        {
            int dropped = incoming + stored - bucket_size;
            printf("Packets dropped: %d\n", dropped);
            stored = bucket_size;
        }
        else
        {
            stored += incoming;
        }

        printf("Packets in bucket: %d\n", stored);

        if (stored >= output_rate)
        {
            stored -= output_rate;
            printf("Packets transmitted: %d\n", output_rate);
        }
        else
        {
            printf("Packets transmitted: %d\n", stored);
            stored = 0;
        }

        printf("Packets remaining: %d\n", stored);
    }

    return 0;
}

