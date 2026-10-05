def load_arena(self):
        try:
            with open('arena_config.json', 'r') as file:
                data = json.load(file)
            arena = Arena()
            arena.set_dimensions(*data['dimensions'])
            arena.set_seating_capacity(data['seating_capacity'])
            arena.set_surface_type(data['surface_type'])
            arena.set_lighting(data['lighting'])
            arena.set_scoreboard(data['scoreboard'])
            print("Arena configuration loaded successfully.")
            return arena
        except FileNotFoundError:
            print("No saved configuration found. Loading default arena settings.")
            return Arena()
        except json.JSONDecodeError:
            print("Error loading configuration. The file may be corrupted.")
            return Arena()