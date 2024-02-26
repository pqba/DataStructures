#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H

#include "../Structures/DoublyLinkedList.h"
#include <string>

// Song struct with title, artist, and length
struct Song {
    std::string title;
    std::string musician;
    std::string albumCover;
    uint16_t length;
    Song(std::string t,std::string mus,std::string ac,uint16_t len) {
        title = t; musician = mus; length = len; albumCover = ac;
    }
    ~Song(){
        title = musician = albumCover = "N/A";
        length = 0;
    }
    std::string display() {
        return title + "|" + musician + "|" + std::to_string(length) + "\n" + albumCover;
    }
    bool operator==(const Song& other){
        return other.title == title && other.musician == musician && other.albumCover == albumCover && other.length == length;
    }
};


// Music player implementation using DoublyLinkedList
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
        Node<Song> * makeNode(Song s);

        int playlistSize();
        
        void addSong(Song);
        void removeSong(Song);

        void display();

};
#endif