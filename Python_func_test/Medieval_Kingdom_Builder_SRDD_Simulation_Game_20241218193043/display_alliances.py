def display_alliances(self):
        if self.alliances:
            print("Alliances:")
            for alliance in self.alliances:
                print(f" - {alliance}")
        else:
            print("No alliances formed.")