#include "../../include/Common/MusicPlayer.h"

#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> generateANSIColors();

// ANSI Reference: https://en.wikipedia.org/wiki/ANSI_escape_code
#define RESET "\033[0m"
std::vector<std::string> colors = generateANSIColors();
int smallest(int a, int b);

std::vector<std::string> generateANSIColors() {
    std::vector<std::string> ansi_seq;
    for (int i = 30; i <= 37; i++) {
        std::string code = std::to_string(i);
        std::string item = "\033[" + code + "m";
        ansi_seq.push_back(item);
        std::string second_code = std::to_string(i + 60);
        std::string second_item = "\033[" + second_code + "m";
        ansi_seq.push_back(second_item);
    }
    return ansi_seq;
}

// Makes Node pointer from Song
DLLNode<Song>* MusicPlayer::makeSong(Song s) {
    DLLNode<Song>* nd = new DLLNode<Song>(s);
    return nd;
}
// Adds song to end of playlist
void MusicPlayer::addSong(Song s) {
    DLLNode<Song>* nd = makeSong(s);
    playlist.add(nd);
}
// Returns playlist size.
int MusicPlayer::playlistSize() {
    return playlist.size();
}
// Displays playlist.
void MusicPlayer::display() {
    if (playlist.size() == 0) return;  // don't display empty playlist. Would throw error.
    int colorSize = colors.size();
    unsigned short colorCounter = 0;
    DLLNode<Song>* currSong = playlist.getHead();
    while (currSong != nullptr) {  // Use display() on Song data in sequenced color fashion.
        std::cout << colors.at(colorCounter) << currSong->data.display() << RESET << "\n";
        displayVisualizer(currSong->data);
        colorCounter++;
        if (colorCounter >= colorSize) {
            colorCounter = 0;
        }
        currSong = currSong->next;
    }
}

void MusicPlayer::displayVisualizer(const Song& song) {
    const int VISUALIZER_WIDTH = smallest(song.info().length(), 100);
    const int VISUALIZER_HEIGHT = 10;

    std::vector<int> waveform(VISUALIZER_WIDTH, 0);

    // Generate a simple waveform-like visualization
    for (int i = 0; i < VISUALIZER_WIDTH; i++) {
        waveform[i] = rand() % VISUALIZER_HEIGHT;
    }
    int colorInd = rand() % colors.size();
    // The acutal display
    for (int y = VISUALIZER_HEIGHT - 1; y >= 0; y--) {
        for (int x = 0; x < VISUALIZER_WIDTH; x++) {
            if (waveform[x] > y) {
                std::cout << colors.at(colorInd) << "#";
            } else {
                std::cout << RESET << " ";
            }
        }
        std::cout << RESET << "\n";
    }

    std::cout << "\n";
}

int smallest(int a, int b) {
    return a < b ? a : b;
}

void MusicPlayer::buildSong(int time) {
    std::cout << "Building song #" << time + 1 << " \n";
}

bool checkInput(const std::string& s) {
    if (s == "q" || s == "Q") {
        return false;
    } else {
        int L;
        try {
            L = std::stoi(s);
        } catch (const std::invalid_argument& e) {
            std::cout << "Invalid number format.\n";
            return true;
        }
        return (L < 0 || L > 1000);
    }
}
// Allow user input of playlists.
void MusicPlayer::buildPlaylist() {
    std::cout << "Creating new playlist..." << "\n";
    std::string songLen;
    do {
        std::cout << "How many songs? (Enter length in range 1-1000, '?' if unsure, 'q' to quit ): ";
        std::cin >> songLen;
    } while (checkInput(songLen));

    if (songLen != "q" && songLen != "Q") {
        int songAmt = std::stoi(songLen);
        for (int t = 0; t < songAmt; t++) {
            buildSong(t);
        }
    }
}