def perform_duty(self):
        '''
        Perform duty logic for the staff member.
        Duties are randomly selected and performed.
        '''
        possible_duties = ['Cleaning', 'Room Service', 'Front Desk', 'Maintenance']
        self.duties = random.sample(possible_duties, k=random.randint(1, len(possible_duties)))
        for duty in self.duties:
            print(f"Staff {self.staff_id} is performing duty: {duty}")
            self._simulate_duty_performance(duty)