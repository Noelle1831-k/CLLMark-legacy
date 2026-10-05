void PlaylistGenerator::generatePlaylist(const vector<string>& recommendedTracks) {
    playlist.clear();
    for (vector<string>::const_iterator it = recommendedTracks.begin(); it != recommendedTracks.end(); ++it) {
        playlist.push_back(*it);
    }
}