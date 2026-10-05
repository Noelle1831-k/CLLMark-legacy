void UserProgress::loadProgress() {
    ifstream file("progress.txt");
    if (file.is_open()) {
        string scale;
        int count;
        while (file >> scale >> count) {
            progress[scale] = count;
        }
        file.close();
    }
}