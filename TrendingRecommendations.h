#include <iostream>
#include "RecommendationStrategy.h"
using namespace std;

class TrendingRecommendations : public RecommendationStrategy {
public:
    void showRecommendations() const override {
        cout << "Trending movies right now:" << endl;
        cout << "1. Oppenheimer" << endl;
        cout << "2. Barbie" << endl;
    }
};