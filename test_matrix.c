/*
 * Homework 5 – Pointer Operations
 * CSE 220 – Spring 2026
 *
 * Name: Gordon Zhang
 * SBU ID: 117574236
 */
#include <criterion/criterion.h>
#include "matrix.h"


//SparseMatrix Tests
Test(SparseMatrix, simple_sparse)
{
    int D[2] = {3,3};

    int M[3][3] = {
        {0,2,0},
        {3,0,4},
        {0,0,0}
    };

    int S[3][3];

    int result = SparseMatrix(D,M,S);

    print_sparse_matrix(3, S);

    cr_assert_eq(result, 3);
}
Test(SparseMatrix, allZeros)
{
    int D[2] = {3,3};

    int M[3][3] = {
        {0,0,0},
        {0,0,0},
        {0,0,0}
    };

    int S[3][3];

    int result = SparseMatrix(D,M,S);

    print_sparse_matrix(3, S);

    cr_assert_eq(result, 0);
}
Test(SparseMatrix, oneElement)
{
    int D[2] = {1,1};

    int M[1][1] = {
        {5}
    };

    int S[3][1];

    int result = SparseMatrix(D,M,S);

    print_sparse_matrix(1, S);

    cr_assert_eq(result, 1);
}
Test(SparseMatrix, allNonZeros)
{
    int D[2] = {2,3};

    int M[2][3] = {
        {1,2,3},
        {4,5,6}
    };

    int S[3][3];

    int result = SparseMatrix(D,M,S);

    print_sparse_matrix(3, S);

    cr_assert_eq(result, -1);
}
Test(SparseMatrix, zeroSize)
{
    int D[2] = {0,0};

    int M[0][0];

    int S[3][0];

    int result = SparseMatrix(D,M,S);

    print_sparse_matrix(3, S);
    cr_assert_eq(result, 0);
}
Test(SparseMatrix, oneFullRow)
{
    int D[2] = {1,5};

    int M[1][5] = {
        {1,2,3,4,5}
    };

    int S[3][5];

    int result = SparseMatrix(D,M,S);

    print_sparse_matrix(5, S);
    cr_assert_eq(result, 5);
}
Test(SparseMatrix, oneFullCol)
{
    int D[2] = {5,1};

    int M[5][1] = {
        {1},
        {2},
        {3},
        {4},
        {5}
    };

    int S[3][5];

    int result = SparseMatrix(D,M,S);

    print_sparse_matrix(5, S);
    cr_assert_eq(result, 5);
}
Test(SparseMatrix, oneRow)
{
    int D[2] = {1,5};

    int M[1][5] = {
        {1,2,0,0,0}
    };

    int S[3][5];

    int result = SparseMatrix(D,M,S);

    print_sparse_matrix(5, S);
    cr_assert_eq(result, 2);
}
Test(SparseMatrix, oneCol)
{
    int D[2] = {5,1};

    int M[5][1] = {
        {1},
        {2},
        {0},
        {0},
        {0}
    };

    int S[3][5];

    int result = SparseMatrix(D,M,S);

    print_sparse_matrix(5, S);
    cr_assert_eq(result, 2);
}
Test(SparseMatrix, largeSparse)
{
    int D[2] = {5,5};

    int M[5][5] = {
        {0,0,0,1,0},
        {2,0,0,0,0},
        {0,0,3,0,0},
        {0,4,0,0,0},
        {0,0,0,0,5}
    };

    int S[3][5];

    int result = SparseMatrix(D,M,S);

    print_sparse_matrix(5, S);
    cr_assert_eq(result, 5);
}




