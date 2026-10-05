def make_decision(self, decision):
        '''
        Executes a decision that affects the company's financial status and growth.
        '''
        if decision == "invest":
            self.balance -= 10000
            self.growth_rate += 0.01
        elif decision == "cut_costs":
            self.balance += 5000
            self.growth_rate -= 0.005