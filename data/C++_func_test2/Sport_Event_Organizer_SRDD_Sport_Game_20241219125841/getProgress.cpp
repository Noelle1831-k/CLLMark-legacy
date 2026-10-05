void GameProgress::getProgress() {
    for (map<string, string>::iterator it = progress.begin(); it != progress.end(); it++) {
        cout << it->first << ": " << it->second << endl;
    }
}