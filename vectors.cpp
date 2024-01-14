#include "vectors.h"

#include <cmath>
#include <vector>
#include <iostream>

using namespace std;

float norm(vector<float> vec){
    float total = 0;
    for(const auto& val : vec){
        total += val * val;
    }
    return sqrt(total);
}

vector<float> vec_sub(vector<float> vec1, vector<float> vec2){
    vector<float> retvec;
    for(auto pos=0u; pos < vec1.size(); pos++){
        retvec.push_back(vec1[pos] - vec2[pos]);
    }
    return retvec;
}