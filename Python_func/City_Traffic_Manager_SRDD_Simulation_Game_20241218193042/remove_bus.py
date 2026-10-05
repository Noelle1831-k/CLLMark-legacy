def remove_bus(self, bus_id):
        '''
        Remove a bus from the public transport system.
        '''
        if bus_id in self.buses:
            self.buses.remove(bus_id)
            del self.routes[bus_id]
            del self.passenger_count[bus_id]