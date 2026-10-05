def calculate_effective_range(self, wind_speed):
        '''
        Calculates the effective range of the rifle considering wind speed.
        '''
        print("Calculating effective range...")
        wind_penalty = wind_speed * 5
        effective_range = max(0, self.current_rifle['range'] - wind_penalty)
        print(f"Effective Range: {effective_range}m")
        return effective_range