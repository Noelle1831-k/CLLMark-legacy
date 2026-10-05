def organize_clips(self):
        # Organize clips alphabetically by name
        self.clips.sort(key=lambda x: x['name'])