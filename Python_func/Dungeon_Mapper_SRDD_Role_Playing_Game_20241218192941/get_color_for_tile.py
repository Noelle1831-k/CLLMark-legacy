def get_color_for_tile(self, tile_type):
        colors = {
            'room': 'lightblue',
            'corridor': 'gray',
            'trap': 'red',
            'treasure': 'gold',
            'empty': 'white'
        }
        return colors.get(tile_type, 'black')