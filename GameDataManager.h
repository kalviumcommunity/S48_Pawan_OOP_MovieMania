class GameDataManager {
public:
    static void loadGameData(int& totalPlayers, int& globalHighScore) {
        ifstream file("game_data.txt");
        if (file.is_open()) {
            file >> totalPlayers;
            file >> globalHighScore;
            file.close();
        } else {
            totalPlayers = 0;
            globalHighScore = 0;
        }
    }

    static void saveGameData(int totalPlayers, int globalHighScore) {
        ofstream file("game_data.txt");
        if (file.is_open()) {
            file << totalPlayers << endl;
            file << globalHighScore << endl;
            file.close();
        } else {
            cerr << "Error: Unable to save game data!" << endl;
        }
    }
};
