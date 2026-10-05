def adjust_pricing_strategy(self):
        '''
        Adjust pricing strategy based on occupancy and market trends.
        '''
        occupancy_rate = sum(not room.check_availability() for room in self.rooms) / len(self.rooms)
        if occupancy_rate < 0.5:
            print("Low occupancy detected. Reducing room prices to attract more guests.")
            self.revenue *= 0.9  # Reduce revenue to simulate price reduction
        else:
            print("High occupancy detected. Maintaining current room prices.")