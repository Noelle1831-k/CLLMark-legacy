void SheetMusicExporter::export(string filename, vector<pair<string, int>> sequence) {
    cout << "Exporting to sheet music file: " << filename << endl;
    for (const auto& chord : sequence) {
        cout << "Chord: " << chord.first << ", Duration: " << chord.second << endl;
    }
}