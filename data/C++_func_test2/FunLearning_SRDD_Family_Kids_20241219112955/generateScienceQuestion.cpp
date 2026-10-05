string generateScienceQuestion() {
    string questions[] = {
        "What is the chemical symbol for water?",
        "Which planet is known as the Red Planet?",
        "What is the process by which plants make their food?",
        "What gas do plants absorb during photosynthesis?"
    };
    return questions[rand() % 4];
}