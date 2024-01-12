#ifndef VECTORS_H
#define VECTORS_H

#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <algorithm>

using namespace std;

class Matrix {
private:
    vector<vector<float>> data;

public:
    Matrix(const vector<vector<float>>& vecs);
    void printMatrix() const;
};

float norm(vector<float> vec);
vector<float> vec_sub(vector<float> vec1, vector<float> vec2);

#endif

