def add_artwork(self, artwork):
        if artwork not in self.artworks:
            self.artworks.append(artwork)
            print(f"Artwork '{artwork.title}' added to gallery '{self.name}'.")
        else:
            print(f"Artwork '{artwork.title}' already exists in gallery '{self.name}'.")