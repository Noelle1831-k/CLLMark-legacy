def render(self):
        '''
        Renders the track with obstacles and turns.
        '''
        print("Rendering track:")
        for i in range(0, self.length, 50):
            segment = ''.join(self.track_data[i:i+50])
            print(segment)