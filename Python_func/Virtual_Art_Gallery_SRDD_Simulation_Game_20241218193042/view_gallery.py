def view_gallery(self, gallery_name):
        if gallery_name in self.galleries:
            gallery = self.galleries[gallery_name]
            gallery.display_artworks()
        else:
            print(f"Gallery '{gallery_name}' not found for player '{self.username}'.")