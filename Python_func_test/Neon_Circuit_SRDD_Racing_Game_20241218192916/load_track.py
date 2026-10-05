def load_track(self):
        '''
        Loads track data with obstacles and turns.
        '''
        self.generate_obstacles()
        self.generate_turns()
        self.track_data = self.generate_track_data()
        print("Track loaded with obstacles and turns.")