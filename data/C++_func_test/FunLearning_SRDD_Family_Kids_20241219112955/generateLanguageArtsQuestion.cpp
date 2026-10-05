string generateLanguageArtsQuestion() {
    string questions[] = {
        "Which of the following is a noun? (Cat, Run, Quickly)",
        "What is the past tense of 'run'?",
        "Choose the correct spelling: (Recieve, Receive)"
    };
    return questions[rand() % 3];
}