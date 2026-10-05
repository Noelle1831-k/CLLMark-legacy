int main() {
    Dictionary dictionary;
    dictionary.loadDictionary("dictionary.txt");
    WordFinder wordFinder(dictionary);
    string inputLetters;
    cout << "Enter the available letters: ";
    cin >> inputLetters;
    vector<string> validWords = wordFinder.findWords(inputLetters);
    cout << "Valid words: " << endl;
    for (int i = 0; i < validWords.size(); i++) {
        cout << validWords[i] << endl;
    }
    cout << "Total valid words found: " << validWords.size() << endl;
    return 0;
}