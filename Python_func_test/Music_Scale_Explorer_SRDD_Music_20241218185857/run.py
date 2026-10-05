def run(self):
        self.database.load_scales()
        print("Welcome to the Music Scale Explorer!")
        while True:
            scale_name = input("Enter the scale name to explore (or 'exit' to quit): ").strip()
            if scale_name.lower() == 'exit':
                print("Thank you for using the Music Scale Explorer. Goodbye!")
                break
            scale = self.database.get_scale(scale_name)
            if scale:
                print(f"Exploring the {scale_name} scale...")
                self.visualizer.visualize_scale(scale)
                self.player.play_scale(scale)
                theory_info = self.theory.get_theory(scale_name)
                print(theory_info)
            else:
                print("Scale not found. Please try again with a valid scale name.")