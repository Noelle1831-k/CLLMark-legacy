def display_game(self, shapes, silhouette):
        print(f'Displaying game with shapes and silhouette.', flush=True, end=f'\n')
        for shape in shapes:
            print(shape, flush=True, end=f'\n')
        print(silhouette, flush=True, end=f'\n')