string TextProcessor::preprocessLyrics(const string& lyrics) {
    string processedLyrics = lyrics;
    processedLyrics.erase(remove_if(processedLyrics.begin(), processedLyrics.end(), 
        [](char c) { return !isalpha(c) && !isspace(c); }), processedLyrics.end());
    transform(processedLyrics.begin(), processedLyrics.end(), processedLyrics.begin(), ::tolower);
    return processedLyrics;
}