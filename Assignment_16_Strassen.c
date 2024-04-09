#include <stdio.h>
#include <stdlib.h>
//Function to dynamically create a matrix
int** create(int m, int n) {
 int** mat = (int**)malloc(sizeof(int*) * m);
 int i, j;
 for (i = 0; i < m; i++) {
 mat[i] = (int*)malloc(sizeof(int) * n);
 for (j = 0; j < n; j++) {
 mat[i][j] = 0; 
 }
 }
 return mat;
}
//Function to segment a matrix
void segment(int **A, int **B, int h, int r, int c) {
 int i, j;
 for (i = 0; i < h; i++) {
 for (j = 0; j < h; j++) {
 A[i][j] = B[r + i][c + j];//Copy elements from matrix B to matrix A
 }
 }
}
//Function to add two matrices
int** add(int **A, int **B, int m, int coeff) {
 int** res = create(m, m); //Create a result matrix
 int i, j;
 for (i = 0; i < m; i++) {
 for (j = 0; j < m; j++) {
 res[i][j] = A[i][j] + coeff * B[i][j]; //Perform element-wise 
addition
 }
 }
 return res;
}
//Function to perform matrix multiplication using Strassen's algorithm
void strassen(int** A, int** B, int** res, int n) {
 if (n == 1) {
 res[0][0] = A[0][0] * B[0][0]; //Base case for single-element matrices
 } else {
 int half = n / 2;
 int** a = create(half, half);
 int** b = create(half, half);
 int** c = create(half, half);
 int** d = create(half, half);
 int** e = create(half, half);
 int** f = create(half, half);
 int** g = create(half, half);
 int** h = create(half, half);
 //Divide matrices A and B into submatrices
 segment(a, A, half, 0, 0);
 segment(b, A, half, 0, half);
 segment(c, A, half, half, 0);
 segment(d, A, half, half, half);
 segment(e, B, half, 0, 0);
 segment(f, B, half, 0, half);
 segment(g, B, half, half, 0);
 segment(h, B, half, half, half);
 //Define temporary matrices for multiplicative terms
 int** p1 = create(half, half);
 int** p2 = create(half, half);
 int** p3 = create(half, half);
 int** p4 = create(half, half);
 int** p5 = create(half, half);
 int** p6 = create(half, half);
 int** p7 = create(half, half);
 
 //Calculate 7 multiplicative terms using recursive calls
 strassen(a, add(f, h, half, -1), p1, half);
 strassen(add(a, b, half, 1), h, p2, half);
 strassen(add(c, d, half, 1), e, p3, half);
 strassen(d, add(g, e, half, -1), p4, half);
 strassen(add(a, d, half, 1), add(e, h, half, 1), p5, half);
 strassen(add(b, d, half, -1), add(g, h, half, 1), p6, half);
 strassen(add(a, c, half, -1), add(e, f, half, 1), p7, half);
 //Define temporary matrices for final result terms
 int **res_00 = create(half, half);
 int **res_01 = create(half, half);
 int **res_10 = create(half, half);
 int **res_11 = create(half, half);
 
 //Compute final result terms based on Strassen's algorithm
 res_00 = add(add(add(p6, p5, half, 1), p4, half, 1), p2, half, -1);
 res_01 = add(p1, p2, half, 1);
 res_10 = add(p3, p4, half, 1);
 res_11 = add(add(add(p1, p3, half, -1), p5, half, 1), p7, half, -1);
 //Assemble the final result matrix
 int i, j;
 for (i = 0; i < half; i++) {
 for (j = 0; j < half; j++) {
 res[i][j] = res_00[i][j];
 res[i][j + half] = res_01[i][j];
 res[half + i][j] = res_10[i][j];
 res[half + i][j + half] = res_11[i][j];
 }
 }
 }
}
//Function to display a matrix
void display(int **A, int m, int n) {
 int i, j; 
 for(i = 0; i < m; i++) { 
 for(j = 0; j < n; j++) 
 printf("%d\t", A[i][j]); 
 printf("\n"); 
 } 
}
int main() {
 int r1, c1, r2, c2;
 printf("Enter the dimensions of 1st matrix (Row, Column):\n");
 scanf("%d", &r1);
 scanf("%d", &c1);
 printf("Enter the dimensions of 2nd matrix (Row, Column):\n");
 scanf("%d", &r2);
 scanf("%d", &c2);
 int i, j;
 if (c1 != r2) {
 printf("Matrix dimensions are not compatible for multiplication.\n");
 return 0;
 }
 int max = (r1 > c1) ? (r1 > c2 ? r1 : c2) : (c1 > c2 ? c1 : c2);
 int p = 1;
 while (p < max) {
 p *= 2;
 }
 int** M1 = create(p, p);
 int** M2 = create(p, p);
 printf("Enter the elements of 1st matrix:\n");
 for (i = 0; i < r1; i++)
 for (j = 0; j < c1; j++)
 scanf("%d", &M1[i][j]);
 printf("\nEnter the elements of 2nd matrix:\n");
 for (i = 0; i < r2; i++)
 for (j = 0; j < c2; j++)
 scanf("%d", &M2[i][j]);
 printf("ORIGINAL MATRIX 1:\n"); 
 display(M1, r1, c1);
 printf("\nORIGINAL MATRIX 2:\n"); 
 display(M2, r2, c2);
 printf("\nPADDED MATRIX 1:\n"); 
 display(M1, p, p);
 printf("\nPADDED MATRIX 2:\n"); 
 display(M2, p, p);
 int** result = create(p, p);
 strassen(M1, M2, result, p);
 printf("MATRIX MULTIPLICATION RESULT:\n"); 
 display(result, r1, c2);
 return 0;
}
