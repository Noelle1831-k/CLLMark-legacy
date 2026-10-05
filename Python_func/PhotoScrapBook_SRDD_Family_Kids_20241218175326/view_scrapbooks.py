def view_scrapbooks(self, user):
        for sb in user.scrapbooks:
            print(f"Scrapbook: {sb.title}")
            for page in sb.pages:
                print(f"  Page: {page.title}")
                for photo in page.photos:
                    print(f"    Photo: {photo.filename}")
                for caption in page.captions:
                    print(f"    Caption: {caption.text}")
                for sticker in page.stickers:
                    print(f"    Sticker: {sticker.name}")
                for element in page.decorative_elements:
                    print(f"    Element: {element.name}")