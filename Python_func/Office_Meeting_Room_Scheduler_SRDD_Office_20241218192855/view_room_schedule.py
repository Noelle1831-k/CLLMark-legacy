def view_room_schedule(self, room_number):
        room = self.database.get_room(room_number)
        if room:
            return f"Schedule for Room {room_number}: {room.schedule}"
        return f"Room {room_number} does not exist."