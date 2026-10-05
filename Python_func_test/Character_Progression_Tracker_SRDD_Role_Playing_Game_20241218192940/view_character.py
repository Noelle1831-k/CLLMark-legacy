def view_character(self):
        name = input("Enter character name to view: ")
        for character in self.characters:
            if character.name == name:
                print(character.get_summary())
                self.visualizer.generate_visualization(character)
                return
        print("Character not found.")