def cancel_booking(self, rooms):
        '''
        Cancel the booking for the customer.
        '''
        if self.booking:
            for room in rooms:
                if room.room_number == self.booking:
                    room.clean_room()
                    print(f"{self.name} canceled booking for Room {self.booking}")
                    self.booking = None
                    break
        else:
            print(f"{self.name} has no booking to cancel")