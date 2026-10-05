def remove_artwork(self, artwork):
        if artwork in self.artworks:
            self.artworks.remove(artwork)
            print(f"Artwork '{artwork.title}' removed from gallery '{self.name}'.")
        else:
            print(f"Artwork '{artwork.title}' not found in gallery '{self.name}'.")