#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>

class GameDataManager {
private:
    string filename;

public:
    GameDataManager(const string& file) : filename(file) {}

    void loadGameData(int& totalPlayers, int& globalHighScore) {
        ifstream file(filename);
        if (file.is_open()) {
            file >> totalPlayers;
            file >> globalHighScore;
            file.close();
        } else {
            totalPlayers = 0;
            globalHighScore = 0;
        }
    }

    void saveGameData(int totalPlayers, int globalHighScore) {
        ofstream file(filename);
        if (file.is_open()) {
            file << totalPlayers << endl;
            file << globalHighScore << endl;
            file.close();
        } else {
            cerr << "Error: Unable to save game data!" << endl;
        }
    }
};
