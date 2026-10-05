int main() {
    cout << "Welcome to the Board Game Strategy Analyzer!" << endl;
    Player player1("Alice", 1);
    Player player2("Bob", 2);
    GameState gameState;
    gameState.resetState();
    StrategyAnalyzer analyzer;
    Visualization visualizer;
    int choice = 0;
    while (choice != 5) {
        displayMenu();
        cin >> choice;
        switch (choice) {
            case 1: {
                cout << "Enter move details for Player 1: ";
                string moveDetails1;
                cin >> moveDetails1;
                Move move1(player1.getID(), moveDetails1);
                if (move1.validateMove()) {
                    gameState.updateState(move1);
                } else {
                    cout << "Invalid move for Player 1!" << endl;
                }
                cout << "Enter move details for Player 2: ";
                string moveDetails2;
                cin >> moveDetails2;
                Move move2(player2.getID(), moveDetails2);
                if (move2.validateMove()) {
                    gameState.updateState(move2);
                } else {
                    cout << "Invalid move for Player 2!" << endl;
                }
                break;
            }
            case 2:
                gameState.displayState();
                break;
            case 3:
                analyzer.analyzeStrategies(gameState);
                cout << "Strategies analyzed successfully!" << endl;
                break;
            case 4:
                visualizer.generateGraphs(analyzer.getAnalysisResults());
                break;
            case 5:
                cout << "Exiting the application. Thank you for using the Board Game Strategy Analyzer!" << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }
    return 0;
}