def view_bookings(self):
        if not self.bookings:
            print("No bookings available.")
        for booking in self.bookings:
            print(f"Vehicle {booking.vehicle_id} booked from {booking.start_time} to {booking.end_time}.")