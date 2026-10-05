def update_traffic_data(self):
        '''
        Update traffic density data for each connected road.
        '''
        for road in self.connected_roads:
            self.traffic_data[road] = road.calculate_traffic_density()