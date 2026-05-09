#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
    int userInput = 0;
    int size = 0;


    printf("1 (square), 2 (triangle), or 3 (pyramid)\n");
    scanf("%d", &userInput);
    printf("You want %d\n", userInput);

    printf("Enter size\n");
    scanf("%d", &size);

    if (userInput == 1){
        for (int i=0; i<size; i++){
            for (int k=0; k<size; k++){
                printf("*");
            }
            printf("\n");
        }
        
        printf("\n");
        return 0;

    } else if (userInput == 2){
        for (int i=0; i<size; i++){
            for (int k = 0; k < i + 1; k++){
                printf("*");
            }
            printf("\n");
        }
        
        printf("\n");
        return 0;
    } else {
        for (int j = 1; j<=size; j++){
            for (int i=0; i<size-j; i++){
                printf(" ");
            }
            
            for (int k=0; k<j; k++){
                printf("* ");
            }
            printf("\n");
        }

        return 0;
    }
}

void q2(){
    int size = 4;
    int A[size];
    int B[size];
    for (int i=0; i<size; i++){
        printf("Values for A[%d]:", i);
        scanf("%d",&A[i]);
        
        printf("Values for B[%d]:", i);
        scanf("%d",&B[i]);
    }
    
    printf("\n");
    
    for (int i=0; i<size; i++){
        printf("Values for A[%d]: %d\n", i, A[i]);
        
        printf("Values for B[%d]: %d\n", i, B[i]);
    }

    printf("\n");
    
    for (int i=0; i<size; i++){
        int temp = A[i];
        A[i] = B[i];
        B[i] = temp;
        
        printf("Values for A[%d]: %d ", i, A[i]);
        
        printf("Values for B[%d]: %d|\n", i, B[i]);
    }
    

}