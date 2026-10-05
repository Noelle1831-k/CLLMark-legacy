def add_photo(self, filename):
        new_photo = photo.Photo(filename)
        self.photos.append(new_photo)