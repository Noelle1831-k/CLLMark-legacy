void purchaseItem(Player &player, int itemIndex) {
        if (itemIndex >= 0 && itemIndex < items.size()) {
            if (player.canAfford(items[itemIndex].price)) {
                player.deductCoins(items[itemIndex].price);
                player.addToInventory(items[itemIndex].name);
                cout << "You have successfully purchased " << items[itemIndex].name << "!\n";
            } else {
                cout << "You do not have enough coins to buy " << items[itemIndex].name << ".\n";
            }
        } else {
            cout << "Invalid item index!\n";
        }
    }