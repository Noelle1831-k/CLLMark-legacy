def search_professionals(self, industry, all_professionals):
        # Filter professionals based on industry
        matching_professionals = [prof for prof in all_professionals if prof.industry == industry]
        print(f"Found {len(matching_professionals)} professionals in {industry}.")
        return matching_professionals