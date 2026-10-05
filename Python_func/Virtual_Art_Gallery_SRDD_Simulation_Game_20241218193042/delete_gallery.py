def delete_gallery(self, gallery_name, game):
        if gallery_name in self.galleries:
            del self.galleries[gallery_name]
            game.gallery_names.remove(gallery_name)
            print(f"Gallery '{gallery_name}' deleted by player '{self.username}'.")
        else:
            print(f"Gallery '{gallery_name}' not found for player '{self.username}'.")