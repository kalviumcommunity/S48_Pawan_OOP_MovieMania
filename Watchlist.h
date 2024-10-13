#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Watchlist {
private:
    vector<string> watchlist; 

public:
    Watchlist() {
        cout << "Watchlist created!" << endl;
    }

    Watchlist(vector<string> initialList) {
        watchlist = initialList;
        cout << "Watchlist initialized with movies!" << endl;
    }

    ~Watchlist() {
        cout << "Watchlist destroyed!" << endl;
    }

    void addMovie(const string &movie) {
        watchlist.push_back(movie);
        cout << "Movie added to watchlist: " << movie << endl;
    }

    void viewWatchlist() {
        if (watchlist.empty()) {
            cout << "Your watchlist is empty." << endl;
        } else {
            cout << "Your watchlist:" << endl;
            for (const auto &movie : watchlist) {
                cout << "- " << movie << endl;
            }
        }
    }

    void removeMovie(const string &movie) {
        auto it = find(watchlist.begin(), watchlist.end(), movie);
        if (it != watchlist.end()) {
            watchlist.erase(it);
            cout << "Movie removed from watchlist: " << movie << endl;
        } else {
            cout << "Movie not found in watchlist: " << movie << endl;
        }
    }
};

