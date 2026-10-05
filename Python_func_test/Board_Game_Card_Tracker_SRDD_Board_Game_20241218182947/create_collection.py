def create_collection(self, name):
        collection = CardCollection(name)
        self.collections.append(collection)