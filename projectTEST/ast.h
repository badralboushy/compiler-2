#pragma once

#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;
using namespace std; 






 
class Node; 
class Class_decl;
class Smallc_program;
class Func_program;
class Var_program;
class Class_decl_program;
class Constructor;
 
class Func;
 
class Array_func;
 
class Normal_func;
 
class Param_decl;
 
class Array_param_decl;
 
class Normal_param_decl;
 
class Param_decl_list;
 
class Compound_stmt; 
 
class Compound_stmts;
 
class Var_decl; 
 
class Var_decl_list; 
 
class Variable_id; 
 
class Id;
 
class Variable_assignment;
 
class Array_variable_assignment;
 
class Array_variable_id;
 
class Stmt; 
 
class Stmt_cond;
 
class Stmt_compound;
 
class Stmt_while;
 
class Stmt_assignstmt;
 
class Stmt_expr;
 
class Cond_stmt; 
 
class If_cond_stmt;
 
class Else_cond_stmt;
 
class While_stmt; 
 
class Assign_stmt; 
 
class Expr;
 
class Primary;
 
class Primary_num;
 
class Primary_float;
 
class Primary_char;
 
class Primary_string;
 
class Primary_id;
 
class Primary_false;
 
class Primary_true;
 
class Primary_null;
 
class TripleCondition;
 
class Exp_primary;
 
class Exp_triplecondition;
 
class Operator_expr; 
 
class Operator;
 
class Not_expr;
 
class  Parentheses_expr;
 
class Minus_expr;
 
class Func_call_expr;
 
class Array_expr;
 
class Expr_list;
 
class Primary_list;
 
class Type_specifier; 
 
class Visitor; 
 
class PrintVisitor; 



 
class Node
{
public:
	int line;
	int column;
	Node* father;
	Node(int, int);
};

 
 
class Class_decl : public Node {
public:
	string accmod; 
	Id* id; 
	Smallc_program* smallc_program; 
	Class_decl(int, int,string, Id*, Smallc_program*);
	virtual void accept(Visitor*);


};




 
 
class Smallc_program : public Node  //not sure 
{
public:
	Smallc_program(int, int);
	virtual void accept(Visitor*);
};

 
 
class Func_program : public Smallc_program {
public:

	Smallc_program* smallc_program;
	Func* func;
	Func_program(int, int, Smallc_program*, Func*);
	virtual void accept(Visitor*);
};

 
 
class Var_program : public Smallc_program {
public:
	Smallc_program* smallc_program;
	Var_decl* var_decl;
	Var_program(int, int, Smallc_program*, Var_decl*);
	virtual void accept(Visitor*);
};
 
 
class Func : public Node 
{
public:
	Func(int, int); 
virtual void accept(Visitor* ); 
};
 
 
class Array_func : public Func {
public:
	Type_specifier* type;
	Id* id;
	Param_decl_list* param_decl_list;
	Compound_stmt* compound_stmt;
	Array_func(int, int ,Type_specifier*, Id*, Param_decl_list*, Compound_stmt*);

virtual void accept(Visitor* ); 
};

 
 
class Normal_func : public Func {
public:
	Type_specifier* type;
	Id* id;
	Param_decl_list* param_decl_list;
	Compound_stmt* compound_stmt;
	Normal_func(int ,int ,Type_specifier*, Id*, Param_decl_list*, Compound_stmt*);

virtual void accept(Visitor* ); 
};
/// <summary> 
// badr 6/6
 
 
class Class_decl_program :public Smallc_program
{
public:
	Smallc_program* smallc_program; 
	Class_decl* class_decl; 
	Class_decl_program(int, int, Smallc_program*, Class_decl*);
virtual void accept(Visitor* ); 
};

 
 
class Constructor_program : public Smallc_program
{
public:
	Smallc_program* smallc_program; 
	Constructor* constructor; 
	Constructor_program(int, int, Smallc_program*, Constructor*);
virtual void accept(Visitor* ); 
};

 
 
