def add_new_character(self):
        name = input("Enter character name: ")
        level = int(input("Enter character level: "))
        attributes = input("Enter attributes (comma-separated): ").split(',')
        skills = input("Enter skills (comma-separated): ").split(',')
        equipment = input("Enter equipment (comma-separated): ").split(',')
        character = Character(name, level, attributes, skills, equipment)
        self.characters.append(character)
        print(f"Character {name} added successfully.")