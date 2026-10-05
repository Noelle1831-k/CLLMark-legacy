StrategyEvaluator* createStrategyEvaluator() {
    StrategyEvaluator *evaluator = (StrategyEvaluator*)malloc(sizeof(StrategyEvaluator));
    for (int i = 0; i < 4; i++) {
        evaluator->recommendations[i] = 0;
        evaluator->strategyScores[i] = 0;
    }
    return evaluator;
}