//HadamardProduct tests
Test(HadamardProduct, exact)
{
    int D[6] = {2,2,2,2,2,2};

    int M[2][2] = {
        {1,2},
        {3,4}
    };

    int N[2][2] = {
        {2,0},
        {1,3}
    };

    int A[2][2] = {
        {0}
    };

    int r = HadamardProduct(D,M,N,A);

    cr_assert_eq(r,1);
}
Test(HadamardProduct, oversize)
{
    int D[6] = {2,2,2,2,3,3};

    int M[2][2] = {
        {1,2},
        {3,4}
    };

    int N[2][2] = {
        {0,1},
        {1,0}
    };

    int A[3][3] = {
        {0}
    };

    int r = HadamardProduct(D,M,N,A);

    cr_assert_eq(r,2);
}
Test(HadamardProduct, undersize)
{
    int D[6] = {3,3,3,3,2,2};

    int M[3][3] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    int N[3][3] = {
        {9,8,7},
        {6,5,4},
        {3,2,1}
    };

    int A[2][2] = {
        {0}
    };

    int r = HadamardProduct(D,M,N,A);

    cr_assert_eq(r,3);
}
Test(HadamardProduct, compatibleSmallerA)
{
    int D[6] = {3,3,2,2,2,2};

    int M[3][3] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    int N[3][3] = {
        {2,5},
        {1,4}
    };

    int A[2][2] = {
        {0}
    };

    int r = HadamardProduct(D,M,N,A);

    cr_assert_eq(r,-1);
}
Test(HadamardProduct, compatibleNotEnough)
{
    int D[6] = {3,3,2,2,1,1};

    int M[3][3] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    int N[3][3] = {
        {2,5},
        {1,4}
    };

    int A[1][1] = {
        {0}
    };

    int r = HadamardProduct(D,M,N,A);

    cr_assert_eq(r,-2);
}
Test(HadamardProduct, oneElement)
{
    int D[6] = {1,1,1,1,1,1};

    int M[1][1] = {
        {5}
    };

    int N[1][1] = {
        {3}
    };

    int A[1][1] = {
        {0}
    };

    int r = HadamardProduct(D,M,N,A);

    cr_assert_eq(r,1);
}
Test(HadamardProduct, empty)
{
    int D[6] = {1,1,1,1,1,1};

    int M[0][0] = {};

    int N[0][0] = {};

    int A[0][0] = {};

    int r = HadamardProduct(D,M,N,A);

    cr_assert_eq(r,1);
}
Test(HadamardProduct, differentCols)
{
    int D[6] = {2,3,2,2,2,2};

    int M[2][3] = {
        {1,2,3},
        {4,5,6}
    };

    int N[2][2] = {
        {1,1},
        {2,2}
    };

    int A[2][2] = {0};

    int r = HadamardProduct(D,M,N,A);

    cr_assert_eq(r,-1);
}
Test(HadamardProduct, negative)
{
    int D[6] = {2,2,2,2,2,2};

    int M[2][2] = {
        {1,-2},
        {-3,4}
    };

    int N[2][2] = {
        {2,-3},
        {-1,4}
    };

    int A[2][2] = {0};

    int r = HadamardProduct(D,M,N,A);

    cr_assert_eq(r,1);
}
Test(HadamardProduct, rowOnly)
{
    int D[6] = {1,4,1,4,1,4};

    int M[1][4] = {
        {1,2,3,4}
    };

    int N[1][4] = {
        {2,2,2,2}
    };

    int A[1][4] = {0};

    int r = HadamardProduct(D,M,N,A);

    cr_assert_eq(r,1);
}




//Multiplication tests
Test(Multiplication, exact)
{
    int D[6] = {2,2,2,2,2,2};

    int M[2][2] = {
        {1,2},
        {3,4}
    };

    int N[2][2] = {
        {1,2},
        {3,4}
    };

    int A[2][2] = {
        {7,10},
        {15,22}
    };

    int r = Multiplication(D,M,N,A);

    cr_assert_eq(r,1);
}
Test(Multiplication, singleElement)
{
    int D[6] = {1,1,1,1,1,1};

    int M[1][1] = {
        {4}
    };

    int N[1][1] = {
        {3}
    };

    int A[1][1] = {
        {12}
    };

    int r = Multiplication(D,M,N,A);

    cr_assert_eq(r,1);
}
Test(Multiplication, incompatible)
{
    int D[6] = {2,3,2,2,2,2};

    int M[2][3] = {
        {1,343,4342},
        {123,1231,1231}
    };

    int N[2][2] = {
        {3,2},
        {2,3}
    };

    int A[2][2];

    int r = Multiplication(D,M,N,A);

    cr_assert_eq(r,-1);
}
Test(Multiplication, noRows)
{
    int D[6] = {3,2,2,2,2,2};

    int M[3][2] = {
        {1,2},
        {2,3},
        {3,4}
    };

    int N[2][2] = {
        {3,2},
        {2,3}
    };

    int A[2][2];

    int r = Multiplication(D,M,N,A);

    cr_assert_eq(r,-3);
}

Test(Multiplication, noCols)
{
    int D[6] = {2,2,2,2,2,1};

    int M[3][2] = {
        {1,2},
        {2,3}
    };

    int N[2][2] = {
        {3,2},
        {2,3}
    };

    int A[2][1];

    int r = Multiplication(D,M,N,A);

    cr_assert_eq(r,-2);
}
Test(Multiplication, allZero)
{
    int D[6] = {2,2,2,2,2,2};

    int M[2][2] = {{}};

    int N[2][2] = {{}};

    int A[2][2] = {{}};

    int r = Multiplication(D,M,N,A);

    cr_assert_eq(r,1);
}
Test(Multiplication, allIdentity)
{
    int D[6] = {2,2,2,2,2,2};

    int M[2][2] = {
        {1,0},
        {0,1}
    };

    int N[2][2] = {
        {1,0},
        {0,1}
    };

    int A[2][2] = {
        {1,0},
        {0,1}
    };

    int r = Multiplication(D,M,N,A);

    cr_assert_eq(r,1);
}
Test(Multiplication, extraRow)
{
    int D[6] = {2,2,2,2,3,2};

    int M[2][2] = {
        {1,0},
        {0,1}
    };

    int N[2][2] = {
        {1,0},
        {0,1}
    };

    int A[3][2] = {
        {1,0},
        {0,1},
        {0,0}
    };

    int r = Multiplication(D,M,N,A);

    cr_assert_eq(r,2);
}

