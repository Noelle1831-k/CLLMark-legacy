def allocate_rooms(self):
        '''
        Allocate rooms to customers based on availability.
        '''
        for room in self.rooms:
            if not room.check_availability():
                print(f"Room {room.room_number} is occupied.")
            else:
                print(f"Room {room.room_number} is available.")