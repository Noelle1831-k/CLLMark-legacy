def is_suitable(self, preferences):
        return (self.style == preferences['style'] and 
                self.duration <= preferences['duration'] and 
                self.theme == preferences['theme'])