#include "Matrix.h"
Matrix::Matrix(int sz)
{
    this->sz = sz;
    this->mat.resize(sz);
}

Matrix::Matrix(vector<vector<int> >& mat, int sz)
{
    this->sz = sz;
    this->mat = mat;
}

int Matrix::get(int x, int y)const
{
    return mat[x][y];
}
Matrix Matrix::matrixMultiplication(Matrix& b)
{
    vector<vector<int> > ans;
    ans.resize(sz);
    for(int i = 0; i < sz; i++)
    {
        ans[i].resize(sz);
    }
    for(int i = 0; i < sz; i++)
    {
        for(int j = 0; j < sz; j++)
        {
            for(int k = 0; k < sz; k++)
            {
                ans[i][j] += mat[i][k] * b.get(k,j);
            }
        }
    }
    Matrix result(ans, sz);
    return result;
}

vector<vector<int> > Matrix::matrixMultiplication(vector<vector<int> > mat, vector<vector<int> > b)
{
    vector<vector<int> > ans;
    ans.resize(sz);
    for(int i = 0; i < sz; i++)
    {
        ans[i].resize(sz);
    }
    for(int i = 0; i < sz; i++)
    {
        for(int j = 0; j < sz; j++)
        {
            for(int k = 0; k < sz; k++)
            {
                ans[i][j] += mat[i][k] * b[k][j];
            }
        }
    }
    return ans;
}
Matrix Matrix::fastMultiplication(int power)
{
    vector<vector<int> > ans;
    ans.resize(sz);
    for(int i = 0; i < sz; i++)
    {
        ans[i].resize(sz);
    }

    for(int i = 0; i < sz; i++)
    {
        for(int j = 0; j < sz; j++)
        {
            ans[i][j] = (i==j);
        }
    }
    while(power)
    {
        if(power & 1)
        {
            ans = matrixMultiplication(ans, mat);
        }

        ans = matrixMultiplication(mat, mat);
        power >>=1;
    }
    Matrix result(ans, sz);
    return result;
}
