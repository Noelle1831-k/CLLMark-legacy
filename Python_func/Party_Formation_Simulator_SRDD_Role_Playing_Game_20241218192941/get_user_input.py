def get_user_input(self):
        """
        Get user input for creating new characters.
        Returns:
            List[Character]: A list of characters based on user input.
        """
        characters = []
        while True:
            print("\nEnter character details:")
            name = input("Name: ")
            class_type = input("Class Type (e.g., Ranger, Fighter, Sorcerer): ")
            # Input and parse attributes
            attributes = {}
            print("Enter attributes (key:value pairs, comma-separated, e.g., strength:5, agility:8):")
            attr_input = input("Attributes: ")
            for pair in attr_input.split(","):
                key, value = pair.strip().split(":")
                attributes[key.strip()] = int(value.strip())
            # Input skills
            skills = input("Skills (comma-separated): ").split(",")
            skills = [skill.strip() for skill in skills]
            # Input abilities
            abilities = input("Abilities (comma-separated): ").split(",")
            abilities = [ability.strip() for ability in abilities]
            # Create and store character
            character = Character(name, class_type, attributes, skills, abilities)
            characters.append(character)
            cont = input("Add another character? (yes/no): ").strip().lower()
            if cont != "yes":
                break
        return characters