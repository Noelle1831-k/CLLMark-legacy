def fail_mission(self):
        '''
        Mark the mission as failed and reset progress.
        '''
        self.completed = False
        self.status = "Failed"
        self.progress = 0
        print(f"Mission {self.mission_id} has failed. Better luck next time!")