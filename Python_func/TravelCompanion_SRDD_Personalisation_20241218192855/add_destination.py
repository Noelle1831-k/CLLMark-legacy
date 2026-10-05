def add_destination(self, destination):
        self.destinations.append(destination)
        self.total_cost += destination.cost
        self.activities.extend(destination.activities)