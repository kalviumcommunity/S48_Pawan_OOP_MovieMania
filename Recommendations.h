#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
#include <vector>
#include<map>
#include "RecommendationStrategy.h"
using namespace std;

class Recommendations {
private:
    RecommendationStrategy* strategy;

public:
    Recommendations(RecommendationStrategy* strategy = nullptr) 
        : strategy(strategy) {}

    void setStrategy(RecommendationStrategy* newStrategy) {
        if (strategy) delete strategy;
        strategy = newStrategy;
    }

    void showRecommendations() const {
        if (strategy) {
            strategy->showRecommendations();
        } else {
            cout << "No recommendation strategy set!" << endl;
        }
    }

    ~Recommendations() {
        if (strategy) delete strategy;
    }
};
