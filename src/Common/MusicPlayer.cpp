#include "../../include/Common/MusicPlayer.h"
#include <iostream>
#include <vector>
#include <string>

std::vector<std::string> generateANSIColors();

// ANSI Reference: https://en.wikipedia.org/wiki/ANSI_escape_code
#define RESET   "\033[0m"
std::vector<std::string> colors = generateANSIColors();

std::vector<std::string> generateANSIColors(){
    std::vector<std::string> ansi_seq;
     for(int i = 30; i <= 37; i++) {
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
Node<Song> * MusicPlayer::makeNode(Song s){
    Node<Song> * nd = new Node<Song>(s);
    return nd;
}
// Adds song to end of playlist
void MusicPlayer::addSong(Song s){
    Node<Song> * nd = makeNode(s);
    playlist.add(nd);
}
// Returns playlist size.
int MusicPlayer::playlistSize(){
    return playlist.size();
}
// Displays playlist.
void MusicPlayer::display(){
    if(playlist.size() == 0) return; // don't display empty playlist. Would throw error.
    int colorSize = colors.size();
    unsigned short colorCounter = 0;
    Node<Song> * currSong = playlist.getHead();
    while(currSong != nullptr){ // Use display() on Song data in sequenced color fashion.
        std::cout << colors.at(colorCounter) << currSong->data.display() << RESET << std::endl;
        colorCounter++;
        if(colorCounter >= colorSize){
            colorCounter = 0;
        }
        currSong = currSong->next;
    }
}