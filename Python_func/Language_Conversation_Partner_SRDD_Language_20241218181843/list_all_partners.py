def list_all_partners(self):
        return [partner.get_user_info() for partner in self.partners]