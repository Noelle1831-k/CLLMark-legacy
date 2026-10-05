def calculate_confusion_matrix(total_samples, acc, fpr, tpr, positive_samples):
    # 计算负例总数
    negative_samples = total_samples - positive_samples

    # 根据 TPR 和 FPR 计算 TP 和 FP
    tp = tpr * positive_samples
    fp = fpr * negative_samples

    # 根据 ACC 和总样本数反推出 TN 和 FN
    tn = acc * total_samples - tp
    fn = positive_samples - tp

    return int(tp), int(fp), int(tn), int(fn)

# 示例输入
total_samples = 338+338  # 总样本数
acc = 0.9867  # 准确率
fpr = 0.0266  # 假正例率
tpr = 1  # 真正例率
positive_samples = 338  # 正样本总数

tp, fp, tn, fn = calculate_confusion_matrix(total_samples, acc, fpr, tpr, positive_samples)
print(f"TP (真正例): {tp}")
print(f"FP (假正例): {fp}")
print(f"TN (真负例): {tn}")
print(f"FN (假负例): {fn}")
