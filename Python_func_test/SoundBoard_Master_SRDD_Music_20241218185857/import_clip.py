def import_clip(self, file_path):
        # Simulate importing a clip
        clip = {"path": file_path, "name": file_path.split('/')[-1]}
        self.clips.append(clip)