def is_available(self, time_period=None):
        if time_period:
            for booking in self.bookings:
                if booking['time_period'] == time_period:
                    return False
        return True