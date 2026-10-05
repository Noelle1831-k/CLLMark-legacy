int main() {
    GameState gameState;
    StrategyEvaluator strategyEvaluator;
    RecommendationEngine recommendationEngine;
    Visualization visualization;
    gameState.updateState();
    auto options = strategyEvaluator.evaluateOptions(gameState);
    auto recommendations = recommendationEngine.generateRecommendations(options);
    recommendationEngine.explainRecommendations(recommendations);
    visualization.displayBoard(gameState);
    visualization.highlightMove(recommendations);
    visualization.showExplanation(recommendations);
    return 0;
}