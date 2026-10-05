void MoodProcessor::sharePlaylist(vector<string> playlist) {
    cout << "Sharing playlist:\n";
    for (size_t i = 0; i < playlist.size(); ++i) {
        cout << "- " << playlist[i] << "\n";
    }
}