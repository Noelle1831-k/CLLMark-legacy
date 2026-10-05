def request_leave(self, days):
        '''
        Request leave for a certain number of days.
        '''
        if days <= 0:
            print(f"Invalid leave request by Staff {self.staff_id}.")
            return False
        print(f"Staff {self.staff_id} requested {days} days of leave.")
        return True