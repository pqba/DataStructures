#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H

#include "../Structures/DoublyLinkedList.h"
#include <string>

// Song struct with title, artist, and length
struct Song {
    std::string title;
    std::string artist;
    uint16_t length;
};


// Music player implementation using DoublyLinkedList
class MusicPlayer {
    private:
        DoublyLinkedList<Song> playlist;
    public:
        int playlistSize();
        
        void addSong(Song);
        void removeSong(Song);

};
#endif