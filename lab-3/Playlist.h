#ifndef PLAYLIST_
#define PLAYLIST_

enum Mode { LOOP, RANDOM, ONCE };

template<class ItemType>
class Playlist {
	private:
		static const int DEFAULT_CAPACITY = 100;
		int songCount; // keeps track of amount of songs in playlist
		int currentSongPosition; // keeps track of where in the playlist we are
		ItemType songs[DEFAULT_CAPACITY]; // songs in playlist
		ItemType history[DEFAULT_CAPACITY]; // history array that keeps track of what songs have been played
		Mode currentMode; // the current mode the playlist is in
	public:
		Playlist();
		// because we're using an array-based implementation we can use the default copy constructor to copy playlists
		void setMode(Mode newMode); // switches the value of the current mode taking in the Mode enum value to switch to
		bool addSong(const ItemType& newSong); // adds a new song to the songs array
		bool removeSong(const ItemType& song); // takes a song input and tries to find and remove it from the existing songs array
		ItemType skip() const; // skips the current song and returns the song it skipped to
		bool pause() const; // pauses the playlist
		void savePlaylist(const Playlist<ItemType>& playlist) const; // takes a playlist input and writes it to a file to save the playlist and its current mode
		void shufflePlaylist(); // re-orders the song array
		ItemType nextSong() const; // returns the next song that's to be played next
		ItemType peekNextSong() const; // returns the next song in order
		ItemType previousSong() const; // returns the last played song from the history list
};

#endif