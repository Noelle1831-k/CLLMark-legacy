def simulate_passenger_flow(self):
        '''
        Simulate passenger flow for each bus and print the current passenger count.
        '''
        for bus_id in self.buses:
            self.passenger_count[bus_id] = random.randint(0, 50)
            print(f"Bus {bus_id} has {self.passenger_count[bus_id]} passengers.")