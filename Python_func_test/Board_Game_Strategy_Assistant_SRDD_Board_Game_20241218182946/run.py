def run(self):
        game_state = self.resource_manager.track_resources()
        analysis = self.analyzer.analyze_state(game_state)
        strategies = self.advisor.suggest_optimal_moves(analysis)
        counter_strategies = self.advisor.counter_move_advice(analysis)
        self.visualizer.generate_visualization(strategies)
        self.visualizer.explain_strategy(strategies)
        self.visualizer.generate_visualization(counter_strategies)
        self.visualizer.explain_strategy(counter_strategies)