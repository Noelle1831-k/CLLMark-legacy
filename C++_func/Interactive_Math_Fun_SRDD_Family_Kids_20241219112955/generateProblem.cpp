void MathGame::generateProblem() {
    operand1 = Utils::generateRandomNumber(1, 10);
    operand2 = Utils::generateRandomNumber(1, 10);
    int opType = Utils::generateRandomNumber(1, 3);
    if (opType == 1) operation = '+';
    else if (opType == 2) operation = '-';
    else operation = '*';
}