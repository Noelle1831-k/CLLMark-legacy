def get_available_rooms(self):
        return [room for room in self.rooms if room.is_available]