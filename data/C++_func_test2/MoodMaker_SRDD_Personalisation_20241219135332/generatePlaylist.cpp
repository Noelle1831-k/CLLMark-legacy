vector<string> MoodProcessor::generatePlaylist(string mood) {
    SongDatabase db;
    vector<string> songs = db.getSongsByMood(mood);
    if (songs.empty()) {
        cout << "No songs found for the mood: " << mood << "\n";
    }
    return songs;
}