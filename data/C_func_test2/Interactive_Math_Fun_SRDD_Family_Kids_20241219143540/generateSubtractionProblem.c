void generateSubtractionProblem() {
    int num1 = generateRandomNumber(50, 100);
    int num2 = generateRandomNumber(1, 50);
    int correctAnswer = num1 - num2;
    displayMessage("Solve the following problem:\n");
    printf("%d - %d = ?\n", num1, num2);
    int userAnswer = getUserInput();
    if (validateAnswer(userAnswer, correctAnswer)) {
        displayMessage("Correct!\n");
        updateScore(10);
    } else {
        displayMessage("Incorrect. Try again!\n");
    }
}