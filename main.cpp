#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cctype>

#include "vectors.h"

using namespace std;

vector<vector<float>> processArgs(int argc, char** argv){
    int vecnum = sqrt(argc-1);

    if (vecnum * vecnum != argc-1) {
        cerr << "Invalid Argument Size" << endl;
        exit(EXIT_FAILURE);
    }

    vector<vector<float>> t_basis;
    for (int vec = 1; vec < argc; vec += vecnum) {
        vector<float> base;
        for (int x = 0; x < vecnum; x++) {
            string arg = argv[vec + x];
            arg.erase(remove(arg.begin(), arg.end(), '['), arg.end());
            arg.erase(remove(arg.begin(), arg.end(), ']'), arg.end());

            try {
                size_t pos;
                float value = stof(arg, &pos);
                if (pos == arg.size()) {
                    base.push_back(value);
                } else {
                    cerr << "Invalid Argument: " << arg << endl;
                    exit(EXIT_FAILURE);
                }
            } catch (const exception& e) {
                cerr << "Invalid Argument: " << arg << endl;
                exit(EXIT_FAILURE);
            }
        }
        t_basis.push_back(base);
    }
    return t_basis;
}
int main(int argc, char* argv[]) {
    vector<vector<float>> t_basis = processArgs(argc, argv);
    Matrix basis(t_basis);

    basis.printMatrix();
    //GaussSieve
    return 0;
}
//L is list of vectors found so far
// S is optional queue jumping array
//K is collision counter

int collision_estimate(int n){
    if(n < 4){
        return 1;
    } else{
        return round(n/10);
    }
}
vector<float> GaussReduce(vector<float> p, vector<vector<float>> L, vector<vector<float>>){
    reduceable = true;
    while(reducable){
        reducable = false;
        for(const auto& vec : L){
            if norm(vec_sub(p, vec)) < norm(p){
                reducable = true;
                p = vec_sub(p, vec);
            }
        }
    }
    //opportunity to implement S optimisation

    return p;
}