def _generate_notes(self):
        if self.name == "C Major":
            return "C D E F G A B"
        elif self.name == "A Minor":
            return "A B C D E F G"
        else:
            return ""