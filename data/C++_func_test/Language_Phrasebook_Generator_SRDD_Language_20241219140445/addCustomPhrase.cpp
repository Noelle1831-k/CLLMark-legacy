void Phrasebook::addCustomPhrase() {
    std::string exampleSentence;
    std::string nativePhrase;
    std::string targetPhrase;
    std::string audioPath;
    
    std::cout << "Enter the phrase in native language: ";
    std::cin.ignore(); 
    std::getline(std::cin, nativePhrase);
    std::cout << "Enter the translation in target language: ";
    std::getline(std::cin, targetPhrase);
    std::cout << "Enter an example sentence: ";
    std::getline(std::cin, exampleSentence);
    std::cout << "Enter the audio file path: ";
    std::getline(std::cin, audioPath);
    Phrase newPhrase(nativePhrase, targetPhrase, audioPath, exampleSentence);
    addPhrase(newPhrase);
}