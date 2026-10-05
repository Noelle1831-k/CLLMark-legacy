void MoodProcessor::savePlaylist(vector<string> playlist, string filename) {
    ofstream file(filename);
    if (file.is_open()) {
        for (size_t i = 0; i < playlist.size(); ++i) {
            file << playlist[i] << "\n";
        }
        file.close();
        cout << "Playlist saved to " << filename << "\n";
    } else {
        cout << "Error saving playlist to file.\n";
    }
}