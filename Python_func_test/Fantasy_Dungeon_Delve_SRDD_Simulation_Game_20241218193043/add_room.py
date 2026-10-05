def add_room(self, room):
        self.rooms.append(room)
        if not self.current_room:
            self.current_room = room