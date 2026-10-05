def customize_arena(self):
        try:
            length = int(input("Enter arena length: "))
            width = int(input("Enter arena width: "))
            self.arena.set_dimensions(length, width)
            capacity = int(input("Enter seating capacity: "))
            self.arena.set_seating_capacity(capacity)
            surface = input("Enter surface type (Grass, Turf, etc.): ")
            self.arena.set_surface_type(surface)
            lighting = input("Enter lighting type (Standard, LED, etc.): ")
            self.arena.set_lighting(lighting)
            scoreboard = input("Enter scoreboard type (Basic, Digital, etc.): ")
            self.arena.set_scoreboard(scoreboard)
            print("Arena customization complete.")
        except ValueError:
            print("Invalid input. Please enter numeric values where applicable.")