def generate_track_data(self):
        '''
        Generates detailed track data including obstacles and turns.
        '''
        track_data = []
        for i in range(self.length):
            if any(obstacle[0] == i for obstacle in self.obstacles):
                track_data.append('O')  # O for obstacle
            elif any(turn[0] == i for turn in self.turns):
                track_data.append('T')  # T for turn
            else:
                track_data.append('-')  # - for clear path
        return track_data