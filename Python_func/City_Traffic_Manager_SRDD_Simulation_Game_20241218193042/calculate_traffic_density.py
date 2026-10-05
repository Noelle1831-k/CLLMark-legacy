def calculate_traffic_density(self):
        '''
        Calculate the traffic density on the road, defined as the number of vehicles
        per unit of road length and lanes.
        '''
        density = len(self.vehicles) / (self.length * self.lanes)
        return density