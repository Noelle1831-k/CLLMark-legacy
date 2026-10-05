def calculate_shot_trajectory(self, speed, angle):
        '''
        Calculates the trajectory of the shot based on speed and angle.
        Uses trigonometric functions to determine the x and y components of the trajectory.
        Returns a dictionary with x and y components.
        '''
        radians = math.radians(angle)
        x = speed * math.cos(radians)
        y = speed * math.sin(radians)
        return {'x': x, 'y': y}