class Constructor :public Node
{
public :
	Id* id; 
	Param_decl_list* param_decl_list; 
	Compound_stmt* compound_stmt; 
	Constructor(int, int,Id* ,Param_decl_list*, Compound_stmt*);
	virtual void accept(Visitor* ); 
};
/// </summaryp
 
 
class Param_decl : public Node { 
public :

	Param_decl(int, int); 

	virtual void accept(Visitor* ); 
};
 
 
class Normal_param_decl : public Param_decl {
public:
	Type_specifier* type;
	Id* id;
	Normal_param_decl(int, int, Type_specifier*, Id*);

	virtual void accept(Visitor* ); 
};
 
 
class Array_param_decl : public Param_decl { 
public:
	Type_specifier* type;
	Id* id;
	Array_param_decl(int, int,Type_specifier*, Id*);

	virtual void accept(Visitor* ); 
};

 
 
class Param_decl_list:public Node  {
public:
	vector<Param_decl* > *list; 
	Param_decl_list(int , int ); 
	Param_decl_list(int, int, Param_decl*); 
	void add_param(Param_decl*); 
	virtual void accept(Visitor* ); 
};

 
 
class Compound_stmt : public Node {
public:
	Compound_stmts* compound_stmts;
	Compound_stmt(int, int, Compound_stmts*);
	virtual void accept(Visitor* ); 
};
 
class Compound_stmts : public Node
{
public:
	vector <Stmt*> *stmt_list;
	vector < Var_decl*> *var_decl_list; 
	Compound_stmts(int, int);
	void add_var(Var_decl*);
	void add_stmt(Stmt*);

	virtual void accept(Visitor* ); 
};


/// </badr>

 
 
class Var_decl : public Node {
public:
	Type_specifier* type;
	Var_decl_list* var_decl_list;
	Var_decl(int, int,Type_specifier*, Var_decl_list*);

	virtual void accept(Visitor* ); 
};
 
 
class Var_decl_list :public Node {
public:
	vector<Variable_id*> *list;
	Var_decl_list(int, int);
	Var_decl_list(int, int, Variable_id*);
	void add_var(Variable_id*);
	virtual void accept(Visitor* ); 
};

 
 
class Variable_id : public Node {
public:

	Variable_id(int, int);

	virtual void accept(Visitor* ); 
};
 
 
class Id_variable : public Variable_id
{
public:

	Id* id;
	Id_variable(int, int, Id*);

virtual void accept(Visitor* ); 
};

 
 
class Id : public Node
{
public:

	string value;
	Id(int, int, string);

	virtual void accept(Visitor* ); 
};
 
 
class Variable_assignment : public Variable_id {
public:
	Id* id;
	Expr* expr;
	Variable_assignment(int, int, Id*, Expr*);
	virtual void accept(Visitor* ); 
};

 
 
class Array_variable_assignment : public Variable_id {
public:
	Id* id;
	Primary_list* primary_list;
	Array_variable_assignment(int, int, Id*, Primary_list*);
	virtual void accept(Visitor* ); 
};

 
 
class Array_variable_id: public Variable_id {
public:
	Id* id; 
	Array_variable_id(int, int, Id*);
	virtual void accept(Visitor* ); 
};

// 2/6/2021.

 
 
class Stmt : public Node
{
public:

	Stmt(int, int); 
	virtual void accept(Visitor* ); 
};

 
 
class Stmt_cond : public Stmt 
{
public:
	Cond_stmt* cond_stmt; 
	Stmt_cond(int, int , Cond_stmt*);

	virtual void accept(Visitor* ); 
};
 
 
class Stmt_compound: public Stmt
{
public:
	Compound_stmt* compound_stmt;
	Stmt_compound(int, int , Compound_stmt*);

	virtual void accept(Visitor* ); 
};

 
 
