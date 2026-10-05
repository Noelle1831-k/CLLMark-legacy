def customize(self, options):
        """
        Updates the car's customization options.
        """
        self.customization_options.update(options)
        if 'handling' in options:
            self.handling = options['handling']
        if 'weight' in options:
            self.weight = options['weight']