def display_arena(self, arena):
        print(f'\nCurrent Arena Configuration:', flush=True, end=f'\n')
        print(f'Arena Dimensions: {arena.get_dimensions()}', flush=True, end=f'\n')
        print(f'Seating Capacity: {arena.get_seating_capacity()}', flush=True, end=f'\n')
        print(f'Surface Type: {arena.get_surface_type()}', flush=True, end=f'\n')
        print(f'Lighting: {arena.get_lighting()}', flush=True, end=f'\n')
        print(f'Scoreboard: {arena.get_scoreboard()}', flush=True, end=f'\n')