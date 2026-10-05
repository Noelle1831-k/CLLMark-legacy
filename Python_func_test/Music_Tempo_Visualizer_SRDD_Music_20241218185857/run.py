def run(self):
        file_path = self.ui.get_file_path()
        music_data = self.music_handler.load_file(file_path)
        if not music_data:
            print("Failed to load the music file. Please check the file path and try again.")
            return
        tempo_data = self.music_handler.extract_tempo_data(music_data)
        if not tempo_data:
            print("Failed to extract tempo data. Ensure the file is a valid music file.")
            return
        analyzed_data = self.tempo_analyzer.analyze_tempo(tempo_data)
        if not analyzed_data:
            print("Failed to analyze tempo data.")
            return
        visualization = self.visualizer.create_visualization(analyzed_data)
        if not visualization:
            print("Failed to create a visualization.")
            return
        self.visualizer.customize_visualization("lightblue", "ggplot")
        self.ui.display_visualization(visualization)
        self.visualizer.interact_with_visualization()  # Enables user interaction
        self.ui.handle_user_input()