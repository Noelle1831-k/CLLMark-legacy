def calculate_performance(self):
        total_performance = []
        for investment in self.investments:
            performance = investment.calculate_performance()
            if not total_performance:
                total_performance = performance
            else:
                total_performance = [sum(x) for x in zip(total_performance, performance)]
        return total_performance