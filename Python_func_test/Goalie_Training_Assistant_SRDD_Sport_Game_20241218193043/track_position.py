def track_position(self):
        '''
        Simulates tracking the current position of the goalie on the ice.
        Returns a dictionary with x and y coordinates.
        '''
        x = random.uniform(0, 100)  # Position x-coordinate
        y = random.uniform(0, 100)  # Position y-coordinate
        print(f"Tracked Position - X: {x:.2f}, Y: {y:.2f}")
        return {'x': x, 'y': y}