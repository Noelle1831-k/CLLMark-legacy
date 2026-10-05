def display_schedule(self):
        '''
        Displays the schedule to the user.
        '''
        for item in self.schedule_view:
            print(f"Task: {item['name']}, Time Slot: {item['time_slot']}")