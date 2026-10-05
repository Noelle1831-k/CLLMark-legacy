def get_room(self, room_number):
        for room in self.rooms:
            if room.room_number == room_number:
                return room
        return None