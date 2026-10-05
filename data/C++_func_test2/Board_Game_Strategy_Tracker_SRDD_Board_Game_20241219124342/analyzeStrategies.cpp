void StrategyAnalyzer::analyzeStrategies(const GameState& gameState) {
    analysisResults.clear();
    vector<Move> moves = gameState.getMoveHistory();
    for (int i = 0; i < moves.size(); i++) {
        string result = "Move " + to_string(i + 1) + ": Player " + to_string(moves[i].getPlayerID()) + " made move '" + moves[i].getMoveDetails() + "'";
        analysisResults.push_back(result);
    }
}