def display_arena(self, arena):
        print("\nCurrent Arena Configuration:")
        print(f"Arena Dimensions: {arena.get_dimensions()}")
        print(f"Seating Capacity: {arena.get_seating_capacity()}")
        print(f"Surface Type: {arena.get_surface_type()}")
        print(f"Lighting: {arena.get_lighting()}")
        print(f"Scoreboard: {arena.get_scoreboard()}")