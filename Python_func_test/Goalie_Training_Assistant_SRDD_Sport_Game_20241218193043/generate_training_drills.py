def generate_training_drills(self):
        '''
        Generates training drills for the goalie.
        '''
        drills = [f"Drill 1: Lateral Movement", f"Drill 2: Quick Reflexes", f"Drill 3: Shot Blocking"]
        selected_drill = random.choice(drills)
        print(f"Training Drill: {selected_drill}", flush=True, end=f"\n")