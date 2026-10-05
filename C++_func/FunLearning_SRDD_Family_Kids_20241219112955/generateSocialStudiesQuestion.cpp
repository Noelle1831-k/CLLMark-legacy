string generateSocialStudiesQuestion() {
    string questions[] = {
        "Who was the first president of the United States?",
        "What is the capital of France?",
        "In which continent is Egypt located?"
    };
    return questions[rand() % 3];
}