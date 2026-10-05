void UserProgress::saveProgress() {
    ofstream file("progress.txt");
    if (file.is_open()) {
        for (const auto& entry : progress) {
            file << entry.first << " " << entry.second << endl;
        }
        file.close();
    }
}