def reset_game(self):
        self.shapes = generate_random_shapes()
        self.ui.display_game(self.shapes, self.silhouette)