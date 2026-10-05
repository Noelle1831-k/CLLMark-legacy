void viewCategoryDetails() const {
        string category;
        cout << "Enter category name to view details: ";
        cin.ignore();
        getline(cin, category);
        const Category* cat = findCategory(category);
        if (cat) {
            cat->viewTransactions();
        } else {
            cout << "Category not found." << endl;
        }
    }