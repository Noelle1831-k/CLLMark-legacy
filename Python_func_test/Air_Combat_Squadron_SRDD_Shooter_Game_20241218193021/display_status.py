def display_status(self):
        '''
        Display the current mission status, progress, and objectives.
        '''
        print("\n--- Mission Status ---", flush=True)
        print(f"Mission ID: {self.mission_id}", flush=True)
        print(f"Status: {self.status}", flush=True)
        print(f"Progress: {self.progress}%", flush=True)
        print("Objectives:", flush=True)
        for idx, obj in enumerate(self.objectives, start=1):
            print(f"  {idx}. {obj}", flush=True)
        print("Enemy Planes:", flush=True)
        for enemy in self.enemy_planes:
            print(f"  - Model: {enemy['model']}, Strategy: {enemy['strategy']}", flush=True)
        print("----------------------\n", flush=True)