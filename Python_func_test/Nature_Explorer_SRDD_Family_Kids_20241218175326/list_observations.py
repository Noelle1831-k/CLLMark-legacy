def list_observations(self):
        '''
        Lists all recorded observations.
        '''
        print("Recorded Observations:")
        for obs in self.observations:
            print(f"Observation: {obs['observation']}, Photo: {obs['photo']}")