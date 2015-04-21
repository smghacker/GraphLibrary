#ifndef Matrix_h
#define Matrix_h
#include<vector>
using namespace std;

class Matrix{
private:
    vector<vector<int> > mat;
    int sz;
    vector<vector<int> > matrixMultiplication(vector<vector<int> > mat, vector<vector<int> > b);
public:
    Matrix(int sz);
    Matrix(vector<vector<int> >& mat, int sz);
    int get(int x, int y)const;
    Matrix matrixMultiplication(Matrix& b);
    Matrix fastMultiplication(int power);
};
#endif
