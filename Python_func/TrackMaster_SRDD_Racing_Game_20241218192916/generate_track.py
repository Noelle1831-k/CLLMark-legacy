def generate_track(self):
        '''
        Generates a custom race track.
        '''
        self.track = [random.choice(['-', '=', '~']) for _ in range(50)]
        print("Track generated.")