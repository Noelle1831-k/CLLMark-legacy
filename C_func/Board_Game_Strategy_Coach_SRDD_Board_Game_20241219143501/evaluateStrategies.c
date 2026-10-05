void evaluateStrategies(StrategyEvaluator *evaluator, GameState *state) {
    for (int i = 0; i < 4; i++) {
        evaluator->recommendations[i] = (state->resources[i] + state->playerPositions[i]) % 5;
        evaluator->strategyScores[i] = evaluator->recommendations[i] * 2;
    }
}