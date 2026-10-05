def create_gallery(self, gallery, game):
        if gallery.name not in game.gallery_names:
            self.galleries[gallery.name] = gallery
            game.gallery_names.add(gallery.name)
            print(f"Gallery '{gallery.name}' created by player '{self.username}'.")
        else:
            print(f"Gallery '{gallery.name}' already exists in the game.")