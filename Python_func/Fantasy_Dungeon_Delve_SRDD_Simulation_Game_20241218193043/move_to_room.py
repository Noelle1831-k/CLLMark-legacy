def move_to_room(self, player):
        if not self.current_room.connected_rooms:
            print("No connected rooms to move to.")
            return
        print("Connected rooms:")
        for idx, room in enumerate(self.current_room.connected_rooms):
            print(f"{idx + 1}. {room.name}")
        choice = int(input("Choose a room to move to: ")) - 1
        if 0 <= choice < len(self.current_room.connected_rooms):
            self.current_room = self.current_room.connected_rooms[choice]
            player.move(self.current_room.name)
        else:
            print("Invalid choice. Please try again.")