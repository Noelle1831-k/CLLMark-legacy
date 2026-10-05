def display_status(self):
        '''
        Display the current mission status, progress, and objectives.
        '''
        print("\n--- Mission Status ---")
        print(f"Mission ID: {self.mission_id}")
        print(f"Status: {self.status}")
        print(f"Progress: {self.progress}%")
        print("Objectives:")
        for idx, obj in enumerate(self.objectives, start=1):
            print(f"  {idx}. {obj}")
        print("Enemy Planes:")
        for enemy in self.enemy_planes:
            print(f"  - Model: {enemy['model']}, Strategy: {enemy['strategy']}")
        print("----------------------\n")