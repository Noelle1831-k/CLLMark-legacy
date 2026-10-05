def _simulate_duty_performance(self, duty):
        '''
        Simulate the performance of a duty.
        '''
        start_time = datetime.now()
        duration = random.randint(1, 3)  # Simulate duty duration in hours
        end_time = start_time + timedelta(hours=duration)
        print(f"Staff {self.staff_id} started {duty} at {start_time.strftime('%H:%M')} and finished at {end_time.strftime('%H:%M')}.")