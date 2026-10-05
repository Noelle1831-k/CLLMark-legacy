void TextProcessor::wordFrequency() {
    for (size_t i = 0; i < words.size(); ++i) {
        wordFrequencyMap[words[i]]++;
    }
}