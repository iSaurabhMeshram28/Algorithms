#include <iostream>
#include <vector>
#include <string>
#include <limits> // Add this line to include the necessary header

struct Song {
    std::string name;
    int duration; // in seconds
};

// Custom swap function for swapping elements in a vector
void customSwap(Song& a, Song& b) {
    Song temp = a;
    a = b;
    b = temp;
}

void selectionSort(std::vector<Song>& playlist) {
    int n = playlist.size();

    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;

        for (int j = i + 1; j < n; ++j) {
            if (playlist[j].duration < playlist[minIndex].duration) {
                minIndex = j;
            }
        }

        // Use the custom swap function
        customSwap(playlist[minIndex], playlist[i]);
    }
}

void displayPlaylist(const std::vector<Song>& playlist) {
    std::cout << "\nPlaylist (sorted by duration):\n";
    for (const auto& song : playlist) {
        std::cout << "Song: " << song.name << ", Duration: " << song.duration << " seconds\n";
    }
}

int main() {
    std::vector<Song> playlist;

    std::cout << "Enter songs and durations (type 'end' for song name to end input):\n";
    while (true) {
        Song song;
        
        // Use std::getline to read the entire line for the song name
        std::cout << "Song: ";
        std::getline(std::cin, song.name);

        if (song.name == "end") {
            break;
        }

        std::cout << "Duration (seconds): ";
        std::cin >> song.duration;

        playlist.push_back(song);

        // Clear the input buffer to handle the newline character
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    selectionSort(playlist);
    displayPlaylist(playlist);

    return 0;
}
