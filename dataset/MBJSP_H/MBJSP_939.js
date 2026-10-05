function sortedModels(models) {
  return models.sort((a, b) => {
    return b.model - a.model;
  })
}
