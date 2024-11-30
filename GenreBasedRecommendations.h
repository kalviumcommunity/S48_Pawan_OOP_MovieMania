#include <iostream>
#include "RecommendationStrategy.h"
using namespace std;

class GenreBasedRecommendations : public RecommendationStrategy {
public:
    void showRecommendations() const override {
        cout << "Recommended movies based on your favorite genre:" << endl;
        cout << "1. Inception (Sci-Fi)" << endl;
        cout << "2. The Shawshank Redemption (Drama)" << endl;
    }
};

