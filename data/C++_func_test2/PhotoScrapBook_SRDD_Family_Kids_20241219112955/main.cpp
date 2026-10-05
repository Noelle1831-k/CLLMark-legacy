int main() {
    cout << "Welcome to PhotoScrapBook!" << endl;
    Scrapbook scrapbook;
    PhotoManager photoManager;
    ShareManager shareManager;
    int choice;
    while (true) {
        showMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice) {
            case 1: {
                string photo;
                cout << "Enter photo filename to upload: ";
                cin >> photo;
                photoManager.uploadPhoto(photo);
                break;
            }
            case 2: {
                string photo, caption, templateName, sticker;
                ScrapbookPage page;
                cout << "Enter photo filename for page: ";
                cin >> photo;
                page.addPhoto(photo);
                cout << "Enter caption for the page: ";
                cin.ignore();
                getline(cin, caption);
                page.addCaption(caption);
                cout << "Enter template name: ";
                cin >> templateName;
                page.applyTemplate(templateName);
                cout << "Enter sticker name: ";
                cin >> sticker;
                page.addSticker(sticker);
                scrapbook.addPage(page);
                break;
            }
            case 3: {
                cout << "\nRendering Scrapbook..." << endl;
                scrapbook.renderScrapbook();
                break;
            }
            case 4: {
                string email;
                cout << "Enter email address to share scrapbook: ";
                cin >> email;
                shareManager.shareViaEmail(email, scrapbook);
                break;
            }
            case 5: {
                cout << "Exiting PhotoScrapBook..." << endl;
                return 0;
            }
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }
}