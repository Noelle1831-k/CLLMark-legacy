def assign_shift(self):
        '''
        Assign shift to the staff member.
        Shifts are randomly assigned for simplicity.
        '''
        shifts = ['Morning', 'Afternoon', 'Night']
        self.shift = random.choice(shifts)
        print(f"Staff {self.staff_id} assigned to {self.shift} shift.")