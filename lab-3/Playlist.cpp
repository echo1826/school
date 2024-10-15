#include "Playlist.h"
#include <stdexcept>

template<class ItemType>
Playlist<ItemType>::Playlist() : maxSongs(DEFAULT_CAPACITY), songCount(0), currentMode(ONCE) {}

template<class ItemType>
void Playlist<ItemType>::setMode(Mode newMode) {
    currentMode = newMode;
}

template<class ItemType>
bool Playlist<ItemType>::addSong(const ItemType& song) {
    if(maxSongs == songCount) {
        return false;
    }

}

template<class ItemType>
bool Playlist<ItemType>::removeSong(const ItemType& song) {
     return false;
}

template<class ItemType>
void Playlist<ItemType>::skip() const {

}

template<class ItemType>
void Playlist<ItemType>::pause() const {

}

template<class ItemType>
void Playlist<ItemType>::savePlaylist(const Playlist<ItemType>& playlist) const {

}

template<class ItemType>
void Playlist<ItemType>::shufflePlaylist() {

}

template<class ItemType>
void Playlist<ItemType>::nextSong() const {

}

template<class ItemType>
ItemType Playlist<ItemType>::peekNextSong() const {
    if(currentSongPosition == songCount - 1) {
        throw(std::invalid_argument("peekNextSong() with an empty playlist or invalid position"));
    }
    return songs[currentSongPosition + 1];
}