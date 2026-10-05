void MusicPlayerExporter::exportToPlayer() {
    cout << "Exporting playlist to music player..." << endl;
    for (vector<string>::iterator it = playlist.begin(); it != playlist.end(); ++it) {
        cout << "Exporting: " << *it << endl;
    }
}