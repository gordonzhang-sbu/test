#include <stdio.h>
#include <limits.h>

int main(void)
{
   printf("Type         Size (bytes)    Min Value                Max Value\n");
   printf("------------------------------------------------------------------\n");

   printf("char         %zu              %d                        %d\n",
          sizeof(char), CHAR_MIN, CHAR_MAX);

   printf("short int    %zu              %d                    %d\n",
          sizeof(short), SHRT_MIN, SHRT_MAX);

   printf("int          %zu              %d               %d\n",
          sizeof(int), INT_MIN, INT_MAX);

   printf("long int     %zu              %ld        %ld\n",
          sizeof(long), LONG_MIN, LONG_MAX);

   printf("long long    %zu              %lld   %lld\n",
          sizeof(long long), LLONG_MIN, LLONG_MAX);

   return 0;
}
