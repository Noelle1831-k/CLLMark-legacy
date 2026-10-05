int main() {
    srand(time(0)); 
    Vocabulary vocab;
    vocab.addWord(Word("Hola", "Hello", "Greeting", 1));
    vocab.addWord(Word("Adios", "Goodbye", "Farewell", 1));
    vocab.addWord(Word("Gracias", "Thank you", "Politeness", 1));
    vector<Word> words = vocab.getAllWords();
    Quiz quiz(words);
    UserProfile user("JohnDoe");
    for (int i = 0; i < 3; i++) {
        quiz.generateQuestion();
        quiz.showScore();
    }
    quiz.trackProgress();
    user.updateScore(quiz.getScore());
    user.showProfile();
    return 0;
}