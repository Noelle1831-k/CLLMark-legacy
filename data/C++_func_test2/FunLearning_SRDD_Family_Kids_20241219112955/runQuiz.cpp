bool runQuiz(string subject) {
    string question;
    string correctAnswer;
    if (subject == "Math") {
        question = generateMathQuestion();
        correctAnswer = "15"; 
    } else if (subject == "Science") {
        question = generateScienceQuestion();
        correctAnswer = "H2O";
    } else if (subject == "Language Arts") {
        question = generateLanguageArtsQuestion();
        correctAnswer = "Cat";
    } else if (subject == "Social Studies") {
        question = generateSocialStudiesQuestion();
        correctAnswer = "George Washington";
    }
    return askQuestion(question, correctAnswer);
}