class Stmt_while : public Stmt
{
public:
	While_stmt* while_stmt ;
	Stmt_while(int, int , While_stmt* );

	virtual void accept(Visitor* ); 
};

 
 
class Stmt_assignstmt : public Stmt
{
public:
	Assign_stmt* assignment;
	Stmt_assignstmt(int, int, Assign_stmt*);

	virtual void accept(Visitor* ); 
};
 
 
class Stmt_expr : public Stmt
{
public:
	Expr* expr; 
	Stmt_expr(int, int, Expr*);
	virtual void accept(Visitor* ); 
};
 
 
class Break_stmt :public Stmt {
public :
	Break_stmt(int, int);
	virtual void accept(Visitor* ); 
};
 
 
class Continue_stmt : public Stmt {
public:
	Continue_stmt(int, int);
	virtual void accept(Visitor* ); 
};
 
 
class Cond_stmt :public Node {
public :
	Cond_stmt(int, int);
	virtual void accept(Visitor* ); 
};

 
class If_cond_stmt : public Cond_stmt {
public:
	Expr* expr;
	Stmt* ifstmt;
	If_cond_stmt(int, int, Expr*, Stmt*);
	virtual void accept(Visitor* ); 
};

 
class Else_cond_stmt : public Cond_stmt 
{
public:

	Expr* expr;
	Stmt* ifstmt;
	Stmt* elsestmt;
	Else_cond_stmt(int, int, Expr*, Stmt*, Stmt*);

	virtual void accept(Visitor* ); 
};

 
class While_stmt : public Stmt
{
public:

	Expr* expr; 
	Stmt* stmt; 
	While_stmt(int, int, Expr*, Stmt*); 

	virtual void accept(Visitor* ); 
};

 
class Assign_stmt :public Stmt
{
public:

	Id* id; 
	Expr* expr; 
	Assign_stmt(int, int, Id*, Expr*); 
	virtual void accept(Visitor* ); 
};

 
class Expr : public Node 
{
public:
	Expr(int, int); 
	virtual void accept(Visitor* ); 
};



 
class Primary : public Node
{
public:
	Primary(int, int); 

virtual void accept(Visitor* ); 
};
 
class Primary_num : public Primary
{
public:
	int value; 
	Primary_num(int, int, int);

	virtual void accept(Visitor* ); 
};
 
class Primary_float :public Primary
{
public :
	double value; 
	Primary_float(int, int, float); 
	virtual void accept(Visitor* ); 
};

 
class Primary_char :public Primary
{
public :

	char value; 
	Primary_char(int, int, char);
	virtual void accept(Visitor* ); 
};
 
class Primary_string : public Primary
{
public:
	string value; 
	Primary_string(int, int, string);
	virtual void accept(Visitor* ); 
};
 
class Primary_id : public Primary
{
public:
	Id* id; 
	Primary_id( int , int ,Id*);
	virtual void accept(Visitor* ); 
};
 
class Primary_false : public Primary
{
public:
	
	Primary_false(int, int);

	virtual void accept(Visitor* ); 
};
 
class Primary_true : public Primary
{
public:
	
	Primary_true(int, int); 


	virtual void accept(Visitor* ); 
};
 
class Primary_null : public Primary
{
public:
	
	Primary_null(int, int);

	virtual void accept(Visitor* ); 
};
 
class Exp_primary : public Expr
{
public :
	Primary* primary; 
	Exp_primary( int , int ,Primary* );
	virtual void accept(Visitor* ); 
};

 
class TripleCondition : public Node {
public :

	Expr* expr1;
	Expr* expr2;
	Expr* expr3;
	TripleCondition(int, int, Expr*, Expr*, Expr*);

	virtual void accept(Visitor* ); 
};
 
class Exp_triplecondition : public Expr
{
public :

	TripleCondition* triple_condition; 
	Exp_triplecondition(int, int, TripleCondition*); 

