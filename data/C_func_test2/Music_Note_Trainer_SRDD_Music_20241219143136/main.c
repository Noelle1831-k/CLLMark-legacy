int main(int argc, char *argv[]) {
    initializeApp();
    while (1) {
        startExercise();
        processUserInput();
    }
    saveUserData();
    return 0;
}