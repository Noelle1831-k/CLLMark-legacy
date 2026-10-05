def export_progression(self, progression, format):
        if format == "pdf":
            print("Exporting to PDF...")
            # Simulate PDF export
            with open("progression.pdf", 'w') as file:
                for chord in progression:
                    file.write(f"{chord}\n")