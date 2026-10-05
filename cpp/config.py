from .transform13_fun import rec_func, cvt_func
from .transform1_blank import *
from .transform2_op import *
from .transform3_update import *
from .transform4_main import *
from .transform6_declare import *
from .transform7_loop import *
from .transform8_if import *
from .transform9_cpp import *

transformation_operators = {
    'op': {
        'assignment': (rec_AugmentedAssignment, cvt_AugmentedAssignment2Assignment, rec_Assignment),
        'augmented_assignment': (rec_Assignment, cvt_Assignment2AugmentedAssignment, rec_AugmentedAssignment),
        'e2ne': (rec_Equal, cvt_Equal2NotEqual, match_LeftConst),
        'e2ne_re': (rec_equal_reverse, cvt_Equal2NotEqual_reverse, match_LeftConst),
        'ne2e': (rec_Equal, cvt_NotEqual2Equal, match_LeftConst),
        'ne2e_re': (rec_not_equal_reverse, cvt_NotEqual2Equal_reverse, match_LeftConst),
        'smaller': (rec_CmpOptBigger, cvt_Bigger2Smaller, rec_CmpOptSmaller),
        'bigger': (rec_CmpOptSmaller, cvt_Smaller2Bigger, rec_CmpOptBigger),
        'expcmp': (rec_Cmp, cvt_Equal, rec_exp_cmp),
        'cmp': (rec_exp_cmp,cvt_cmp,rec_Cmp),
        'hashequalB': (rec_Equal_nolimit,cvt_EqualBiggerHashTrans,match_Equal),
        'hashequalS': (rec_Equal_nolimit,cvt_EqualSmallHashTrans,match_Equal),
        'hashnotequalB': (rec_Equal_nolimit, cvt_NotEqualBiggerHashTrans, match_Equal),
        'hashnotequalS': (rec_Equal_nolimit, cvt_NotEqualSmallHashTrans, match_Equal)
    },
    'update': {
        'left': (rec_ToLeft, cvt_ToLeft, rec_LeftUpdate),
        'right': (rec_ToRight, cvt_ToRight, rec_RightUpdate),
    },
    'main': {
        'int_void_return': (rec_Main, cvt_IntVoidReturn, match_IntVoidReturn),
        'int_void': (rec_Main, cvt_IntVoid, match_IntVoid),
        'int_return': (rec_Main, cvt_IntReturn, match_IntReturn),
        'int': (rec_Main, cvt_Int, match_Int),
        'int_arg_return': (rec_Main, cvt_IntArgReturn, match_IntArgReturn),
        'int_arg': (rec_Main, cvt_IntArg, match_IntArg),
        'void_arg': (rec_Main, cvt_VoidArg, match_VoidArg),
        'void': (rec_Main, cvt_Void, match_Void),
    },
    'declare': {
        'split': (rec_DeclareMerge, cvt_DeclareMerge2Split, rec_DeclareSplit),
        'merge': (rec_DeclareSplit, cvt_DeclareSplit2Merge, rec_DeclareMerge),
    },
    'loop': {
        'obc': (rec_For, cvt_OBC, match_ForOBC),
        'aoc': (rec_For, cvt_AOC, match_ForAOC),
        'abo': (rec_For, cvt_ABO, match_ForABO),
        'aoo': (rec_For, cvt_AOO, match_ForAOO),
        'obo': (rec_For, cvt_OBO, match_ForOBO),
        'ooc': (rec_For, cvt_OOC, match_ForOOC),
        'ooo': (rec_For, cvt_OOO, match_ForOOO),
        'for': (rec_loop, cvt_for, match_For),
    },
    'if': {
        'merge': (rec_IfMerge, cvt_IfSplit, rec_IfSplit),
        'switch': (rec_If, cvt_if2switch, rec_Switch),
        'if': (rec_Switch, cvt_switch2if, rec_If),
    },
    'cpp': {
        'stdc++': (rec_Include, cvt_AddBitsStd, match_Include),
        'namespace': (rec_NameSpaceStd, cvt_AddStd, match_NameSpaceStd),
        'sync_with_false': (rec_MainWithoutSync, cvt_AddSyncWithFalse, match_MainWithSync),
        'struct': (rec_StructDeclare, cvt_DelStruct, match_StructDeclare),
        'coutendl': (rec_Printf, cvt_Printf2CoutEndl, match_CoutEndl),
        'cout': (rec_Printf, cvt_Printf2Cout, rec_Cout),
        'del_endl': (rec_Cout, cvt_DelEndl, match_CoutNoEndl),
        'printf': (rec_Cout, cvt_Cout2Printf, rec_Printf),
        'cin': (rec_Scanf, cvt_Scanf2Cin, rec_Cin),
        'scanf': (rec_Cin, cvt_Cin2Scanf, rec_Scanf),
    },
    'func':{
        'get_func':(rec_func,cvt_func,rec_func)
    }
}