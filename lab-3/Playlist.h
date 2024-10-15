#ifndef PLAYLIST_
#define PLAYLIST_

enum Mode { LOOP, RANDOM, ONCE };

template<class ItemType>
class Playlist {
	private:
		static const int DEFAULT_CAPACITY = 100;
		int songCount;
		int maxSongs;
		int currentSongPosition;
		ItemType songs[DEFAULT_CAPACITY];
		ItemType history[DEFAULT_CAPACITY];
		Mode currentMode;
	public:
		Playlist();
		void setMode(Mode newMode);
		bool addSong(const ItemType& newSong);
		bool removeSong(const ItemType& song);
		void skip() const;
		void pause() const;
		void savePlaylist(const Playlist<ItemType>& playlist) const;
		void shufflePlaylist();
		void nextSong() const;
		ItemType peekNextSong() const;
};

#include "Playlist.cpp"
#endif