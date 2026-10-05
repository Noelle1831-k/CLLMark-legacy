vector<string> SongDatabase::getSongsByMood(string mood) {
    if (moodToSongs.find(mood) != moodToSongs.end()) {
        return moodToSongs[mood];
    }
    return {};
}