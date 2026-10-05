def main():
    # Initialize the game tracker
    game_tracker = GameTracker()
    # Simulate adding moves
    game_tracker.add_move("Player1", "Move1", "State1")
    game_tracker.add_move("Player2", "Move2", "State2")
    # Analyze the game
    analyzer = StrategyAnalyzer(game_tracker)
    analysis_results = analyzer.analyze_moves()
    # Generate visuals
    visualizer = Visualizer(analysis_results)
    visualizer.display_visuals()