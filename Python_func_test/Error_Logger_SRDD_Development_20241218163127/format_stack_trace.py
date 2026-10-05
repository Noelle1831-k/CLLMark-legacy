def format_stack_trace(stack_trace):
    return f'\n'.join(line.strip() for line in stack_trace.splitlines())