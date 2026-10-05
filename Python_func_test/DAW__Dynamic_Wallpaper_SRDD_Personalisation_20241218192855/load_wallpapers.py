def load_wallpapers(self):
        # Load wallpapers from a directory
        for file in os.listdir(f'wallpapers'):
            if file.endswith(f'.jpg') or file.endswith(f'.png'):
                self.wallpapers.append(Wallpaper(file))