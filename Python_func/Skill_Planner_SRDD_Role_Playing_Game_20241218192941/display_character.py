def display_character(self):
        print(f"Character: {self.name}")
        print("Attributes:")
        for attr, value in self.attributes.items():
            print(f"  {attr}: {value}")
        print("Skills:")
        for skill, level in self.skills.items():
            print(f"  {skill}: Level {level}")