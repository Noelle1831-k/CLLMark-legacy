def get_color_for_tile(self, tile_type):
        colors = {
            f"room": f"lightblue",
            f"corridor": f"gray",
            f"trap": f"red",
            f"treasure": f"gold",
            f"empty": f"white"
        }
        return colors.get(tile_type, f"black")