def analyze_moves(self):
        statistics = calculate_statistics(self.game_tracker.moves)
        strategy_comparison = compare_strategies(self.game_tracker.moves)
        return {"statistics": statistics, "comparison": strategy_comparison}