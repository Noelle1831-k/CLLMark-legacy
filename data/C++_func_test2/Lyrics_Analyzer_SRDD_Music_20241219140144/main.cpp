int main() {
    LyricsAnalyzer analyzer;
    string lyrics;
    cout << "Enter the lyrics of the song: ";
    getline(cin, lyrics);
    analyzer.loadLyrics(lyrics);
    analyzer.analyzeText();
    analyzer.analyzeSentiment();
    analyzer.analyzeRhymes();
    analyzer.visualizeData();
    analyzer.displayResults();
    return 0;
}