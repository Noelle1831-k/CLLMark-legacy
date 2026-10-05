string UserInterface::getFilePath() {
    string filePath;
    cout << "Enter the path to the music file (WAV, MP3, etc.): ";
    scanf("%s", &filePath);
    return filePath;
}