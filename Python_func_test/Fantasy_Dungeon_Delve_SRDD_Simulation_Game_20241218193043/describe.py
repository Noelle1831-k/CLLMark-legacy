def describe(self):
        print(f"This is the {self.name}.")
        if self.connected_rooms:
            print("Connected rooms:")
            for room in self.connected_rooms:
                print(f"- {room.name}")