char* generateQuestion(int language, int difficulty) {
    Word word = selectWord(language, difficulty);
    int questionType = generateRandomNumber(1, 3); 
    if (questionType == 1) {
        return generateSynonymQuestion(word);
    } else if (questionType == 2) {
        return generateAntonymQuestion(word);
    } else {
        return generateMeaningQuestion(word);
    }
}