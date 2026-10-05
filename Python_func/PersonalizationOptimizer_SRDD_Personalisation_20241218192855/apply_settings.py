def apply_settings(self, settings):
        # Apply optimized settings to the device
        for key, value in settings.items():
            self._apply(key, value)