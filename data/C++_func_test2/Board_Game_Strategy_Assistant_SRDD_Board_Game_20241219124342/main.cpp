int main() {
    cout << "Welcome to the Advanced Board Game Strategy Assistant!" << endl;
    GameState gameState;
    StrategyEngine strategyEngine;
    Visualization visualization;
    while (true) {
        cout << "\nUpdating game state..." << endl;
        gameState.updateState();
        cout << "\nAnalyzing game state..." << endl;
        strategyEngine.analyzeState(gameState);
        cout << "\nGenerating optimal move..." << endl;
        string optimalMove = strategyEngine.generateOptimalMove(gameState);
        cout << "Optimal Move: " << optimalMove << endl;
        cout << "\nGenerating counter-move..." << endl;
        string counterMove = strategyEngine.generateCounterMove(gameState);
        cout << "Counter Move: " << counterMove << endl;
        cout << "\nRendering board visualization..." << endl;
        visualization.renderBoard(gameState);
        cout << "\nExplaining strategy..." << endl;
        visualization.explainStrategy(optimalMove, counterMove);
        cout << "\nDo you want to continue? (y/n): ";
        char choice;
        cin >> choice;
        if (choice == 'n' || choice == 'N') {
            break;
        }
    }
    cout << "Thank you for using the Advanced Board Game Strategy Assistant!" << endl;
    return 0;
}