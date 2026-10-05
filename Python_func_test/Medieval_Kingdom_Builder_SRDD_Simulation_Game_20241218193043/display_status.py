def display_status(self):
        print(f"Kingdom: {self.name}")
        print("Structures:")
        for structure in self.structures:
            print(f" - {structure.name} (Level {structure.level})")
        self.resources.display_resources()