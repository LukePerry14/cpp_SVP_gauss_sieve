#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cctype>
#include <random>
#include <fstream>

#include "vectors.h"
#include "Gauss.h"

using namespace std;

vector<vector<float>> processArgs(int argc, char** argv, int vecnum){

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
    int vecnum = sqrt(argc-1);

    if (vecnum * vecnum != argc-1) {
        cerr << "Invalid Argument Size" << endl;
        exit(EXIT_FAILURE);
    }
    
    vector<vector<float>> basis = processArgs(argc, argv, vecnum);

    float smallest = GaussSieve(basis, vecnum);

    cout << smallest << endl;

    ofstream outputFile("result.txt");

    if(outputFile.is_open()){
        outputFile << smallest << endl;
        outputFile.close();
    } else {
        cerr << "Error writing result to file" << endl;
    }

    return 0;
}
