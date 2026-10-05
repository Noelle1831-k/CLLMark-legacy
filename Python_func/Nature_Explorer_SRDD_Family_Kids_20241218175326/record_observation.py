def record_observation(self):
        '''
        Records an observation.
        '''
        observation = input("Enter your observation: ")
        self.observations.append({"observation": observation, "photo": self.save_photo()})
        print("Observation recorded.")