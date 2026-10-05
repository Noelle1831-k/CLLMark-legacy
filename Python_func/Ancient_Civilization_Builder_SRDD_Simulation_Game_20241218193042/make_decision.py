def make_decision(self):
        # Example decision-making logic
        if self.happiness < 30:
            self.build_structure('temple')
        elif self.population > 150:
            self.build_structure('marketplace')
        print("Decision made.")