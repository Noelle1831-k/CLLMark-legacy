def customize(self, options):
        self.customization_options.update(options)
        if 'max_speed' in options:
            self.max_speed = options['max_speed']
        if 'drift_capability' in options:
            self.drift_capability = options['drift_capability']