Test(Multiplication, extraCol)
{
    int D[6] = {2,2,2,2,2,3};

    int M[2][2] = {
        {1,0},
        {0,1}
    };

    int N[2][2] = {
        {1,0},
        {0,1}
    };

    int A[2][3] = {
        {1,0,0},
        {0,1,0}
    };

    int r = Multiplication(D,M,N,A);

    cr_assert_eq(r,2);
}
Test(Multiplication, negative)
{
    int D[6] = {2,2,2,2,2,2};

    int M[2][2] = {
        {-1,0},
        {0,-1}
    };

    int N[2][2] = {
        {1,0},
        {0,1}
    };

    int A[2][2] = {
        {-1,0},
        {0,-1}
    };

    int r = Multiplication(D,M,N,A);

    cr_assert_eq(r,1);
}








//DiagonalSum test
Test(DiagonalSum, square_matrix)
{
    int D[4] = {3,3,2,2};

    int A[3][3] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    int DS[2][2] = {
        {0}
    };
    int r = DiagonalSum(D,A,DS);
    cr_assert_eq(r,-1);
}
Test(DiagonalSum, rectangularRow)
{
    int D[4] = {4,2,6,2};

    int A[4][2] = {
        {1,2},
        {3,4},
        {5,6},
        {7,8}
    };
    int DS[6][2] = {
        {0}
    };
    int r = DiagonalSum(D,A,DS);
    cr_assert_eq(r,1);
}
Test(DiagonalSum, rectangularCol)
{
    int D[4] = {2,4,4,4};

    int A[2][4] = {
        {1,2,3,4},
        {5,6,7,8}
    };
    int DS[4][4] = {
        {0}
    };
    int r = DiagonalSum(D,A,DS);
    cr_assert_eq(r,1);
}
Test(DiagonalSum, singleA)
{
    int D[4] = {1,1,4,3};

    int A[1][1] = {
        {9}
    };
    int DS[4][3] = {
        {9,0,0},
        {9,0,0},
        {9,0,0},
        {0,0,0}
    };
    int r = DiagonalSum(D,A,DS);
    cr_assert_eq(r,2);
}
Test(DiagonalSum, emptyMatrix)
{
    int D[4] = {1,1,1,1};

    int A[1][1] = {
    };
    int DS[1][1] = {
    };
    int r = DiagonalSum(D,A,DS);
    cr_assert_eq(r,-1);
}
Test(DiagonalSum, noAntiD)
{
    int D[4] = {3,2,3,2};

    int A[3][2] = {
        {1,2},
        {3,4},
        {5,6}
    };
    int DS[3][2] = {
    };
    int r = DiagonalSum(D,A,DS);
    cr_assert_eq(r,-1);
}
Test(DiagonalSum, smallDS)
{
    int D[4] = {3,3,1,1};

    int A[3][3] = {
        {1,2,5},
        {3,4,6}
    };
    int DS[1][1] = {
    };
    int r = DiagonalSum(D,A,DS);
    cr_assert_eq(r, -1);
}
Test(DiagonalSum, negative)
{
    int D[4] = {2,2,4,2};

    int A[2][2] = {
        {-1,-2},
        {-3,-4}
    };
    int DS[4][2] = {
        {-5,-5},
        {-4,-6},
        {-3,0},
        {-7,0}
    };
    int r = DiagonalSum(D,A,DS);
    cr_assert_eq(r, 1);
}
Test(DiagonalSum, moreThanEnough)
{
    int D[4] = {2,2,5,4};

    int A[2][2] = {
        {1,2},
        {3,4}
    };
    int DS[5][4] = {
        {5,5,0,0},
        {4,6,0,0},
        {3,0,0,0},
        {7,0,0,0},
        {0,0,0,0}
    };
    int r = DiagonalSum(D,A,DS);
    cr_assert_eq(r, 2);
}
Test(DiagonalSum, emptyDSAndA)
{
    int D[4] = {2,2,5,4};

    int A[2][2] = {
        {}
    };
    int DS[5][4] = {
        {}
    };
    int r = DiagonalSum(D,A,DS);
    cr_assert_eq(r, 2);
}
