def select_style(self, style):
        if style in self.styles:
            print(f"Style {style} selected.")
        else:
            print("Style not found.")