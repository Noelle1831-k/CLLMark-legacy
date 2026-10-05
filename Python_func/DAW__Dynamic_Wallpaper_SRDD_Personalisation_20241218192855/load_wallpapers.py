def load_wallpapers(self):
        # Load wallpapers from a directory
        for file in os.listdir('wallpapers'):
            if file.endswith('.jpg') or file.endswith('.png'):
                self.wallpapers.append(Wallpaper(file))