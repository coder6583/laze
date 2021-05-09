#include "tree.h"

T_stm T_IfStm(T_exp test, T_type result, T_stm then, T_stm elsee)
{
    T_stm p = checked_malloc(sizeof(*p));
    p -> kind = T_ifStm;
    p -> u.iff.test = test;
    p -> u.iff.result = result;
    p -> u.iff.then = then;
    p -> u.iff.elsee = elsee;
    return p;
}
T_stm T_BlockStm(T_stm body)
{
    T_stm p = checked_malloc(sizeof(*p));
    p -> kind = T_blockStm;
    p -> u.block.body = body;
    return p;
}
T_stm T_LoopStm(T_exp test, T_stm body, int index)
{
    T_stm p = checked_malloc(sizeof(*p));
    p -> kind = T_loopStm;
    p -> u.loop.test = test;
    p -> u.loop.body = body;
    p -> u.loop.index = index;
    return p;
}
T_stm T_BinOpStm(T_type type, T_binOp oper, T_exp lhs, T_exp rhs)
{
    T_stm p = checked_malloc(sizeof(*p));
    p -> kind = T_binOpStm;
    p -> u.binOp.type = type;
    p -> u.binOp.oper = oper;
    p -> u.binOp.lhs = lhs;
    p -> u.binOp.rhs = rhs;
    return p;
}
T_stm T_SetLocalStm(int index, T_exp exp)
{
    T_stm p = checked_malloc(sizeof(*p));
    p -> kind = T_setLocalStm;
    p -> u.setLocal.index = index;
    p -> u.setLocal.exp = exp;
    return p;
}
T_stm T_SetGlobalStm(int index, T_exp exp)
{
    T_stm p = checked_malloc(sizeof(*p));
    p -> kind = T_setLocalStm;
    p -> u.setLocal.index = index;
    p -> u.setLocal.exp = exp;
    return p;
}
T_stm T_SeqStm(T_stmList list)
{
    T_stm p = checked_malloc(sizeof(*p));
    p -> kind = T_seqStm;
    p -> u.seq = list;
    return p;
}
T_stm T_StoreStm(T_exp addr, T_exp data)
{
    T_stm p = checked_malloc(sizeof(*p));
    p -> kind = T_storeStm;
    p -> u.store.addr = addr;
    p -> u.store.data = data;
    return p;
}
T_stm T_BreakStm(int depth)
{
    T_stm p = checked_malloc(sizeof(*p));
    p -> kind = T_breakStm;
    p -> u.depth = depth;
    return p;
}
T_stm T_CallStm(int index, string label, T_expList args)
{
    T_stm p = checked_malloc(sizeof(*p));
    p -> kind = T_callStm;
    p -> u.call.index = index;
    p -> u.call.label = label;
    p -> u.call.args = args;
    return p;
}

T_exp T_BinOpExp(T_type type, T_binOp oper, T_exp lhs, T_exp rhs)
{
    T_exp p = checked_malloc(sizeof(*p));
    p -> kind = T_binOpExp;
    p -> type = type;
    p -> u.binOp.oper = oper;
    p -> u.binOp.lhs = lhs;
    p -> u.binOp.rhs = rhs;
    return p;
}
T_exp T_UniOpExp(T_type type, T_uniOp oper, T_exp exp)
{
    T_exp p = checked_malloc(sizeof(*p));
    p -> kind = T_uniOpExp;
    p -> type = type;
    p -> u.uniOp.oper = oper;
    p -> u.uniOp.exp = exp;
    return p;
}
T_exp T_ConstExp(T_type type, A_exp exp)
{
    T_exp p = checked_malloc(sizeof(*p));
    p -> kind = T_constExp;
    p -> type = type;
    p -> u.constt.exp = exp;
    return p;
}
T_exp T_GetLocalExp(T_type type, int index)
{
    T_exp p = checked_malloc(sizeof(*p));
    p -> kind = T_getLocalExp;
    p -> type = type;
    p -> u.getLocal.index = index;
    return p;
}
T_exp T_GetGlobalExp(T_type type, int index)
{
    T_exp p = checked_malloc(sizeof(*p));
    p -> kind = T_getGlobalExp;
    p -> type = type;
    p -> u.getGlobal.index = index;
    return p;
}
T_exp T_CallExp(T_type type, int index, string label, T_expList args)
{
    T_exp p = checked_malloc(sizeof(*p));
    p -> kind = T_callExp;
    p -> type = type;
    p -> u.call.index = index;
    p -> u.call.label = label;
    p -> u.call.args = args;
    return p;
}
T_exp T_IfExp(T_type type, T_exp test, T_exp then, T_exp elsee)
{
    T_exp p = checked_malloc(sizeof(*p));
    p -> kind = T_ifExp;
    p -> type = type;
    p -> u.iff.test = test;
    p -> u.iff.then = then;
    p -> u.iff.elsee = elsee;
    return p;
}

T_fundec T_Fundec(T_typeList params, T_typeList locals, T_type result, T_stm body, bool isMain, int index)
{
    T_fundec p = checked_malloc(sizeof(*p));
    p -> params = params;
    p -> locals = locals;
    p -> result = result;
    p -> body = body;
    p -> isMain = isMain;
    p -> index = index;
    return p;
}

T_module T_FuncMod(T_fundec func)
{
    T_module p = checked_malloc(sizeof(*p));
    p -> kind = T_func;
    p -> u.func = func;
    return p;
}
T_module T_MemMod(int pageSize)
{
    T_module p = checked_malloc(sizeof(*p));
    p -> kind = T_mem;
    p -> u.memory.pageSize = pageSize;
    return p;
}
T_module T_DataMod(T_exp exp, string data)
{
    T_module p = checked_malloc(sizeof(*p));
    p -> kind = T_data;
    p -> u.data.exp = exp;
    p -> u.data.data = data;
    return p;
}
T_module T_ImportMod(string module, string name, T_module import)
{
    T_module p = checked_malloc(sizeof(*p));
    p -> kind = T_import;
    p -> u.import.module = module;
    p -> u.import.name = name;
    p -> u.import.import = import;
    return p;
}
T_module T_ExportMod(string name, T_module export)
{
    T_module p = checked_malloc(sizeof(*p));
    p -> kind = T_export;
    p -> u.export.name = name;
    p -> u.export.export = export;
    return p;
}
T_stmList T_StmList(T_stm head, T_stmList tail)
{
    T_stmList p = checked_malloc(sizeof(*p));
    p -> head = head;
    p -> tail = tail;
    return p;
}
T_expList T_ExpList(T_exp head, T_expList tail)
{
    T_expList p = checked_malloc(sizeof(*p));
    p -> head = head;
    p -> tail = tail;
    return p;
}
T_moduleList T_ModuleList(T_module head, T_moduleList tail)
{
    T_moduleList p = checked_malloc(sizeof(*p));
    p -> head = head;
    p -> tail = tail;
    return p;
}