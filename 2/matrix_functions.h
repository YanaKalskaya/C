#pragma once
#define N 5

float minMatrix(float m[N][N]);
float maxMatrix(float m[N][N]);
float minLowerTriangle(float m[N][N]);
float maxLowerTriangle(float m[N][N]);
float minUpperTriangle(float m[N][N]);
float maxUpperTriangle(float m[N][N]);
float minMainDiagonal(float m[N][N]);
float maxMainDiagonal(float m[N][N]);
float minSecondaryDiagonal(float m[N][N]);
float maxSecondaryDiagonal(float m[N][N]);
float meanMatrix(float m[N][N]);
float meanLowerTriangle(float m[N][N]);
float meanUpperTriangle(float m[N][N]);
float sumRow(float m[N][N], int row);
float sumCol(float m[N][N], int col);
float minRow(float m[N][N], int row);
float maxRow(float m[N][N], int row);
float minCol(float m[N][N], int col);
float maxCol(float m[N][N], int col);
float sumLowerTriangle(float m[N][N]);
float sumUpperTriangle(float m[N][N]);
float closestToMean(float m[N][N]);
float meanRow(float m[N][N], int row);
float meanCol(float m[N][N], int col);
