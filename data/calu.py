# 假设已经有 TP, FP, TN, FN 的值
TP = 485  # 示例：真正例
FP = 6  # 示例：假正例
TN = 478  # 示例：真负例
FN = 0   # 示例：假负例

# 计算 TPR (True Positive Rate)
TPR = TP / (TP + FN)

# 计算 FPR (False Positive Rate)
FPR = FP / (FP + TN)

# 计算 ACC (Accuracy)
ACC = (TP + TN) / (TP + TN + FP + FN)

# 输出结果
print(f"TPR (True Positive Rate): {TPR:.5f}")
print(f"FPR (False Positive Rate): {FPR:.5f}")
print(f"ACC (Accuracy): {ACC:.5f}")
