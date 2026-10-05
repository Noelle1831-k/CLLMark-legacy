def add_bus(self, bus_id, route):
        '''
        Add a new bus and assign it a route.
        '''
        self.buses.append(bus_id)
        self.routes[bus_id] = route
        self.passenger_count[bus_id] = 0