def draw_timer(self):
        elapsed_time = int(time.time() - self.start_time)
        remaining_time = max(0, self.time_limit - elapsed_time)
        font = pygame.font.Font(None, 36)
        timer_text = font.render(f"Time Left: {remaining_time}s", True, (0, 0, 0))
        self.screen.blit(timer_text, (350, 10))