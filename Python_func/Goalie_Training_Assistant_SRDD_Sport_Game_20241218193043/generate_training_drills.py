def generate_training_drills(self):
        '''
        Generates training drills for the goalie.
        '''
        drills = ["Drill 1: Lateral Movement", "Drill 2: Quick Reflexes", "Drill 3: Shot Blocking"]
        selected_drill = random.choice(drills)
        print(f"Training Drill: {selected_drill}")