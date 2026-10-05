string UserInterface::getFilePath() {
    string filePath;
    cout << "Enter the path to the music file (WAV, MP3, etc.): ";
    cin >> filePath;
    return filePath;
}