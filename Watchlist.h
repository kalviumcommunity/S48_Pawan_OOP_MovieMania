#include "MovieFeature.h"
#include <vector>
#include <algorithm>

class Watchlist : public MovieFeature {
private:
    vector<string> watchlist;

public:
    Watchlist() : MovieFeature("User's personalized watchlist", "Variety") {
        cout << "Watchlist created!" << endl;
    }

    void addMovie(string movie) {
        watchlist.push_back(movie);
        cout << "Movie added to watchlist: " << movie << endl;
    }

    void viewWatchlist() {
        if (watchlist.empty()) {
            cout << "Your watchlist is empty." << endl;
        } else {
            cout << "Your watchlist:" << endl;
            for (auto movie : watchlist) {
                cout << "- " << movie << endl;
            }
        }
    }

    void removeMovie(string movie) {
        auto it = find(watchlist.begin(), watchlist.end(), movie);
        if (it != watchlist.end()) {
            watchlist.erase(it);
            cout << "Movie removed from watchlist: " << movie << endl;
        } else {
            cout << "Movie not found in watchlist: " << movie << endl;
        }
    }
};
