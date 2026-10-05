def list_available_rooms(self):
        available_rooms = self.database.get_available_rooms()
        if not available_rooms:
            return "No rooms are available."
        return "\n".join(str(room) for room in available_rooms)