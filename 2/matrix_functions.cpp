#include "matrix_functions.h"
#include <cmath>
#include <algorithm>
using namespace std;

float minMatrix(float m[N][N])
{
    float minVal = m[0][0];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            minVal = min(minVal, m[i][j]);
    return minVal;
}

float maxMatrix(float m[N][N])
{
    float maxVal = m[0][0];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            maxVal = max(maxVal, m[i][j]);
    return maxVal;
}

float minLowerTriangle(float m[N][N])
{
    float minVal = m[1][0];
    for (int i = 1; i < N; i++)
        for (int j = 0; j < i; j++)
            minVal = min(minVal, m[i][j]);
    return minVal;
}

float maxLowerTriangle(float m[N][N])
{
    float maxVal = m[1][0];
    for (int i = 1; i < N; i++)
        for (int j = 0; j < i; j++)
            maxVal = max(maxVal, m[i][j]);
    return maxVal;
}

float minUpperTriangle(float m[N][N])
{
    float minVal = m[0][1];
    for (int i = 0; i < N - 1; i++)
        for (int j = i + 1; j < N; j++)
            minVal = min(minVal, m[i][j]);
    return minVal;
}

float maxUpperTriangle(float m[N][N])
{
    float maxVal = m[0][1];
    for (int i = 0; i < N - 1; i++)
        for (int j = i + 1; j < N; j++)
            maxVal = max(maxVal, m[i][j]);
    return maxVal;
}

float minMainDiagonal(float m[N][N])
{
    float minVal = m[0][0];
    for (int i = 0; i < N; i++)
        minVal = min(minVal, m[i][i]);
    return minVal;
}

float maxMainDiagonal(float m[N][N])
{
    float maxVal = m[0][0];
    for (int i = 0; i < N; i++)
        maxVal = max(maxVal, m[i][i]);
    return maxVal;
}

float minSecondaryDiagonal(float m[N][N])
{
    float minVal = m[0][N - 1];
    for (int i = 0; i < N; i++)
        minVal = min(minVal, m[i][N - 1 - i]);
    return minVal;
}

float maxSecondaryDiagonal(float m[N][N])
{
    float maxVal = m[0][N - 1];
    for (int i = 0; i < N; i++)
        maxVal = max(maxVal, m[i][N - 1 - i]);
    return maxVal;
}

float meanMatrix(float m[N][N])
{
    float sum = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            sum += m[i][j];
    return sum / (N * N);
}

float meanLowerTriangle(float m[N][N])
{
    float sum = 0;
    int count = 0;
    for (int i = 1; i < N; i++)
        for (int j = 0; j < i; j++)
        {
            sum += m[i][j];
            count++;
        }
    return count > 0 ? sum / count : 0;
}

float meanUpperTriangle(float m[N][N])
{
    float sum = 0;
    int count = 0;
    for (int i = 0; i < N - 1; i++)
        for (int j = i + 1; j < N; j++)
        {
            sum += m[i][j];
            count++;
        }
    return count > 0 ? sum / count : 0;
}

float sumRow(float m[N][N], int row)
{
    float sum = 0;
    for (int j = 0; j < N; j++)
        sum += m[row][j];
    return sum;
}

float sumCol(float m[N][N], int col)
{
    float sum = 0;
    for (int i = 0; i < N; i++)
        sum += m[i][col];
    return sum;
}

float minRow(float m[N][N], int row)
{
    float minVal = m[row][0];
    for (int j = 1; j < N; j++)
        if (m[row][j] < minVal)
            minVal = m[row][j];
    return minVal;
}

float maxRow(float m[N][N], int row)
{
    float maxVal = m[row][0];
    for (int j = 1; j < N; j++)
        if (m[row][j] > maxVal)
            maxVal = m[row][j];
    return maxVal;
}

float minCol(float m[N][N], int col)
{
    float minVal = m[0][col];
    for (int i = 1; i < N; i++)
        if (m[i][col] < minVal)
            minVal = m[i][col];
    return minVal;
}

float maxCol(float m[N][N], int col)
{
    float maxVal = m[0][col];
    for (int i = 1; i < N; i++)
        if (m[i][col] > maxVal)
            maxVal = m[i][col];
    return maxVal;
}

float meanRow(float m[N][N], int row)
{
    float sum = 0;
    for (int j = 0; j < N; j++)
        sum += m[row][j];
    return sum / N;
}

float meanCol(float m[N][N], int col)
{
    float sum = 0;
    for (int i = 0; i < N; i++)
        sum += m[i][col];
    return sum / N;
}

float sumLowerTriangle(float m[N][N]) {
    float sum = 0;
    for (int i = 1; i < N; i++)
        for (int j = 0; j < i; j++)
            sum += m[i][j];
    return sum;
}

float sumUpperTriangle(float m[N][N]) {
    float sum = 0;
    for (int i = 0; i < N - 1; i++)
        for (int j = i + 1; j < N; j++)
            sum += m[i][j];
    return sum;
}

float closestToMean(float m[N][N]) {
    float mean = meanMatrix(m);
    float closest = m[0][0];
    float minDiff = abs(m[0][0] - mean);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            float diff = abs(m[i][j] - mean);
            if (diff < minDiff) {
                minDiff = diff;
                closest = m[i][j];
            }
        }
    }
    return closest;
}