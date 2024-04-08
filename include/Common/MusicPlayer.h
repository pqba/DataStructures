#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H

#include "../Structures/DoublyLinkedList.h"
#include <string>


// Song struct with title, artist, and length
struct Song {
    std::string title;
    std::string musician;
    std::string albumCover;
    int32_t length;
    Song(std::string t,std::string mus,std::string ac,int32_t len) {
        title = t; musician = mus; length = len; albumCover = ac;
    }
    ~Song(){
        title = musician = albumCover = "N/A";
        length = 0;
    }
    std::string songLength() const {
        int32_t minutes = length % 60;
        int32_t seconds = length / 60;
        std::string minString = std::to_string(minutes);
        std::string secString = std::to_string(seconds); 
        if(minutes < 10){
            minString = "0" + minString;
        }
        if(seconds < 10){
            secString = "0" + secString;
        }
        return minString + ":" + secString;
    }   
    std::string info() const {
        return title + " | " + musician + " | " + songLength() + "\n";
    }
    std::string display() const {
        return info() + albumCover;
    }
    bool operator==(const Song& other){
        return other.title == title && other.musician == musician && other.albumCover == albumCover && other.length == length;
    }
};


// Music Player implementation using DoublyLinkedList
class MusicPlayer {
    private:
        DoublyLinkedList<Song> playlist;
    public:
        MusicPlayer(){
            playlist = DoublyLinkedList<Song>();
        }
        ~MusicPlayer(){
            playlist.clear();
        }
        DoublyLinkedNode<Song> * makeSong(Song s);

        int playlistSize();
        
        void addSong(Song);
        void removeSong(Song);

        void buildSong(int);
        void buildPlaylist();

        void display();
        void displayVisualizer(const Song&);

};

#endif
