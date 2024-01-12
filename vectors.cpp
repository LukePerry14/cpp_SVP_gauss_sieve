#include "vectors.h"

#include <cmath>
#include <iostream>

using namespace std;

Matrix::Matrix(const vector<vector<float>>& input) : data(input) {}

void Matrix::printMatrix() const{
    for (const auto& row : data) {
        for (float value : row) {
            cout << value << " ";
        }
        cout << endl;
    }
}

float norm(vector<float> vec) const{
    total = 0;
    for(const auto& val : vec){
        total += val * val;
    }
    return sqrt(total);
}

vector<float> vec_sub(vector<float> vec1, vector<float> vec2){
    vector<float> retvec;
    for(int pos=0; pos < vec1.size(); pos++){
        retvec.push_back(vec1[x] - vec2[x]);
    }
    return retvec;
}

vector<float> randomSample(vector<vector<vector<float>> basis, int size){
    int[size] scalars;
    for 
    vector<float> retvec;
    for(int x=0; x < size; x++){
        float nval = 0
        for(int y=0; y < size; y++){
            nval += basis[y][x]
        }
        retvec.push_back()
    }
}