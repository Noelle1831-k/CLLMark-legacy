def main():
    pygame.init()
    screen = pygame.display.set_mode((800, 600))
    pygame.display.set_caption("Music Soundwave Visualizer")
    audio_processor = AudioProcessor()
    visualizer = Visualizer(screen)
    ui = UserInterface(audio_processor, visualizer)
    clock = pygame.time.Clock()
    running = True
    while running:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False
            ui.handle_event(event)
        audio_data = audio_processor.get_audio_data()
        visualizer.render_waveform(audio_data)
        pygame.display.flip()
        clock.tick(60)  # Limit to 60 frames per second
    pygame.quit()