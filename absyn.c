/*
 * absyn.c - Abstract Syntax Functions. Most functions create an instance of an
 *           abstract syntax rule.
 */

#include "util.h"
#include "symbol.h" /* symbol table data structures */
#include "absyn.h"  /* abstract syntax data structures */

A_stm A_AssignStm(A_pos pos, A_var var, A_exp exp)
{
    A_stm p = checked_malloc(sizeof(*p));
    p-> kind = A_assignStm;
    p-> pos = pos;
    p-> u.assign.var = var;
    p-> u.assign.exp = exp;
    return p;
}
A_stm A_IfStm(A_pos pos, A_exp test, A_stm then, A_stm elsee)
{
    A_stm p = checked_malloc(sizeof(*p));
    p-> kind = A_ifStm;
    p-> pos = pos;
    p-> u.iff.test = test;
    p-> u.iff.then = then;
    p-> u.iff.elsee = elsee;
    return p;
}
A_stm A_WhileStm(A_pos pos, A_exp test, A_stm body)
{
    A_stm p = checked_malloc(sizeof(*p));
    p-> kind = A_whileStm;
    p-> pos = pos;
    p-> u.whilee.test = test;
    p-> u.whilee.body = body;
    return p;
}
A_stm A_ForStm(A_pos pos, A_stm assign, A_exp condition, A_stm increment, A_stm body)
{
    A_stm p = checked_malloc(sizeof(*p));
    p-> kind = A_forStm;
    p-> pos = pos;
    p-> u.forr.assign = assign;
    p-> u.forr.condition = condition;
    p-> u.forr.increment = increment;
    p-> u.forr.body = body;
    return p;
}
A_stm A_BreakStm(A_pos pos)
{
    A_stm p = checked_malloc(sizeof(*p));
    p-> kind = A_breakStm;
    p-> pos = pos;
    return p;
}
A_stm A_ContinueStm(A_pos pos)
{
    A_stm p = checked_malloc(sizeof(*p));
    p-> kind = A_continueStm;
    return p;
}
A_stm A_CompoundStm(A_pos pos, A_stmList stmlist)
{
    A_stm p = checked_malloc(sizeof(*p));
    p-> kind = A_compoundStm;
    p-> pos = pos;
    p -> u.compound = stmlist;
    return p;
}
A_stm A_DeclarationStm(A_pos pos, A_dec dec)
{
    A_stm p = checked_malloc(sizeof(*p));
    p-> kind = A_declarationStm;
    p-> pos = pos;
    p-> u.declaration.dec = dec;
    return p;
}
A_stm A_CallStm(A_pos pos, S_symbol func, A_expList args)
{
    A_stm p = checked_malloc(sizeof(*p));
    p-> kind = A_callStm;
    p-> pos = pos;
    p-> u.call.func = func;
    p->u.call.args  = args;
    return p;
}
A_stm A_ReturnStm(A_pos pos, A_exp exp)
{
    A_stm p = checked_malloc(sizeof(*p));
    p-> kind - A_returnStm;
    p -> pos = pos;
    p-> u.returnn.ret = exp;
    return p;
}

A_var A_SimpleVar(A_pos pos, S_symbol sym)
{
    A_var p = checked_malloc(sizeof(*p));
    p->kind=A_simpleVar;
    p->pos=pos;
    p->u.simple=sym;
    return p;
}

A_var A_FieldVar(A_pos pos, A_var var, S_symbol sym)
{
    A_var p = checked_malloc(sizeof(*p));
    p->kind=A_fieldVar;
    p->pos=pos;
    p->u.field.var=var;
    p->u.field.sym=sym;
    return p;
}

A_var A_SubscriptVar(A_pos pos, A_var var, A_exp exp)
{
    A_var p = checked_malloc(sizeof(*p));
    p->kind=A_subscriptVar;
    p->pos=pos;
    p->u.subscript.var=var;
    p->u.subscript.exp=exp;
    return p;
}

A_var A_IntVar(A_pos pos, A_var var)
{
    return var;
}

A_var A_StringVar(A_pos pos, A_var var)
{
    return var;
}

A_var A_RealVar(A_pos pos, A_var var)
{
    return var;
}

