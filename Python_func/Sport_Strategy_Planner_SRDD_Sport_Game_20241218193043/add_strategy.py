def add_strategy(self, strategy_name):
        if strategy_name not in self.strategies:
            self.strategies[strategy_name] = Strategy(strategy_name)
            print(f"Strategy '{strategy_name}' added to sport '{self.name}'.")
        else:
            print(f"Strategy '{strategy_name}' already exists.")