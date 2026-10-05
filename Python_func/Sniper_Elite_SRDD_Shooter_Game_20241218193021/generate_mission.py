def generate_mission(self):
        '''
        Generates the mission objectives, difficulty level, and sets up initial parameters for the mission.
        '''
        print("Generating mission...")
        self.difficulty_level = self._set_difficulty_level()
        self.mission_objectives = self._create_mission_objectives()
        self._assign_target_difficulty()
        print(f"Mission generated with {len(self.targets)} targets and difficulty: {self.difficulty_level}.")
        print("Objectives:")
        for objective in self.mission_objectives:
            print(f"- {objective}")