def load_mission(self):
        '''
        Load mission objectives and populate enemy planes based on difficulty level.
        '''
        print(f"Loading mission {self.mission_id} with difficulty level: {self.difficulty_level}.")
        self.objectives = self._generate_objectives()
        self.enemy_planes = self._generate_enemies()
        self.status = "In Progress"
        print(f"Mission {self.mission_id} initialized with objectives: {self.objectives}")