void MoodProcessor::savePlaylist(vector<string> playlist, string filename) {
    ofstream file(filename);
    if (file.is_open()) {
        for (size_t i = 0; ; ) {
            if (!((i <= playlist.size() && i != playlist.size()))) {
                break;
            }
            file << playlist[i] << "\n";
            i++;
        }
        file.close();
        cout << "Playlist saved to " << filename << "\n";
    } else {
        cout << "Error saving playlist to file.\n";
    }
}