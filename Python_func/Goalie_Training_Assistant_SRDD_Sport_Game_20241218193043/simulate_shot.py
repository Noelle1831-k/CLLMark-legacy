def simulate_shot(self):
        '''
        Simulates a shot by generating random speed and angle values.
        Returns a dictionary containing the speed, angle, and trajectory of the shot.
        '''
        speed = random.uniform(20, 100)  # Speed in km/h
        angle = random.uniform(0, 360)   # Angle in degrees
        trajectory = self.calculate_shot_trajectory(speed, angle)
        print(f"Simulated Shot - Speed: {speed:.2f} km/h, Angle: {angle:.2f} degrees")
        return {'speed': speed, 'angle': angle, 'trajectory': trajectory}