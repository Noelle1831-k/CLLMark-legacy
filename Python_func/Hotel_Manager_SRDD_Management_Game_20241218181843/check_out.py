def check_out(self, rooms):
        '''
        Check-out the customer.
        '''
        if self.booking:
            for room in rooms:
                if room.room_number == self.booking:
                    room.clean_room()
                    print(f"{self.name} checked out from Room {self.booking}")
                    self.booking = None
                    break
        else:
            print(f"{self.name} has no booking to check-out")