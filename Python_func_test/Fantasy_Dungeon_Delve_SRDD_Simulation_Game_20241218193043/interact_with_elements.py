def interact_with_elements(self, player):
        elements = self.current_room.get_elements()
        if not elements:
            print("No elements to interact with in this room.")
            return
        print("Elements in the room:")
        for idx, element in enumerate(elements):
            print(f"{idx + 1}. {element.describe()}")
        choice = int(input("Choose an element to interact with: ")) - 1
        if 0 <= choice < len(elements):
            player.interact(elements[choice])
        else:
            print("Invalid choice. Please try again.")