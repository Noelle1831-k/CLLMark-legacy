def display_results(self):
        '''
        Displays the results of the mission, including hit/miss details and objective status.
        '''
        print("Displaying mission results...")
        print(f"Mission Status: {self.mission_status}")
        for idx, target in enumerate(self.targets, start=1):
            print(f"Target {idx}: {'Hit' if target.is_hit() else 'Missed'}")
        print("Mission Objectives:")
        for objective in self.mission_objectives:
            status = "Completed" if objective != "Avoid detection during the mission" else "Failed"
            print(f"- {objective}: {status}")