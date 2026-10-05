def delete_collection(self, name):
        self.collections = [collection for collection in self.collections if collection.name != name]