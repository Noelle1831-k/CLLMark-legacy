def transform_view(self, zoom, pan, rotate):
        self.zoom_level *= zoom
        self.pan_offset += pan
        self.rotation_angle += rotate