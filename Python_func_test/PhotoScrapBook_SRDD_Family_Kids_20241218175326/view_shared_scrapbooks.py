def view_shared_scrapbooks(self, user):
        if user.username not in self.pending_shares or not self.pending_shares[user.username]:
            print("No shared scrapbooks.")
            return
        print("Shared scrapbooks:")
        for idx, share_instance in enumerate(self.pending_shares[user.username]):
            print(f"{idx + 1}. {share_instance.scrapbook.title}")
        sb_choice = int(input("Enter the number of the scrapbook to accept: ")) - 1
        if sb_choice < 0 or sb_choice >= len(self.pending_shares[user.username]):
            print("Invalid choice.")
            return
        user.add_scrapbook(self.pending_shares[user.username][sb_choice].scrapbook)
        del self.pending_shares[user.username][sb_choice]
        print("Scrapbook accepted successfully!")