	virtual void accept(Visitor* ); 
};

 
class Operator_expr : public Expr {
public:
	Expr* expr_left;
	Expr* expr_right;
	Operator* op;
	Operator_expr(int, int, Operator*, Expr*, Expr*);
	virtual void accept(Visitor* ); 
};

 
class Operator :public Node {
public:

	int op_code;
	Operator(int, int, int);

	virtual void accept(Visitor* ); 
}; 

 
class Not_expr : public Expr {
public:
	Expr* expr;
	Not_expr(int, int, Expr*);
	virtual void accept(Visitor* ); 
};

 
class  Parentheses_expr : public Expr {
public:
	Expr* expr;
	Parentheses_expr(int, int, Expr*);
	virtual void accept(Visitor* ); 
};

 
class Minus_expr : public Expr {
public:

	Expr* expr;
	Minus_expr(int, int, Expr*);
	virtual void accept(Visitor* ); 
};

 
class Func_call_expr : public Expr {
public:

	Id* id;
	Expr_list* list;
	Func_call_expr(int, int, Id*, Expr_list*);
	virtual void accept(Visitor* ); 
};

 
class Array_expr : public Expr {
public:
	Id* id;
	Expr* expr;
	Array_expr(int, int, Id*, Expr*);

	virtual void accept(Visitor* ); 
};

 
class Expr_list : public Node {
public:
	vector<Expr* >* list;
	Expr_list(int, int);
	Expr_list(int, int, Expr*);
	void add_expr(Expr*);
	virtual void accept(Visitor* ); 
};

 
class Primary_list : public Node {
public:
	vector<Primary* >* list;
	Primary_list(int, int);
	Primary_list(int, int, Primary*);
	void add_primary(Primary*);
	virtual void accept(Visitor* ); 
};

 
class Type_specifier : public Node
{
public:
	int type; 
	Type_specifier(int, int, int);
	virtual void accept(Visitor* ); 
};


///////////// class visitor///////////
 
class Visitor
{
public:

	virtual void visit(Node* n) =0 ;
	virtual void visit(Class_decl* n) =0 ;
	virtual void visit( Smallc_program* n) =0 ;
	virtual void visit( Func_program* n) =0 ;
	virtual void visit( Var_program* n) =0 ;
	virtual void visit(Class_decl_program* n) =0 ;
	virtual void visit( Constructor* n) =0 ;
	virtual void visit( Func* n) =0 ;
	virtual void visit( Array_func* n) =0 ;
	virtual void visit( Normal_func* n) =0 ;
	virtual void visit( Param_decl* n) =0 ;
	virtual void visit( Array_param_decl* n) =0 ;
	virtual void visit( Normal_param_decl* n) =0 ;
	virtual void visit( Param_decl_list* n) =0 ;
	virtual void visit( Compound_stmt* n) =0 ;
	virtual void visit( Compound_stmts* n) =0 ;
	virtual void visit( Var_decl* n) =0 ;
	virtual void visit( Var_decl_list* n) =0 ;
	virtual void visit( Variable_id* n) =0 ;
	virtual void visit( Id* n) =0 ;
	virtual void visit( Variable_assignment* n) =0 ;
	virtual void visit( Array_variable_assignment* n) =0 ;
	virtual void visit( Array_variable_id* n) =0 ;
	virtual void visit( Stmt* n) =0 ;
	virtual void visit( Stmt_cond* n) =0 ;
	virtual void visit( Stmt_compound* n) =0 ;
	virtual void visit( Stmt_while* n) =0 ;
	virtual void visit( Stmt_assignstmt* n) =0 ;
	virtual void visit( Stmt_expr* n) =0 ;
	virtual void visit( Cond_stmt* n) =0 ;
	virtual void visit( If_cond_stmt* n) =0 ;
	virtual void visit( Else_cond_stmt* n) =0 ;
	virtual void visit( While_stmt* n) =0 ;
	virtual void visit( Assign_stmt* n) =0 ;
	virtual void visit( Expr* n) =0 ;
	virtual void visit( Primary* n) =0 ;
	virtual void visit( Primary_num* n) =0 ;
	virtual void visit( Primary_float* n) =0 ;
	virtual void visit( Primary_char* n) =0 ;
	virtual void visit( Primary_string* n) =0 ;
	virtual void visit( Primary_id* n) =0 ;
	virtual void visit( Primary_false* n) =0 ;
	virtual void visit( Primary_true* n) =0 ;
	virtual void visit( Primary_null* n) =0 ;
	virtual void visit( TripleCondition* n) =0 ;
	virtual void visit( Exp_primary* n) =0 ;
	virtual void visit( Exp_triplecondition* n) =0 ;
	virtual void visit( Operator_expr* n) =0 ;
	virtual void visit( Operator* n) =0 ;
	virtual void visit( Not_expr* n) =0 ;
	virtual void visit(  Parentheses_expr* n) =0 ;
	virtual void visit( Minus_expr* n) =0 ;
	virtual void visit( Func_call_expr* n) =0 ;
	virtual void visit( Array_expr* n) =0 ;
	virtual void visit( Expr_list* n) =0 ;
	virtual void visit( Primary_list* n) =0 ;
	virtual void visit( Type_specifier* n) =0 ;

};

