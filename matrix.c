
/*
 * Homework 5 – Pointer Operations
 * CSE 220 – Spring 2026
 *
 * Name: Gordon Zhang
 * SBU ID: 117574236
 */

#include "matrix.h"
#include <stdio.h>

int max(int a, int b)
{
    if (a > b)
        return a;
    return b;
}

/*----------------------------------------------------
  1. Sparse Matrix
----------------------------------------------------*/
int SparseMatrix(int D[2], int M[D[0]][D[1]],
                 int S[3][(D[1] > D[0] ? D[1] : D[0])])
{

    int rows = D[0];
    int cols = D[1];
    int m = max(rows, cols);

    int nonZeroCount = 0;

     //Initialie the array S to be zero
    for (int i = 0; i < 3; i ++){
      for (int j = 0; j < m; j++){
        S[i][j] = 0;
      }
    }

    //Count all the non zero number
    for (int i = 0; i < rows; i++){
      for (int j = 0; j < cols; j++){
        if (M[i][j] != 0){
          nonZeroCount++;
        }
      }
    }

    //If the non zero count is more than the largest dimension, just return -1
    if (nonZeroCount > m){
      return -1;
    }

    //Create the sparse matrix
    int sparseColIndex = 0;
    for (int r = 0; r < rows; r++){
      for (int c = 0; c < cols; c++){
        //If the value in the 2D array is not 0
        if (M[r][c] != 0){
          //Give r to the first array (row)
          S[0][sparseColIndex] = r;
          //Give c to the second array (column)
          S[1][sparseColIndex] = c;
          //Give the value at r row, and c column of 2D array M to the third array (value)
          S[2][sparseColIndex] = M[r][c];
          //Increse the sparseColIndex so we move to the next column of all 3 arrays in the 2D array
          sparseColIndex++;
        }
      }
    }



  

    return nonZeroCount;
}







/*----------------------------------------------------
  2. Hadamard Product
----------------------------------------------------*/
int HadamardProduct(const int D[6],
                    const int M[D[0]][D[1]],
                    const int N[D[2]][D[3]],
                    int A[D[4]][D[5]])
{

    int mRows = D[0];
    int mCols = D[1];

    int nRows = D[2];
    int nCols = D[3];

    int aRows = D[4];
    int aCols = D[5];

    //Initialie the array A to be 0
    for (int i = 0; i < aRows; i ++){
      for (int j = 0; j < aCols; j++){
        A[i][j] = 0;
      }
    }

    //Find the smaller rows so we don't go out of bound
    int smallerRow;
    if (mRows < nRows){
      smallerRow = mRows;
    } else {
      smallerRow = nRows;
    }
    //Find the smaller cols so we don't go out of bound
    int smallerCol;
    if (mCols < nCols){
      smallerCol = mCols;
    } else {
      smallerCol = nCols;
    }

    //Fill in the result for A
    //Using the smaller row so we make sure i does not go out of bound for matrix A and any of matrix M or N
    for (int i = 0; i < smallerRow && i < aRows; i++){
      //Using the smaller col so we make sure j does not go out of bound for matrix A and any of matrix M or N
      for (int j = 0; j < smallerCol && j < aCols; j++){
        //Compute the product
        A[i][j] = M[i][j] * N[i][j];
      }
    }

    //If same dimension
    if (mRows == nRows && mCols == nCols){
        
        //Exact size
        if (aRows == mRows && aCols == mCols){
          return 1;
        } else if (aRows >= mRows && aCols >= mCols){
          //Oversize
          return 2;
        } else {
          //Not enough or compatible
          return 3;
        }
    } else {
      //Different dimension
      if (aRows >= smallerRow && aCols >= smallerCol){
        //Have enough to store result
        return -1;
      } else {
        //Does not have enough to store result
        return -2;
      }
    }

    return 0;
}


/*----------------------------------------------------
  3. Matrix Multiplication
----------------------------------------------------*/
int Multiplication(const int D[6],
                   const int M[D[0]][D[1]],
                   const int N[D[2]][D[3]],
                   int A[D[4]][D[5]])
{

    int mRows = D[0];
    int mCols = D[1];

    int nRows = D[2];
    int nCols = D[3];

    int aRows = D[4];
    int aCols = D[5];

    //Initialize A to be a zero matrix
    for (int r = 0; r < aRows; r++){
      for (int c = 0; c < aCols; c++){
        A[r][c] = 0;
      }
    }

    //Cannot conduct a multiplication
    if (mCols != nRows){
      return -1;
    }
    if (aRows < mRows){
      return -3;
    }
    if (aCols < mCols){
      return -2;
    }

    //Compute the multiplication
    //Start with the row of m and dot product it with the column of n
    //Making sure the rows does not go out of bound for both matrix M and A
    for (int r = 0; r < mRows && r < aRows; r++){
      //Making sure the columns does not go out of bound for both matrix N and A
      for (int c = 0; c < nCols && c <aCols; c++){
        int dotProduct = 0;
        //Loop that loops from left to right for all elements
        for (int temp = 0; temp < mCols; temp++){
          //Only if there is a row corresponding with n, we do the dot product
          if (temp < nRows){
            dotProduct += M[r][temp] * N[temp][c];
          }
        } 
        //Give dot product
        A[r][c] = dotProduct;

      }

    }


    //Exactly fits in
    if (aRows == mRows && aCols == nCols){
        return 1;
    } else  {
        //More than enough
        return 2;
    }
}


/*----------------------------------------------------
  4. Diagonal Sum
----------------------------------------------------*/
int DiagonalSum(const int D[4],
                const int A[D[0]][D[1]],
                int DS[D[2]][D[3]])
{

    int rows = D[0];
    int cols = D[1];

    int dsRows = D[2];
    int dsCols = D[3];

    //Intialize DS to a 0 matrix
    for (int r = 0; r < dsRows; r++){
      for (int c = 0; c < dsCols; c++){
        DS[r][c] = 0;
      }
    }



    int mainD = 0;
    //Main diagonal has some row and column index
    for (int i = 0; i < rows && i < cols; i++ ){
      mainD += A[i][i];
    }

    //Assign the value
    if (dsRows > 0 && dsCols > 0){
      DS[0][0] = mainD;
    }

   
    
    int antiD = 0;
    //Making sure i does not go out of bound for matrix A
    for (int i = 0; i < rows && i < cols; i++){
      antiD += A[i][cols - 1 -i];
    }

    //Assign anti diagonal
    if (dsRows > 0 && dsCols > 1){
        DS[0][1] = antiD;
    }
  

  

    //Starting from the first columns to the last
    //Making sure j does not go out of bound for columns of matrix A and DS
    if (dsRows > 1){
      for (int j = 0; j < cols && j < dsCols; j++){
        int colSum = 0;
        //Loop from first rows to the last
        for (int i = 0; i < rows; i++){
          //Add up the column value at row i
          colSum += A[i][j];
        }
        //Assign the value to matrix DS
        DS[1][j] = colSum;
      }

    }

    //Starting from the first rows to the last
    //Making sure i does not go out of bound for rows of matrix A and DS
    for (int i = 0; i < rows && (i + 2) < dsRows; i++){
      int rowSum = 0;
      //Loop from first columns to the last
      for (int j = 0; j < cols; j++){
        //Add up the column value at row i
        rowSum += A[i][j];
      }
      //Assign the value to matrix DS
      DS[i + 2][0] = rowSum;
    }

    if (dsRows < (rows + 2) || dsCols < cols){
      return -1;
    } 
    if (dsRows == (rows + 2) && dsCols == cols){
      return 1;
    }
    return 2;

}
