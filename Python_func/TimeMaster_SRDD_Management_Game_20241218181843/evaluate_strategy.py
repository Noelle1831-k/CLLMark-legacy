def evaluate_strategy(self):
        if not self.strategies:
            print("No strategies to evaluate.")
        else:
            print("Evaluating strategies...")
            for strategy in self.strategies:
                print(f"Strategy: {strategy}")