#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// Struct for artist information
struct Artist {
    string name;
    string hometown;
};

// Struct for song information
struct Song {
    string title;
    Artist artist;
    string genre;
    int durationSeconds;
};

// Function Prototypes
string formatDuration(int seconds);
void displaySong(const Song& song);

// Main Function
int main() {

    // Program title
    cout << "PERSONAL PLAYLIST MANAGER" << endl;
    cout << "--------------------------" << endl;
   
    // Create array of 5 songs
    Song playlist[5];

    // Input 5 songs from user
    for (int i =0; i<5; i++) {
        cout << "\nEnter information for song " << i +1 <<":" << endl;

        cout << "Title: ";
        getline(cin, playlist[i].title);

        cout << "Artist name: ";
        getline(cin, playlist[i].artist.name);

        cout << "Artist hometown: ";
        getline(cin, playlist[i].artist.hometown);

        cout << "Genre: ";
        getline(cin, playlist[i].genre);

        cout << "Duration (seconds): ";
        cin >> playlist[i].durationSeconds;
        cin.ignore();
    }

    // Display full playlist
    cout << "\nYOUR PLAYLIST:" << endl;
    cout <<  "-------------" << endl;

    for (int i = 0; i < 5; i++) {
        cout << i + 1 << ". ";
        displaySong(playlist[i]);
        cout << endl;
    }

    // Calculate total runtime and longest song
    int totalDuration = 0;
    int longestSongIndex = 0;

    for (int i = 0; i < 5; i++) {
        totalDuration += playlist[i].durationSeconds;

        if (playlist[i].durationSeconds > playlist[longestSongIndex].durationSeconds) {
            longestSongIndex = i;
        }
    }

    // Display playlist statistics
    cout << "Playlist Stats:" << endl;
    cout << "  Total runtime: " << formatDuration(totalDuration) << endl;
    cout << "  Longest song: " << playlist[longestSongIndex].title << " (" << formatDuration(playlist[longestSongIndex].durationSeconds) << ")" << endl;

    // Search songs by artist
    string searchArtist;
    bool foundartist = false;

    while (!foundartist) {
        cout << "\nSearch by artist: ";
        getline (cin, searchArtist );

        string lowerSearchArtist = searchArtist;
        for (char &ch : lowerSearchArtist) {
            ch = tolower(ch);
        }

        cout << "Songs by " << searchArtist << ":" << endl;

        foundartist = false;

        for (int i = 0; i < 5; i++) {
            string artistName = playlist[i].artist.name;

            for (char &c : artistName) {
                c = tolower(c);
            }

            if (artistName == lowerSearchArtist) {
                cout << "  - " << playlist[i].title << " (" << formatDuration(playlist[i].durationSeconds) << ")" << endl;
                foundartist = true;
            } 
        }
        if (!foundartist) {
            cout << "No songs found for that artist. Please try again." << endl;
        }
    }
    
    // Search songs by genre
    string searchGenre;
    bool foundGenre = false;
    
    while (!foundGenre) {
        cout << "\nSearch by genre: ";
        getline(cin, searchGenre);

        string lowerSearchGenre = searchGenre;

        for (char &ch : lowerSearchGenre) {
            ch = tolower(ch);
        }

        cout << "Songs in genre " << "\"" << searchGenre << "\"" << ":" << endl;

        foundGenre = false;

        for (int i = 0; i < 5; i++) {
            string genre = playlist[i].genre;

            for (char &c : genre) {
                c = tolower(c);
            }
            if (genre == lowerSearchGenre) {
                cout << "  - " << playlist[i].title << " (" << formatDuration(playlist[i].durationSeconds) << ")" << endl;
                foundGenre = true;
            }
        }
        if(!foundGenre) {
            cout << " No songs found in that genre. Please try again." << endl; 
        }
    }

    return 0;
}

// Convert seconds into M:SS format
string formatDuration(int seconds) {
    int minutes = seconds / 60;
    int remainSeconds = seconds % 60;

    string minutesResult = to_string(minutes);    
    string secondsPart;

    if (remainSeconds < 10) {
        secondsPart = "0" + to_string(remainSeconds);

    }
    else {
        secondsPart = to_string(remainSeconds);
    }

    string result = minutesResult + ":" + secondsPart;

    return result;
}

// Display song's full information
void displaySong(const Song& song) {
    cout << song.title << endl;
    cout << "   Artist: " << song.artist.name << " (" << song.artist.hometown << ")" << endl;
    cout << "   Genre: " << song.genre << endl;
    cout << "   Duration: " << formatDuration(song.durationSeconds) << endl;

}