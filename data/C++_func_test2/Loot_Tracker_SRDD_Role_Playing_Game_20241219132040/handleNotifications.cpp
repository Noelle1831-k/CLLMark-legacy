void UIHandler::handleNotifications() {
    notificationSystem.checkNotifications(inventoryManager.getItems());
}