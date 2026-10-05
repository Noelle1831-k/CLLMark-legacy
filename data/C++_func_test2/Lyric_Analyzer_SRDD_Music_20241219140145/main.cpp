int main() {
    string filePath;
    cout << "Enter the path to the lyrics file: ";
    cin >> filePath;
    string lyrics = Utils::readFile(filePath);
    if (lyrics.empty()) {
        cerr << "Error: Unable to read lyrics from the file." << endl;
        return 1;
    }
    TextProcessor textProcessor;
    string processedLyrics = textProcessor.preprocessLyrics(lyrics);
    LyricAnalyzer lyricAnalyzer(processedLyrics);
    map<string, int> wordFrequency = lyricAnalyzer.analyzeWordFrequency();
    lyricAnalyzer.printWordFrequency(wordFrequency);
    string rhymeScheme = lyricAnalyzer.analyzeRhymeScheme();
    cout << "Rhyme Scheme: " << rhymeScheme << endl;
    SentimentAnalyzer sentimentAnalyzer;
    string sentiment = sentimentAnalyzer.analyzeSentiment(processedLyrics);
    cout << "Sentiment: " << sentiment << endl;
    Visualization::visualizeWordFrequency(wordFrequency);
    return 0;
}