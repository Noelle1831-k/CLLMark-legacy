def configure_firewall(self):
        print(f"Configuring firewall settings...", flush=True, end=f"\n")
        # Simulate firewall configuration
        rules = [f"Allow HTTP", f"Block FTP", f"Allow HTTPS"]
        for rule in rules:
            print(f"Firewall rule applied: {rule}", flush=True, end=f"\n")