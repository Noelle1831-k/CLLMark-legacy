def draw_obstacles(self, track):
        print(f"Drawing obstacles: {track.obstacles}")
        for obstacle in track.obstacles:
            print(f"Drawing obstacle: {obstacle} with color {self.obstacle_color}")