def share_photo(self, user, event, photo_path):
        photo = Photo(user, event, photo_path)
        self.photos.append(photo)
        return photo