def release_room(self, room_number):
        room = self.database.get_room(room_number)
        if room:
            room.release_room()
            return f"Room {room_number} is now available."
        return f"Room {room_number} does not exist."