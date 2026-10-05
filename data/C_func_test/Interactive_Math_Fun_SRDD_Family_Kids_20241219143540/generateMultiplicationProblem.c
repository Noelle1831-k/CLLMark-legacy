void generateMultiplicationProblem() {
    int num1 = generateRandomNumber(1, 12), num2 = generateRandomNumber(1, 12), correctAnswer = num1 * num2, userAnswer = getUserInput();


    displayMessage("Solve the following problem:\n");
    printf("%d * %d = ?\n", num1, num2);

    if (validateAnswer(userAnswer, correctAnswer)) {
        displayMessage("Correct!\n");
        updateScore(10);
    } else {
        displayMessage("Incorrect. Try again!\n");
    }
}