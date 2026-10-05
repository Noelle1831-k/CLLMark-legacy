def schedule_staff(self):
        '''
        Schedule shifts for all staff members.
        '''
        for staff_member in self.staff:
            staff_member.assign_shift()
            staff_member.perform_duty()