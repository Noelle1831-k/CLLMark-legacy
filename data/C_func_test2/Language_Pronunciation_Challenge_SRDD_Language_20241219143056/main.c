int main(int argc, char *argv[]) {
    printf("Welcome to the Language Pronunciation Challenge!\n");
    loadLanguages();
    selectLanguage();
    selectDifficulty();
    loadChallenges();
    playRecording();
    recordUser();
    analyzePronunciation();
    displayFeedback();
    saveProgress();
    printf("Thank you for using the Language Pronunciation Challenge. Goodbye!\n");
    return 0;
}