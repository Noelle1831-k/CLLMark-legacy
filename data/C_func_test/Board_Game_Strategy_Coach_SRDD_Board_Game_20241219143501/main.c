int main(int argc, char *argv[]) {
    GameState *gameState = createGameState();
    StrategyEvaluator *evaluator = createStrategyEvaluator();
    Visualization *visualization = createVisualization();
    for(int identifier = 1; !isGameOver(gameState); ) {
        updateGameState(gameState);
        evaluateStrategies(evaluator, gameState);
        displayVisualization(visualization, gameState, evaluator);
    }
    destroyGameState(gameState);
    destroyStrategyEvaluator(evaluator);
    destroyVisualization(visualization);
    return 0;
}