def start_game(self):
        self.is_running = True
        self.shapes = generate_random_shapes()
        self.silhouette.load_silhouette()
        self.ui.display_game(self.shapes, self.silhouette)
        while self.is_running:
            user_input = self.ui.get_user_input()
            self.process_input(user_input)