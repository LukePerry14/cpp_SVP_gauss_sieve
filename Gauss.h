#ifndef GAUSS_H
#define GAUSS_H

#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <algorithm>

using namespace std;

float GaussSieve(vector<vector<float>> basis, int vecnum);

vector<float> GaussReduce(vector<float> p, vector<vector<float>> L);

float shortest_vec(vector<vector<float>> L);

vector<float> randomSample(vector<vector<float>> basis, int size);

int collision_estimate(int n);

#endif