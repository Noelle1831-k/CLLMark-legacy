import os
from openai import OpenAI
import jsonlines
from tqdm import tqdm
from concurrent.futures import ThreadPoolExecutor, as_completed

input_file = "mbcpp_release_v1.2.jsonl"

prompts = []
with jsonlines.open(input_file) as reader:
    for obj in reader:
        prompts.append(obj)

client = OpenAI(
    api_key=os.environ["OPENAI_API_KEY"],
    base_url=os.environ.get("OPENAI_BASE_URL", "https://run.v36.cm/v1/"),
    default_headers={"x-foo": "true"}
)

def generate_code(idx, data):
    prompt = data['prompt']
    task_id = data['task_id']

    response = client.chat.completions.create(
        model="gpt-4o",
        messages=[
            {
                "role": "system",
                "content": "You are a professional C++ programmer.I need you to complete the code according to the prompt,"
            },
            {
                "role": "user",
                "content": prompt + 'Do not include the function definition part; only generate the code inside the function body without any comment,without any code block formatting (e.g., no ``` markers).'
            },
        ],
    )
    generated_code = response.choices[0].message.content
    print(generated_code)
    return {
        "task_id": task_id,
        "completion": generated_code,
        "language": "cpp"
    }

start_idx = 0
end_idx = 10
output_file = f"generated_codes_{start_idx+1}-{end_idx+1}_4o_python.jsonl"

with jsonlines.open(output_file, mode='w') as writer:
    with ThreadPoolExecutor(max_workers=20) as executor:
        future_to_idx = {
            executor.submit(generate_code, idx, prompts[idx]): idx
            for idx in range(start_idx, min(end_idx + 1, len(prompts)))
        }

        for future in tqdm(as_completed(future_to_idx), total=len(future_to_idx), desc="Processing prompts"):
            idx = future_to_idx[future]
            try:
                result = future.result()
                writer.write(result)  # 将结果逐行写入 JSONL 文件
            except Exception as e:
                print(f"Error processing index {idx}: {e}")

print(f"Results saved to {output_file}")
