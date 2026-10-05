def delete_hunt(self, hunt):
        if hunt in self.hunts:
            self.hunts.remove(hunt)