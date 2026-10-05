def book(self, user, time_period):
        if self.is_available(time_period):
            self.bookings.append({'user': user, 'time_period': time_period})