A_exp A_VarExp(A_pos pos, A_var var)
{
    A_exp p = checked_malloc(sizeof(*p));
    p->kind=A_varExp;
    p->pos=pos;
    p->u.var=var;
    return p;
}

A_exp A_NilExp(A_pos pos)
{
    A_exp p = checked_malloc(sizeof(*p));
    p->kind=A_nilExp;
    p->pos=pos;
    return p;
}

A_exp A_IntExp(A_pos pos, int i)
{
    A_exp p = checked_malloc(sizeof(*p));
    p->kind=A_intExp;
    p->pos=pos;
    p->u.intt=i;
    return p;
}

A_exp A_StringExp(A_pos pos, string s)
{
    A_exp p = checked_malloc(sizeof(*p));
    p->kind=A_stringExp;
    p->pos=pos;
    p->u.stringg=s;
    return p;
}

A_exp A_RealExp(A_pos pos, double f)
{
    A_exp p = checked_malloc(sizeof(*p));
    p->kind=A_realExp;
    p->pos=pos;
    p->u.intt=f;
    return p;
}

A_exp A_BoolExp(A_pos pos, bool b)
{
    A_exp p = checked_malloc(sizeof(*p));
    p -> kind = A_boolExp;
    p -> pos = pos;
    p -> u.booll = b;
    return p;
}

A_exp A_CallExp(A_pos pos, S_symbol func, A_expList args)
{
    A_exp p = checked_malloc(sizeof(*p));
    p->kind=A_callExp;
    p->pos=pos;
    p->u.call.func=func;
    p->u.call.args -> head =args-> head;
    p->u.call.args -> tail =args-> tail;
    return p;
}

A_exp A_OpExp(A_pos pos, A_oper oper, A_exp left, A_exp right)
{
    A_exp p = checked_malloc(sizeof(*p));
    p->kind=A_opExp;
    p->pos=pos;
    p->u.op.oper=oper;
    p->u.op.left=left;
    p->u.op.right=right;
    return p;
}

A_exp A_RecordExp(A_pos pos, S_symbol typ, A_efieldList fields)
{
    A_exp p = checked_malloc(sizeof(*p));
    p->kind=A_recordExp;
    p->pos=pos;
    p->u.record.typ=typ;
    p->u.record.fields=fields;
    return p;
}

A_exp A_SeqExp(A_pos pos, A_expList seq)
{
    A_exp p = checked_malloc(sizeof(*p));
    p->kind=A_seqExp;
    p->pos=pos;
    p->u.seq=seq;
    return p;
}

A_exp A_AssignExp(A_pos pos, A_var var, A_exp exp)
{
    A_exp p = checked_malloc(sizeof(*p));
    p->kind=A_assignExp;
    p->pos=pos;
    p->u.assign.var=var;
    p->u.assign.exp=exp;
    return p;
}

A_exp A_IfExp(A_pos pos, A_exp test, A_exp then, A_exp elsee)
{
    A_exp p = checked_malloc(sizeof(*p));
    p->kind=A_ifExp;
    p->pos=pos;
    p->u.iff.test=test;
    p->u.iff.then=then;
    p->u.iff.elsee=elsee;
    return p;
}

// A_exp A_WhileExp(A_pos pos, A_exp test, A_exp body)
// {
//     A_exp p = checked_malloc(sizeof(*p));
//     p->kind=A_whileExp;
//     p->pos=pos;
//     p->u.whilee.test=test;
//     p->u.whilee.body=body;
//     return p;
// }

// A_exp A_ForExp(A_pos pos, S_symbol var, A_exp lo, A_exp hi, A_exp body)
// {
//     A_exp p = checked_malloc(sizeof(*p));
//     p->kind=A_forExp;
//     p->pos=pos;
//     p->u.forr.var=var;
//     p->u.forr.lo=lo;
//     p->u.forr.hi=hi;
//     p->u.forr.body=body;
//     p->u.forr.escape=TRUE;
//     return p;
// }

// A_exp A_BreakExp(A_pos pos)
// {
//     A_exp p = checked_malloc(sizeof(*p));
//     p->kind=A_breakExp;
//     p->pos=pos;
//     return p;
// }

A_exp A_ArrayExp(A_pos pos, S_symbol typ, A_exp size, A_exp init)
{
    A_exp p = checked_malloc(sizeof(*p));
    p->kind=A_arrayExp;
    p->pos=pos;
    p->u.array.typ=typ;
    p->u.array.size=size;
    p->u.array.init=init;
    return p;
}

