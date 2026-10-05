bool ResourceManager::checkResources(int foodReq, int goldReq, int materialsReq) {
    return food >= foodReq && gold >= goldReq && materials >= materialsReq;
}