#include <bits/stdc++.h>

#include <iostream>

using namespace std;

vector<float> x = {1.0, 0.7, 1.2};
int lenx = x.size();
vector<vector<float>> w = {{0.5, 1.5, 0.8, 0.9, -1.7, 1.6},
                           {0.8, 0.2, -1.6, 1.2, 2.1, -0.2}};
int lenw = w.size();

vector<float> _true = {1, 0};
vector<int> loss;

float mean_squared_error(vector<float> y, vector<float> y_pred) {
    int n = y.size();
    float sum = 0;
    for (int i = 0; i < n; i++) {
        sum +=pow((y[i] - y_pred[i]), 2);
    }

    return sum / n;
}

int main() {
    vector<float> layer2;
    vector<float> layer1 = {1};
    for (int iter = 0; iter < 10000000; iter++) {
        layer1 = {1};
        layer2 = {};

        for (int j = 0; j < lenw; j++) {
            float sum = 0;
            for (int i = 0; i < lenx; i++) {
                sum += x[i]*w[j][i];
            }
            layer1.push_back(1/(1 + exp(-sum)));
        }

        int lenlayer1 = layer1.size();
        for (int j = 0; j < lenw; j++) {
            float sum = 0;
            for (int i = 0; i < lenlayer1; i++) {
                sum += layer1[i]*w[j][3+i];
            }
            layer2.push_back(1/1 + exp(-sum));
        }

        float del12 = (layer2[0] - _true[0])*layer2[0]*(1-layer2[0]);
        float del22 = (layer2[1] - _true[1])*layer2[1]*(1-layer2[1]);
        
        float del11 = layer1[1]*(1-layer1[1])*((del12*w[0][3+1])+(del22*w[1][3+1]));
        float del21 = layer1[2]*(1-layer1[2])*((del12*w[0][3+2])+(del22*w[1][3+2]));

        vector<vector<float>> delta = {{del11, del21}, 
                                       {del12, del22}};

        for (int i = 0; i < lenw; i++) {
            for (int j = 0; j < (int) lenw/2; j++) {
                w[i][j] -= 0.5*(delta[0][i]*x[j]);
            }
        }

        for (int i = 0; i < lenw; i++) {
            for (int j = 0; j < (int) lenw/2; j++) {
                w[i][3+j] -= 0.5*(delta[1][i]*layer1[j]);
            }
        }

        float val = mean_squared_error(_true, layer2);

        loss.push_back(val);
        // cout << "**********************************\n";
        // cout << "Weight Vector after iteration: " << iter+1 << "\n";
        // // cout << w << "\n";
        // cout << "**********************************\n";
    }

    // cout << layer2 << "\n";
    // cout << loss << "\n";
}
