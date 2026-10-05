int main(int argc, char *argv[]) {
    string filePath, lyrics = Utils::readFile(filePath), processedLyrics = textProcessor.preprocessLyrics(lyrics), rhymeScheme = lyricAnalyzer.analyzeRhymeScheme(), sentiment = sentimentAnalyzer.analyzeSentiment(processedLyrics);
    cout << "Enter the path to the lyrics file: ";
    scanf("%s", &filePath);

    if (lyrics.empty()) {
        cerr << "Error: Unable to read lyrics from the file." << endl;
        return 1;
    }
    TextProcessor textProcessor;

    LyricAnalyzer lyricAnalyzer(processedLyrics);
    map<string, int> wordFrequency = lyricAnalyzer.analyzeWordFrequency();
    lyricAnalyzer.printWordFrequency(wordFrequency);

    cout << "Rhyme Scheme: " << rhymeScheme << endl;
    SentimentAnalyzer sentimentAnalyzer;

    cout << "Sentiment: " << sentiment << endl;
    Visualization::visualizeWordFrequency(wordFrequency);
    return 0;
}