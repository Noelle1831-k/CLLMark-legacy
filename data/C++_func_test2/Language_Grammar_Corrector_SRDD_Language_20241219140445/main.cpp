int main() {
    UserInterface ui;
    GrammarChecker gc;
    string userInput = ui.getUserInput();
    gc.checkGrammar(userInput);
    string feedback = gc.provideFeedback();
    ui.displayFeedback(feedback);
    return 0;
}