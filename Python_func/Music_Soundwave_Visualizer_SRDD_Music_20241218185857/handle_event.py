def handle_event(self, event):
        if event.type == pygame.KEYDOWN:
            if event.key == pygame.K_o:
                self.toggle_file_selection()
            elif event.key == pygame.K_RETURN and self.file_selection_active:
                self.select_file()
            elif event.key == pygame.K_UP and self.file_selection_active:
                self.selected_file_index = max(0, self.selected_file_index - 1)
            elif event.key == pygame.K_DOWN and self.file_selection_active:
                self.selected_file_index = min(len(self.file_list) - 1, self.selected_file_index + 1)
            elif event.key == pygame.K_PLUS:
                self.visualizer.transform_view(1.1, 0, 0)
            elif event.key == pygame.K_MINUS:
                self.visualizer.transform_view(0.9, 0, 0)
            elif event.key == pygame.K_LEFT:
                self.visualizer.transform_view(1.0, -10, 0)
            elif event.key == pygame.K_RIGHT:
                self.visualizer.transform_view(1.0, 10, 0)
            elif event.key == pygame.K_UP:
                self.visualizer.transform_view(1.0, 0, 5)
            elif event.key == pygame.K_DOWN:
                self.visualizer.transform_view(1.0, 0, -5)