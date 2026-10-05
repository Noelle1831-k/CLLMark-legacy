from .transform10_return import *
from .transform13_fun import rec_func, cvt_func
from .transform2_list import *
from .transform3_dict import *
from .transform4_range import *
from .transform5_call import *
from .transform6_string import *
from .transform7_op import *
from .transform9_declare import *

transformation_operators = {
    'print': {
        'add_flush': (rec_CallPrintWithoutFlush, cvt_CallPrint2CallPrintWithFlush, rec_CallPrintWithFlush),
        'del_flush': (rec_CallPrintWithFlush, cvt_CallPrintWithFlush2CallPrint, rec_CallPrintWithoutFlush),
        'add_end': (rec_CallPrintWithoutEnd, cvt_CallPrint2CallPrintWithEnd, rec_CallPrintWithEndn),
        'del_end': (rec_CallPrintWithEndn, cvt_CallPrintWithEndn2CallPrint, rec_CallPrintWithoutEnd),
    },
    'list': {
        'init_call_list': (rec_InitList, cvt_InitList2InitCallList, rec_InitCallList),
        'init_list': (rec_InitCallList, cvt_InitCallList2InitList, rec_InitList),
        'call_list': (rec_List, cvt_List2CallList, rec_CallList),
        'list': (rec_CallList, cvt_CallList2List, rec_List),
    },
    'dict': {
        'init_call_dict': (rec_InitDict, cvt_InitDict2InitCallDict, rec_InitCallDict),
        'init_dict': (rec_InitCallDict, cvt_InitCallDict2InitDict, rec_InitDict),
        'call_dict': (rec_Dict, cvt_Dict2CallDict, rec_CallDict),
        'dict': (rec_CallDict, cvt_CallDict2Dict, rec_Dict)
    },
    'range': {
        'add_zero': (rec_CallRange, cvt_CallRange2CallRangeWithZero, rec_CallRangeWithZero),
        'del_zero': (rec_CallRangeWithZero, cvt_CallRangeWithZero2CallRange, rec_CallRange),
        'add_slice_index': (rec_SubscriptSlice, cvt_AddSliceIndex, rec_SubscriptSlice),
        'del_slice_index': (rec_SubscriptSlice, cvt_DelSliceIndex, rec_SubscriptSlice),
        'add_index': (rec_ListIndex, cvt_AddIndex, match_TwoIndex)
    },
    'call': {
        'add_magic_call': (rec_Call, cvt_Call2MagicCall, rec_MagicCall),
        'del_magic_call': (rec_MagicCall, cvt_MagicCall2Call, rec_Call),
    },
    'string': {
        'single': (rec_string, cvt_single_quotation, match_StringSingle),
        'double': (rec_string, cvt_double_quotation, match_StringDouble),
        'add_f': (rec_not_format_string_without_f, cvt_add_f, match_format_string),
        'del_f':(rec_not_format_string_with_f,cvt_del_f,match_format_string)
    },
    'op': {
        'assignment': (rec_AugmentedAssignment, cvt_AugmentedAssignment2Assignment, rec_Assignment),
        'augmented_assignment': (rec_Assignment, cvt_Assignment2AugmentedAssignment, rec_AugmentedAssignment),
        'e2ne': (rec_Equal, cvt_Equal2NotEqual, match_LeftConst),
        'e2ne_re': (rec_equal_reverse, cvt_Equal2NotEqual_reverse, match_LeftConst),
        'ne2e': (rec_Equal, cvt_NotEqual2Equal, match_LeftConst),
        'ne2e_re': (rec_not_equal_reverse, cvt_NotEqual2Equal_reverse, match_LeftConst),
        'smaller': (rec_CmpOptBigger, cvt_Smaller2Bigger, rec_CmpOptSmaller),
        'bigger': (rec_CmpOptSmaller, cvt_Bigger2Smaller, rec_CmpOptBigger),
        'expcmp': (rec_Cmp, cvt_Equal, rec_exp_cmp),
        'cmp': (rec_exp_cmp,cvt_cmp,rec_Cmp),
        'hashequalB': (rec_Equal_nolimit,cvt_EqualBiggerHashTrans,match_Equal),
        'hashequalS': (rec_Equal_nolimit,cvt_EqualSmallHashTrans,match_Equal),
        'hashnotequalB': (rec_Equal_nolimit, cvt_NotEqualBiggerHashTrans, match_Equal),
        'hashnotequalS': (rec_Equal_nolimit, cvt_NotEqualSmallHashTrans, match_Equal)
    },
    'declare': {
        'split': (rec_AssignmentMerge, cvt_Merge2Split, rec_AssignmentMergeSame),
        'merge_simple': (rec_AssignmentMergeSame, cvt_Merge2MergeSimple, rec_AssignmentMerge),
    },
    'return': {
        'add_bracket': (rec_MultiReturnNotTuple, cvt_ReturnTuple, rec_MultiReturnWithTuple),
        'del_bracket': (rec_MultiReturnWithTuple, cvt_ReturnWithoutTuple, rec_MultiReturnNotTuple),
        'add_None': (rec_MultiReturnWithoutNone, cvt_AddNone, rec_MultiReturnWithNone),
        'del_None': (rec_MultiReturnWithNone, cvt_DelNone, rec_MultiReturnWithoutNone)
    },
    'func':{
        'get_func':(rec_func,cvt_func,rec_func)
    }
}

