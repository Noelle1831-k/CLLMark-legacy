def delete_folder(self, name):
        self.folders = [folder for folder in self.folders if folder.name != name]