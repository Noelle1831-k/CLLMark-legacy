def reset_mission(self):
        '''
        Reset the mission progress and reload objectives and enemies.
        '''
        print(f"Resetting mission {self.mission_id}...")
        self.completed = False
        self.progress = 0
        self.status = "Not Started"
        self.load_mission()