int main() {
    GameState *gameState = createGameState();
    StrategyEvaluator *evaluator = createStrategyEvaluator();
    Visualization *visualization = createVisualization();
    while (!isGameOver(gameState)) {
        updateGameState(gameState);
        evaluateStrategies(evaluator, gameState);
        displayVisualization(visualization, gameState, evaluator);
    }
    destroyGameState(gameState);
    destroyStrategyEvaluator(evaluator);
    destroyVisualization(visualization);
    return 0;
}