string PracticeMaterial::getRandomPhrase() {
    if (phrases.empty()) {
        return "No phrases available.";
    }
    int randomIndex = rand() % phrases.size();
    return phrases[randomIndex];
}