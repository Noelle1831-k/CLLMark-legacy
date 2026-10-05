def calculate_total_cost(self):
        return sum(destination.cost for destination in self.destinations)