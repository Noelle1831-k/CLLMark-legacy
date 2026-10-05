import json

# 定义文件路径
file1_path = 'z:/testc.jsonl_results.jsonl'
file2_path = 'z:/output_cpp.jsonl_results.jsonl'

# 读取JSONL文件并转换为字典
def read_jsonl(file_path):
    data = {}
    with open(file_path, 'r', encoding='utf-8') as file:
        for line in file:
            record = json.loads(line.strip())
            task_id = record['task_id']
            passed = record['passed']
            data[task_id] = passed
    return data

# 获取两个文件中的数据
data1 = read_jsonl(file1_path)
data2 = read_jsonl(file2_path)

# 找出相同task_id但passed结果不同的task_id
different_results = []
for task_id in data1:
    if task_id in data2 and data1[task_id] != data2[task_id]:
        different_results.append(task_id)

# 输出结果
print("具有相同task_id但passed结果不同的task_id如下：")
print(different_results)
