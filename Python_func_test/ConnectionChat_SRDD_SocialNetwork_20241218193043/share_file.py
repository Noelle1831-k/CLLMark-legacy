def share_file(self, sender, receiver, file_name):
        if receiver.name not in self.shared_files:
            self.shared_files[receiver.name] = []
        self.shared_files[receiver.name].append((sender.name, file_name))