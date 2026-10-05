def update_display(self):
        self.canvas.delete("all")
        for i in range(10):
            for j in range(10):
                tile = self.dungeon_map.get_tile(i, j)
                color = self.get_color_for_tile(tile.type)
                self.canvas.create_rectangle(i*50, j*50, (i+1)*50, (j+1)*50, fill=color)