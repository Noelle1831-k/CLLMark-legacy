def update(self):
        '''
        Update mission progress based on objectives and enemy planes status.
        '''
        print(f"Updating mission {self.mission_id} progress...")
        if self.status != "In Progress":
            print("Mission is not in progress. Update halted.")
            return
        self.progress += random.randint(5, 15)  # Simulate progress increment
        if self.progress >= 100:
            self.progress = 100
            self.complete_mission()
        else:
            print(f"Mission {self.mission_id} progress: {self.progress}%.")