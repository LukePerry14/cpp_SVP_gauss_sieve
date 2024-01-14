#include "Gauss.h"
#include "vectors.h"

#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cctype>
#include <random>

using namespace std;

float GaussSieve(vector<vector<float>> basis, int vecnum){
    int collision_counter = 0;
    int collision_cap = collision_estimate(vecnum);
    vector<vector<float>> L(basis);

    while (collision_counter < collision_cap){
        vector<float> new_vec = randomSample(basis, vecnum);
        new_vec = GaussReduce(new_vec, L);

        if(norm(new_vec) == 0){
            collision_counter += 1;
        } else {
            L = L_reduce(L, new_vec);
            L.push_back(new_vec);
        }
    }

    float smallest = shortest_vec(L);
    return smallest;
}
//L is list of vectors found so far
// S is optional queue jumping array
//K is collision counter

vector<vector<float>> L_reduce(vector<vector<float>> L, vector<float> vec){
    for (auto x=0u; x<L.size(); x++){
        if(norm(vec_sub(L[x], vec)) < norm(L[x])){
            L[x] = vec_sub(L[x], vec);
        } else if (norm(vec_sub(L[x], vec)) < norm(L[x])){
            L[x] = vec_add(L[x], vec);
        }
    }

    return L;
}

vector<float> GaussReduce(vector<float> p, vector<vector<float>> L){
    bool reduceable = true;
    while(reduceable){
        reduceable = false;
        for(const auto& vec : L){
            if (norm(vec_sub(p, vec)) < norm(p)){
                reduceable = true;
                p = vec_sub(p, vec);
            } else if (norm(vec_add(p, vec)) < norm(p)) {
                reduceable = true;
                p = vec_add(p, vec);
            }
        }
    }
    //opportunity to implement S optimisation

    return p;
}

float shortest_vec(vector<vector<float>> L){
    float smallest = numeric_limits<float>::infinity();
    for(auto x=0u; x<L.size(); x++){
        float size = norm(L[x]);
        if(size < smallest){
            smallest = size;
        }
    }
    return smallest;
}

int collision_estimate(int n){
    return round(n/10) + 200;
}

vector<float> randomSample(vector<vector<float>> basis, int size){
    vector<float> retvec;
    vector<int> scalars;

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> distribution(-10,10);
    int randnum;
    for(int x = 0; x < size; x++){
        randnum = distribution(gen);
        scalars.push_back(randnum);
    }
    for(int x=0; x < size; x++){
        float nval = 0;
        for(int y=0; y < size; y++){
            nval += basis[y][x] * scalars[y];
        }
        retvec.push_back(nval);
    }

    return retvec;
}