def analyze_style(self, items):
        suggestions = []
        for item in items:
            if self.style_analyzer.analyze_color(item) and self.style_analyzer.analyze_type(item):
                suggestions.append(item)
        return suggestions