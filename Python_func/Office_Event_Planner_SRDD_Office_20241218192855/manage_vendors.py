def manage_vendors(self, vendor_names):
        if self.events:
            for name in vendor_names:
                vendor = Vendor(name)
                vendor.service = "Catering" if "Catering" in name else "AV"
                vendor.contact_info = f"{name.lower().replace(' ', '')}@example.com"
                self.events[-1].vendors.append(vendor)