#include <string>
using namespace std;

class Moviefeature {
protected:
    string genre;

public:
    Moviefeature() : genre("Unknown") {}

    virtual void displayFeature() const = 0;  

    void setGenre(string& g){ 
        genre = g; 
    }
    string getGenre(){
        return genre;
    }

};
