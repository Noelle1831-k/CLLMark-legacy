def transform_view(self, zoom, pan, rotate):
        self.zoom_level = self.zoom_level * zoom
        self.pan_offset = self.pan_offset + pan
        self.rotation_angle = self.rotation_angle + rotate