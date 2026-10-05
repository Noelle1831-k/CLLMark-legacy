void displayVisualization(Visualization *visual, GameState *state, StrategyEvaluator *evaluator) {
    for (int i = 0; i < 4; i++) {
        snprintf(visual->displayBuffer, sizeof(visual->displayBuffer), 
                 "Player %d: Position %d, Resources %d, Objective %d, Recommendation %d, Strategy Score %d\n",
                 i, state->playerPositions[i], state->resources[i], state->objectives[i], 
                 evaluator->recommendations[i], evaluator->strategyScores[i]);
        printf("%s", visual->displayBuffer);
    }
}