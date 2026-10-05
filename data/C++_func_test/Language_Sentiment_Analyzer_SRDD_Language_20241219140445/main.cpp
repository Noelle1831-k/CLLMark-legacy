int main(int argc, char *argv[]) {
    DictionaryLoader dictLoader;
    dictLoader.loadFile("positive.txt", dictLoader.getPositiveWords());
    dictLoader.loadFile("negative.txt", dictLoader.getNegativeWords());
    dictLoader.loadFile("neutral.txt", dictLoader.getNeutralWords());
    SentimentAnalyzer analyzer(dictLoader);
    string inputText;
    cout << "Enter a text to analyze sentiment: ";
    getline(cin, inputText);
    string sentiment = analyzer.analyzeSentiment(inputText);
    cout << "Sentiment Analysis Result: " << sentiment << endl;
    return 0;
}