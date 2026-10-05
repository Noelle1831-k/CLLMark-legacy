def get_total_passengers(self):
        '''
        Calculate and return the total number of passengers across all buses.
        '''
        total_passengers = sum(self.passenger_count.values())
        print(f"Total passengers across all buses: {total_passengers}")
        return total_passengers