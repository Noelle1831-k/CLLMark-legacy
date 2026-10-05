#define MAX_LINES 50
#define MAX_VARIABLES 5
typedef struct {
    int line;
    char op[5];
    char var1;
    char var2[2];
    char var3[2];
} Instruction;
typedef struct {
    char name;
    int value;
} Variable;
Instruction program[MAX_LINES];
Variable vars[MAX_VARIABLES];
int var_count = 0;
int line_count;
int get_variable_index(char var) {
    for (int i = 0; i < var_count; i++) {
        if (vars[i].name == var) {
            return i;
        }
    }
    vars[var_count].name = var;
    vars[var_count].value = 0;
    return var_count++;
}
void execute_program() {
    int pc = 0;
    int executed[MAX_LINES] = {0};
    while (pc < line_count) {
        if (executed[pc]) {
            printf("inf\n");
            return;
        }
        executed[pc] = 1;
        Instruction *instr = &program[pc];
        int idx1 = get_variable_index(instr->var1);
        int idx2 = (instr->var2[0] >= 'a' && instr->var2[0] <= 'z') ? get_variable_index(instr->var2[0]) : -1;
        int idx3 = (instr->var3[0] >= 'a' && instr->var3[0] <= 'z') ? get_variable_index(instr->var3[0]) : -1;
        if (strcmp(instr->op, "ADD") == 0) {
            int val2 = (idx2 != -1) ? vars[idx2].value : atoi(instr->var2);
            int val3 = (idx3 != -1) ? vars[idx3].value : atoi(instr->var3);
            int result = val2 + val3;
            if (result < 0 || result > 15) break;
            vars[idx1].value = result;
        }
        else if (strcmp(instr->op, "SUB") == 0) {
            int val2 = (idx2 != -1) ? vars[idx2].value : atoi(instr->var2);
            int val3 = (idx3 != -1) ? vars[idx3].value : atoi(instr->var3);
            int result = val2 - val3;
            if (result < 0 || result > 15) break;
            vars[idx1].value = result;
        }
        else if (strcmp(instr->op, "SET") == 0) {
            int val2 = (idx2 != -1) ? vars[idx2].value : atoi(instr->var2);
            if (val2 < 0 || val2 > 15) break;
            vars[idx1].value = val2;
        }
        else if (strcmp(instr->op, "IF") == 0) {
            if (vars[idx1].value != 0) {
                int target = atoi(instr->var2);
                int found = 0;
                for (int j = 0; j < line_count; j++) {
                    if (program[j].line == target) {
                        pc = j;
                        found = 1;
                        break;
                    }
                }
                if (!found) break;
                continue;
            }
        }
        else if (strcmp(instr->op, "HALT") == 0) {
            break;
        }
        pc++;
    }
    for (int i = 0; i < var_count; i++) {
        printf("%c=%d\n", vars[i].name, vars[i].value);
    }
}