/////////////printvisistor//////////

 
class PrintVisitor : public Visitor
{
public :
	virtual void visit(Node* n);
	virtual void visit(Class_decl* n);
	virtual void visit(Smallc_program* n);
	virtual void visit(Func_program* n);
	virtual void visit(Var_program* n);
	virtual void visit(Class_decl_program* n);
	virtual void visit(Constructor* n);
	virtual void visit(Func* n);
	virtual void visit(Array_func* n);
	virtual void visit(Normal_func* n);
	virtual void visit(Param_decl* n);
	virtual void visit(Array_param_decl* n);
	virtual void visit(Normal_param_decl* n);
	virtual void visit(Param_decl_list* n);
	virtual void visit(Compound_stmt* n);
	virtual void visit(Compound_stmts* n);
	virtual void visit(Var_decl* n);
	virtual void visit(Var_decl_list* n);
	virtual void visit(Variable_id* n);
	virtual void visit(Id* n);
	virtual void visit(Variable_assignment* n);
	virtual void visit(Array_variable_assignment* n);
	virtual void visit(Array_variable_id* n);
	virtual void visit(Stmt* n);
	virtual void visit(Stmt_cond* n);
	virtual void visit(Stmt_compound* n);
	virtual void visit(Stmt_while* n);
	virtual void visit(Stmt_assignstmt* n);
	virtual void visit(Stmt_expr* n);
	virtual void visit(Cond_stmt* n);
	virtual void visit(If_cond_stmt* n);
	virtual void visit(Else_cond_stmt* n);
	virtual void visit(While_stmt* n);
	virtual void visit(Assign_stmt* n);
	virtual void visit(Expr* n);
	virtual void visit(Primary* n);
	virtual void visit(Primary_num* n);
	virtual void visit(Primary_float* n);
	virtual void visit(Primary_char* n);
	virtual void visit(Primary_string* n);
	virtual void visit(Primary_id* n);
	virtual void visit(Primary_false* n);
	virtual void visit(Primary_true* n);
	virtual void visit(Primary_null* n);
	virtual void visit(TripleCondition* n);
	virtual void visit(Exp_primary* n);
	virtual void visit(Exp_triplecondition* n);
	virtual void visit(Operator_expr* n);
	virtual void visit(Operator* n);
	virtual void visit(Not_expr* n);
	virtual void visit(Parentheses_expr* n);
	virtual void visit(Minus_expr* n);
	virtual void visit(Func_call_expr* n);
	virtual void visit(Array_expr* n);
	virtual void visit(Expr_list* n);
	virtual void visit(Primary_list* n);
	virtual void visit(Type_specifier* n);
};


