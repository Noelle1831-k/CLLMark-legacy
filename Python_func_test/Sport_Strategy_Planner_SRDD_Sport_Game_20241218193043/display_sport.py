def display_sport(self, sport):
        print(f"Displaying strategies for sport: {sport.name}")
        for strategy_name, strategy in sport.strategies.items():
            print(f"Strategy: {strategy_name}")
            for play_name, play in strategy.plays.items():
                print(f"  Play: {play_name}")
                print(f"    Positions: {play.positions}")
                print(f"    Annotations: {play.annotations}")