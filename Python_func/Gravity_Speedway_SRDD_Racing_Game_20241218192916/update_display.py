def update_display(self):
        # Update the display and control the frame rate
        pygame.display.flip()
        self.clock.tick(60)