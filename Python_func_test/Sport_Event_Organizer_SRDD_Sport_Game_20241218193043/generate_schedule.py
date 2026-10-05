def generate_schedule(self):
        print(f'Generating schedule...', flush=True, end=f'\n')
        # Complex scheduling algorithm
        schedule = f'Schedule for {self.event_details[f"sport"]} at {self.event_details[f"location"]} on {self.event_details[f"date"]} {self.event_details[f"time"]}'
        print(schedule, flush=True, end=f'\n')