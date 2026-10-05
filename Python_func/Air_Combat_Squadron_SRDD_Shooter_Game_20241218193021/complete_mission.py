def complete_mission(self):
        '''
        Mark the mission as completed and print a success message.
        '''
        self.completed = True
        self.status = "Completed"
        print(f"Mission {self.mission_id} successfully completed!")