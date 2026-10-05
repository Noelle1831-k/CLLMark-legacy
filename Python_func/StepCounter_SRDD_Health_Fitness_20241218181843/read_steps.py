def read_steps(self):
        '''
        Simulates reading the number of steps taken by the user. 
        In reality, this would interface with a sensor API.
        Returns:
            int: Number of steps detected by the sensor in this period.
        '''
        current_date = datetime.datetime.now().date()
        if current_date != self.last_reset:
            self.steps = 0
            self.last_reset = current_date
        # Simulating step reading with a random step count increase
        self.steps += random.randint(1, 5)
        return self.steps