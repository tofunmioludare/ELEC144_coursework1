#include "uop_msb.h"
#include <cstdio>
using namespace uop_msb;

// 4x4 Array
double M[4][3] = {
    {1.0, 2.0, 3.0},
    {-3.0, -4.0, -5.0},
    {10.0, 11.0, 12.0},
    {-1.0, -2.0, -3.0}
};

double N[3][4] = {
    {1.0, 2.0, 3.0, 4.0},
    {-3.0, -4.0, -5.0, -6.0},
    {10.0, 11.0, 12.0, 13.0}
};

double x;
double y;

double w;
double z;

void displayArray(int rows, int cols, double *Array)
{
    for (unsigned row=0; row<rows; row++) {
        for (unsigned col=0; col<cols; col++) {
            printf("%8.1f\t", Array[(row*cols)+col]);
        }
        printf("\n");
    }
}

// ***** For (1) WRITE YOUR ARRAY Y HERE *****
double Y[4][4] = {
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0}
};

// ***** For (3) WRITE YOUR FUNCTION HERE *****
void matrixMultiplier(int rowK, int colK, int rowL, int colL){
    double K[rowK][colK];
    double L[rowL][colL];
    double Z[rowK][colL];

    if(colK == rowL){
        printf("\n\nYou have chosen right dimensions WISE ONE.🧠\n\nNow enter the matrix inputs, I would label the first matrix K and the second matrix L\n\n");
        printf("\nLETS START WITH MATRIX K\n");    
        for(int i=1; i<=rowK; i++){
            for(int j=1; j<=colK; j++){
                printf("Enter value for K[%d][%d]\n",i, j);
                scanf("%lf", &K[i-1][j-1]);
            }
        }
        printf("\nArray K is:\n");
        displayArray(rowK, colK, (double*)K);
        printf("\n\n\n");

        printf("\nLETS START WITH MATRIX L\n");    
        for(int i=1; i<=rowL; i++){
            for(int j=1; j<=colL; j++){
                printf("Enter value for L[%d][%d]\n",i, j);
                scanf("%lf", &L[i-1][j-1]);
            }
        }
        printf("\nArray L is:\n");
        displayArray(rowL, colL, (double*)L);
        printf("\n\n\n");

        for(int h = 0; h < rowK; h++){
            for(int i = 0; i < colL; i++){
                for(int j = 0; j < colK; j++){
                    w = K[h][j] * L[j][i];
                    z += w;
                }
                Z[h][i] = z;
                z = 0;
            }
        }
        printf("\nThe multiplication of matrices K and L is:\n");
        displayArray(rowK, colL, (double*)Z);
    }
    else{
        printf("Matrices with specified size cannot be executed❗️❗️❌");
    }
}
// *****  END YOUR FUNCTION HERE  *****

int main()
{
    double* addressOfArray = (double*)M;    //Obtain base address of the array M
    displayArray(4,3,(double*)M);           //Display in terminal

    // ***** MODIFY THE CODE BELOW HERE *****

    // 1. Create another Array Y with the correct dimensions to hold the result of M*N (see comments above)
    double Y[4][4] = {
                    {0, 0, 0, 0},
                    {0, 0, 0, 0},
                    {0, 0, 0, 0},
                    {0, 0, 0, 0}
                };
    // 2. Write a nested loop to perform a matrix multiplication M*N and store the result in Y
    
    for(int h = 0; h < 4; h++){
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 3; j++){
                x = M[h][j] * N[j][i];
                y += x;
            }
            Y[h][i] = y;
            y = 0;
        }
    }
    printf("\n\nThe multiplication of matrices A and B is:\n");
    displayArray(4, 4, (double*)Y);
    // 3. Write a function to multiply two matrices together (see comments above). Include some text code to demonstrate it working

    
    matrixMultiplier(3, 2, 2, 3);
    

    // ***** MODIFY THE CODE ABOVE HERE *****


    while (true) {
    }
}

