#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
#include <vector>
#include<map>
using namespace std;

class Recommendations{
    private:
        vector<string> genres;
        map<string, vector<string>> moviesByGenre;


    public:
        Recommendations() {
        // Populate some sample genres and movies
        genres = {"Action", "Comedy", "Drama", "Horror", "Sci-Fi"};
        moviesByGenre = {
            {"Action", {"Mad Max: Fury Road", "John Wick", "Gladiator"}},
            {"Comedy", {"Superbad", "The Hangover", "Step Brothers"}},
            {"Drama", {"The Godfather", "Forrest Gump", "The Shawshank Redemption"}},
            {"Horror", {"The Exorcist", "Get Out", "A Nightmare on Elm Street"}},
            {"Sci-Fi", {"Inception", "The Matrix", "Interstellar"}}
        };
        }

        void showRecommendations() {
        cout << "Available genres: ";
        for (const auto& genre : genres) {
            cout << genre << " ";
        }
        cout << endl;

        string chosenGenre;
        cout << "Enter a genre to get recommendations: ";
        cin.ignore();
        getline(cin, chosenGenre);

        auto it = moviesByGenre.find(chosenGenre);
        if (it != moviesByGenre.end()) {
            cout << "Movies recommended for " << chosenGenre << " genre:" << endl;
            for (const auto& movie : it->second) {
                cout << "- " << movie << endl;
            }
        } else {
            cout << "Sorry, no recommendations available for the chosen genre." << endl;
        }
    }


};
