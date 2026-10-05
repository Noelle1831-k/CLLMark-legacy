int main(void) {
    initializeApp();
    while (1) {
        startExercise();
        processUserInput();
    }
    saveUserData();
    return 0;
}