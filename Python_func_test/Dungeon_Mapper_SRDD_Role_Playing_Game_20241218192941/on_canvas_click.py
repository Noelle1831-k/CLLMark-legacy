def on_canvas_click(self, event):
        x, y = event.x // 50, event.y // 50
        if self.selected_tile:
            self.dungeon_map.set_tile(x, y, self.selected_tile)
            self.update_display()