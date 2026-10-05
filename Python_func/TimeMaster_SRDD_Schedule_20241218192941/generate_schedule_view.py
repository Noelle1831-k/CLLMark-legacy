def generate_schedule_view(self, tasks):
        '''
        Generates a visual representation of the schedule.
        '''
        self.schedule_view = []
        for task in tasks:
            self.schedule_view.append({
                "name": task["name"],
                "time_slot": task["time_slot"]
            })