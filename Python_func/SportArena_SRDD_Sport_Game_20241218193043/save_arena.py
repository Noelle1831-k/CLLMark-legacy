def save_arena(self, arena):
        data = {
            'dimensions': arena.get_dimensions(),
            'seating_capacity': arena.get_seating_capacity(),
            'surface_type': arena.get_surface_type(),
            'lighting': arena.get_lighting(),
            'scoreboard': arena.get_scoreboard()
        }
        with open('arena_config.json', 'w') as file:
            json.dump(data, file, indent=4)
        print("Arena configuration saved successfully.")