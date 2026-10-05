def customize_wallpaper(self, wallpaper_path):
        '''
        Sets the desktop wallpaper to the specified image.
        Parameters:
        wallpaper_path (str): The path to the wallpaper image file.
        '''
        if not os.path.exists(wallpaper_path):
            print(f"Wallpaper path '{wallpaper_path}' does not exist.")
            return
        try:
            # Example for Windows
            if os.name == 'nt':
                import ctypes
                SPI_SETDESKWALLPAPER = 20
                ctypes.windll.user32.SystemParametersInfoW(SPI_SETDESKWALLPAPER, 0, wallpaper_path, 3)
            # Example for macOS
            elif os.uname().sysname == 'Darwin':
                script = f'''
                tell application "System Events"
                    set desktopCount to count of desktops
                    repeat with desktopNumber from 1 to desktopCount
                        tell desktop desktopNumber
                            set picture to "{wallpaper_path}"
                        end tell
                    end repeat
                end tell
                '''
                subprocess.run(["osascript", "-e", script])
            # Example for Linux (GNOME)
            elif os.uname().sysname == 'Linux':
                subprocess.run(["gsettings", "set", "org.gnome.desktop.background", "picture-uri", f"file://{wallpaper_path}"])
            print(f"Wallpaper set to '{wallpaper_path}'.")
        except Exception as e:
            print(f"An error occurred while setting wallpaper: {e}")