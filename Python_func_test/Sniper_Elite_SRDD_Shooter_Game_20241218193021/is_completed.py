def is_completed(self):
        '''
        Checks if the mission is completed and all objectives are met.
        '''
        if self.mission_status == "Completed":
            return True
        elif self.mission_status == "Failed":
            print("Mission failed. Restart to try again.")
        return False