def render_waveform(self, audio_data):
        width, height = self.screen.get_size()
        center_y = height // 2
        num_samples = len(audio_data)
        for x in range(width):
            sample_index = int(x / width * num_samples * self.zoom_level) + self.pan_offset
            if 0 <= sample_index < num_samples:
                amplitude = audio_data[sample_index]
                y = int(center_y + amplitude * center_y)
                pygame.draw.line(self.screen, self.color_scheme, (x, center_y), (x, y))