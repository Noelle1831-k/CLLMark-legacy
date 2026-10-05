def display_artworks(self):
        print(f"Displaying artworks in gallery '{self.name}':")
        for artwork in self.artworks:
            print(f"- {artwork.title} by {artwork.artist.name} ({artwork.year})")