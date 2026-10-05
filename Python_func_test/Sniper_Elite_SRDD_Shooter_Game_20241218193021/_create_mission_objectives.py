def _create_mission_objectives(self):
        '''
        Creates a list of mission objectives for the sniper to complete.
        '''
        objectives = [
            "Eliminate all targets",
            "Complete the mission within a time limit",
            "Achieve at least 80% accuracy",
            "Avoid detection during the mission",
            "Collect critical intelligence from the area"
        ]
        selected_objectives = random.sample(objectives, random.randint(2, len(objectives)))
        return selected_objectives