A_dec A_FunctionDec(A_pos pos, A_fundecList function)
{
    A_dec p = checked_malloc(sizeof(*p));
    p->kind=A_functionDec;
    p->pos=pos;
    p->u.function=function;
    return p;
}

A_dec A_VarDec(A_pos pos, A_stm assign, S_symbol typ)
{
    A_dec p = checked_malloc(sizeof(*p));
    p->kind=A_varDec;
    p->pos=pos;
    p->u.var.var=assign->u.assign.var;
    p->u.var.typ=typ;
    p->u.var.init=assign->u.assign.exp;
    p->u.var.escape=TRUE;
    return p;
}

A_dec A_TypeDec(A_pos pos, A_nametyList type)
{
    A_dec p = checked_malloc(sizeof(*p));
    p->kind=A_typeDec;
    p->pos=pos;
    p->u.type=type;
    return p;
}

A_ty A_NameTy(A_pos pos, S_symbol name)
{
    A_ty p = checked_malloc(sizeof(*p));
    p->kind=A_nameTy;
    p->pos=pos;
    p->u.name=name;
    return p;
}

A_ty A_RecordTy(A_pos pos, A_fieldList record)
{
    A_ty p = checked_malloc(sizeof(*p));
    p->kind=A_recordTy;
    p->pos=pos;
    p->u.record=record;
    return p;
}

A_ty A_ArrayTy(A_pos pos, S_symbol array)
{
    A_ty p = checked_malloc(sizeof(*p));
    p->kind=A_arrayTy;
    p->pos=pos;
    p->u.array=array;
    return p;
}

A_field A_Field(A_pos pos, S_symbol name, S_symbol typ)
{
    A_field p = checked_malloc(sizeof(*p));
    p->pos=pos;
    p->name=name;
    p->typ=typ;
    // printf("%s", S_name(typ));
    if(p -> typ == S_Symbol("int") || p -> typ == S_Symbol("real"))
    {
        p->escape=FALSE;
    }
    else
    {
        p -> escape = TRUE;
    }
    return p;
}

A_fieldList A_FieldList(A_field head, A_fieldList tail)
{
    A_fieldList p = checked_malloc(sizeof(*p));
    p->head=head;
    p->tail=tail;
    return p;
}

A_expList A_ExpList(A_exp head, A_expList tail)
{
    A_expList p = checked_malloc(sizeof(*p));
    p->head=head;
    p->tail=tail;
    return p;
}

A_stmList A_StmList(A_stm head, A_stmList tail)
{
    A_stmList p = checked_malloc(sizeof(*p));
    p->head=head;
    p->tail=tail;
    return p;
}

A_fundec A_Fundec(A_pos pos, S_symbol name, A_fieldList params, S_symbol result, A_stm body)
{
    A_fundec p = checked_malloc(sizeof(*p));
    p->pos=pos;
    p->name=name;
    p->params=params;
    p->result=result;
    p->body=body;
    return p;
}

A_fundecList A_FundecList(A_fundec head, A_fundecList tail)
{
    A_fundecList p = checked_malloc(sizeof(*p));
    p->head=head;
    p->tail=tail;
    return p;
}

A_decList A_DecList(A_dec head, A_decList tail)
{
    A_decList p = checked_malloc(sizeof(*p));
    p->head=head;
    p->tail=tail;
    return p;
}

A_namety A_Namety(S_symbol name, A_ty ty)
{
    A_namety p = checked_malloc(sizeof(*p));
    p->name=name;
    p->ty=ty;
    return p;
}

A_nametyList A_NametyList(A_namety head, A_nametyList tail)
{
    A_nametyList p = checked_malloc(sizeof(*p));
    p->head=head;
    p->tail=tail;
    return p;
}

A_efield A_Efield(S_symbol name, A_exp exp)
{
    A_efield p = checked_malloc(sizeof(*p));
    p->name=name;
    p->exp=exp;
    return p;
}

A_efieldList A_EfieldList(A_efield head, A_efieldList tail)
{
    A_efieldList p = checked_malloc(sizeof(*p));
    p->head=head;
    p->tail=tail;
    return p;
}

