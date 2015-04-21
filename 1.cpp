#include "Matrix.h"
template<typename W>
Matrix<W>::Matrix(int sz)
{
    this->sz = sz;
    this->mat.resize(sz);
}

template<typename W>
Matrix<W>::Matrix(vector<vector<W> >& mat, int sz)
{
    this->sz = sz;
    this->mat = mat;
}

template<typename W>
W Matrix<W>::get(int x, int y)const
 {
     return mat[x][y];
 }
/*
template<typename W>
Matrix<W> Matrix<W>::matrixMultiplication(Matrix<W>& b)
{
    vector<vector<W> > ans;
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
    Matrix<W> result(ans, sz);
    return result;
}

template<typename W>
Matrix<W> Matrix<W>::fastMultiplication(int power)
{
    vector<vector<W> > ans;
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

        mat = matrixMultiplication(mat, mat);
        power >>=1;
    }
     Matrix<W> result(ans, sz);
    return result;
}
*/
