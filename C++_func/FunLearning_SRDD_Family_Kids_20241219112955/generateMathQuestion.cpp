string generateMathQuestion() {
    int num1 = rand() % 10 + 1;
    int num2 = rand() % 10 + 1;
    string question = "What is " + to_string(num1) + " + " + to_string(num2) + "?";
    return question;
}