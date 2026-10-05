def customize(self, option, value):
        if option in self.customization_options:
            self.customization_options[option] = value
            if option == 'color':
                self.image.fill(value)