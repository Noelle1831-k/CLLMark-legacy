void Phrasebook::displayPhrase(int index) {
    if (index >= 0 && index < phrases.size()) {
        Phrase phrase = phrases[index];
        std::cout << "Native Phrase: " << phrase.getNativePhrase() << std::endl;
        std::cout << "Target Phrase: " << phrase.getTargetPhrase() << std::endl;
        std::cout << "Example Sentence: " << phrase.getExampleSentence() << std::endl;
        std::cout << "Audio Path: " << phrase.getAudioFilePath() << std::endl;
    } else {
        std::cout << "Invalid index. Unable to display the phrase." << std::endl;
    }
}