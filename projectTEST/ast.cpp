#include "ast.h"


Node::Node(int line, int column)
{
	this->line = line;
	this->column = column;
	this->father = NULL;
}



Class_decl::Class_decl(int line ,int column ,string accmod,  Id* id, Smallc_program* smallc_program  ) : Node(line, column)
{
		this->id = id;
		this->smallc_program = smallc_program;
		this->accmod = accmod;
		id->father = this;
		smallc_program->father = this;
}

Smallc_program::Smallc_program(int line, int column) :Node(line, column) 
{

}

Func_program::Func_program(int line, int column, Smallc_program* s, Func* f) : Smallc_program(line, column) {
	this->smallc_program = s;
	this->func = f;
	if (func != NULL)this->func->father = this;
	if (this->smallc_program != NULL)	this->smallc_program = this;
}

Var_program::Var_program(int line, int column, Smallc_program* s, Var_decl* v) : Smallc_program(line, column) {
	this->smallc_program = s;
	this->var_decl = v;
	if (var_decl != NULL) this->var_decl->father = this;
	if (this->smallc_program != NULL)	this->smallc_program = this;
}



Func::Func(int line, int column) :Node(line, column ) 
{
	
}
Array_func::Array_func(int line, int column ,Type_specifier* tb, Id* id, Param_decl_list* p, Compound_stmt* c) : Func(line, column) {
	this->type = tb; 
	this->id = id;
	this->param_decl_list = p;
	this->compound_stmt = c;

	this->type->father = this; 
	id->father = this;
	if (param_decl_list != NULL)
		param_decl_list->father = this;

	if (compound_stmt != NULL)
		compound_stmt->father = this;
}

Normal_func::Normal_func(int line, int column,Type_specifier* ts, Id* id, Param_decl_list* p, Compound_stmt* c) : Func(line, column) {
	this->type = ts;
	this->id = id;
	this->param_decl_list = p;
	this->compound_stmt = c;

	id->father = this;
	if (param_decl_list != NULL)
		param_decl_list->father = this;

	if (compound_stmt != NULL)
		compound_stmt->father = this;
	this->type->father = this; 
}
Param_decl::Param_decl(int line, int column) :Node(line, column) {
	
}
Normal_param_decl::Normal_param_decl(int line, int column,Type_specifier* tb, Id* id): Param_decl(line, column) {
	this->type = tb;
	this->id = id;
	if (id != NULL) id->father = this;
	this->type->father = this; 
}
Array_param_decl::Array_param_decl(int line, int column, Type_specifier* tb, Id* id) : Param_decl(line, column) {
	this->type = tb; 
	this->id = id;
	if (id != NULL) id->father = this;
	this->type->father = this; 
}
Param_decl_list::Param_decl_list(int line , int column):Node(line,column)
{
	this->list = new vector<Param_decl*>(); 

}
void Param_decl_list::add_param(Param_decl* p) {
	this->list->push_back(p); 
	p->father = this; 

}
Param_decl_list::Param_decl_list(int line, int column, Param_decl* p) : Node(line, column)
{	
	this->list = new vector <Param_decl*>();				// not sure;


	this->list->push_back(p); 

}

Compound_stmt::Compound_stmt(int line, int column, Compound_stmts* c) : Node(line, column) {
	this->compound_stmts = c;
	this->compound_stmts->father = this;
}
Compound_stmts::Compound_stmts(int line, int column) : Node(line, column) {
	this->stmt_list = new vector <Stmt*>(); 
	this->var_decl_list = new vector <Var_decl*>();

}

void Compound_stmts::add_stmt(Stmt* s) {
	this->stmt_list->push_back(s);
}
void Compound_stmts::add_var(Var_decl* v)
{
	this->var_decl_list->push_back(v);
}


Var_decl::Var_decl(int line, int column, Type_specifier* tb, Var_decl_list* v) : Node(line, column) {
	this->type = tb;
	this->var_decl_list = v;
	this->var_decl_list->father = this;
	this->type->father = this; 

}

Var_decl_list::Var_decl_list(int line, int column) :Node(line, column)
{
	this->list = new vector<Variable_id*>();

}
void Var_decl_list::add_var(Variable_id* v) {
	this->list->push_back(v);
}
Var_decl_list::Var_decl_list(int line, int column, Variable_id* v) : Node(line, column)
{
	this->list = new vector<Variable_id* >();
	this->list->push_back(v);

}
Variable_id::Variable_id(int line, int column) : Node(line, column) {
	
}



Id::Id(int line, int column, string s) : Node(line, column)
{
	this->value = s;

}


Id_variable::Id_variable(int line, int column, Id* id) : Variable_id(line, column)
{
	this->id = id;
	this->id->father = this;

}


Variable_assignment::Variable_assignment(int line, int column, Id* id, Expr* expr) : Variable_id(line, column) {
	this->id = id;
	this->expr = expr;
	if (id != NULL) this->id->father = this;
	if (expr != NULL) this->expr->father = this;
}

Array_variable_assignment::Array_variable_assignment(int line, int column, Id* id, Primary_list* p ) :Variable_id(line, column) {
	this->id = id;
	this->primary_list = p;
	if (id != NULL) this->id->father = this;
	if (p != NULL) this->primary_list->father = this;
}

Array_variable_id::Array_variable_id(int line, int column, Id* i) : Variable_id(line, column)
{
	this->id = i; 
	this->id->father= this; 
}
Stmt::Stmt(int line, int column) : Node(line, column)
{

};



If_cond_stmt::If_cond_stmt(int line, int column, Expr* expr, Stmt* ifs) : Cond_stmt(line, column) {
	this->expr = expr;
	this->ifstmt = ifs;
	this->expr->father = this;
	this->ifstmt->father = this;
}

Else_cond_stmt::Else_cond_stmt(int line, int column, Expr* expr, Stmt* ifs, Stmt* els) : Cond_stmt(line, column)
{
	this->expr = expr;
	this->ifstmt = ifs;
	this->elsestmt = els;
	this->expr->father = this;
	this->ifstmt->father = this;
	this->elsestmt->father = this;
}

While_stmt::While_stmt(int line, int column, Expr* e , Stmt* s):Stmt(line,column)
{
	this->expr = e; 
	this->stmt = s; 	
	this->expr->father = this; 
	this->stmt->father = this; 
}

Assign_stmt::Assign_stmt(int line, int column, Id* id, Expr* expr ) : Stmt(line, column)
{
	this->id = id; 
	this->expr = expr; 
	this->id->father = this; 
	this->expr->father = this; 
}
Break_stmt::Break_stmt(int line, int column) : Stmt(line, column) {

}



Continue_stmt::Continue_stmt(int line, int column) : Stmt(line, column) {

}

Expr::Expr(int line, int column) : Node(line, column)
{

}


TripleCondition::TripleCondition(int line, int column, Expr* e1, Expr* e2, Expr* e3) : Node(line, column) {
	this->expr1 = e1;
	this->expr2 = e2;
	this->expr3 = e3;
	this->expr1->father = this;
	this->expr2->father = this;
	this->expr3->father = this;
}



Operator_expr::Operator_expr(int line, int column, Operator* o, Expr* left, Expr* right) : Expr(line, column) {
	this->op = o;
	this->expr_left = left;
	this->expr_right = right;
	this->expr_left->father = this;
	this->expr_right->father = this;
	this->op->father = this; 
}



Not_expr::Not_expr(int line, int column, Expr* e) : Expr(line, column) {
	this->expr = e;
	this->expr->father = this;

}



Parentheses_expr::Parentheses_expr(int line, int column, Expr* e) : Expr(line, column) {
	this->expr = e;
	this->expr->father = this;

}


Minus_expr::Minus_expr(int line, int column, Expr* e) : Expr(line, column) {
	this->expr = e;
	this->expr->father = this;

}



Func_call_expr::Func_call_expr(int line, int column, Id* id, Expr_list* e) : Expr(line, column) {
	this->id = id;
	this->list = e;
	this->id->father = this;
	this->list->father = this;
}



Array_expr::Array_expr(int line, int column, Id* id, Expr* e) : Expr(line, column) {
	this->id = id;
	this->expr = e;
	this->id->father = this;
	this->expr->father = this;
}



Expr_list::Expr_list(int line, int column) :Node(line, column)
{
	this->list = new vector<Expr*>();

}
void Expr_list::add_expr(Expr* e) {
	this->list->push_back(e);
	e->father = this;

}

Expr_list::Expr_list(int line, int column, Expr* e) : Node(line, column)
{

	this->list->push_back(e);

}

Primary_list::Primary_list(int line, int column) :Node(line, column)
{
	this->list = new vector<Primary*>();

}
void Primary_list::add_primary(Primary* p) {
	this->list->push_back(p);
	p->father = this;

}

Primary_list::Primary_list(int line, int column, Primary* p) : Node(line, column)
{

	this->list->push_back(p);

}


/////// badr 6/6
Class_decl_program::Class_decl_program(int line, int column, Smallc_program* sm, Class_decl* cl) :Smallc_program(line, column)
{
	this->smallc_program = sm; 
	this->class_decl = cl; 
	this->smallc_program->father = this; 
	this->class_decl->father = this; 

}

Constructor::Constructor(int line, int column, Id* i, Param_decl_list* pd, Compound_stmt* cs) : Node(line, column)
{
	this->id = i; 
	this->param_decl_list = pd;
	this->compound_stmt = cs; 
	param_decl_list->father = this;
	compound_stmt->father = this; 
	this->id->father = this;
}

Exp_primary::Exp_primary(int line, int column ,Primary* primary):Expr(line, column )
{
	this->primary = primary; 
	this->primary->father = this; 
}


Exp_triplecondition::Exp_triplecondition(int line, int coloumn, TripleCondition* t) : Expr(line,column)
{
	this->triple_condition = t; 
	this->triple_condition->father = this; 
}





Operator::Operator(int line, int column, int op):Node(line,column)
{
	this->op_code = op; 
}



Primary::Primary(int line , int column):Node(line,column)
{
}

Primary_null::Primary_null(int line, int column) : Primary(line,column)
{

}



Primary_true::Primary_true(int line, int column) : Primary(line,column)
{
	
}

void
Primary_true::accept(Visitor* v)
{
	v->visit(this);
}

Primary_false::Primary_false(int line, int column):Primary(line,column)
{
	
}


Primary_id::Primary_id(int line, int column, Id* id) : Primary ( line ,column)
{
	this->id = id; 
}



Primary_char::Primary_char(int line, int column, char c) : Primary ( line ,column)
{
	this->value = c; 
}



Primary_float::Primary_float(int line, int column, float f):Primary (line,column)
{
	this->value = f; 
}

Primary_num::Primary_num(int line, int column, int n) : Primary ( line ,column )
{
	this->value = n;
}

Stmt_expr::Stmt_expr(int line, int column, Expr* e): Stmt(line,column)
{
	this->expr = e; 
}

Stmt_assignstmt::Stmt_assignstmt(int line, int column, Assign_stmt* a) : Stmt(line,column)
{
	this->assignment = a; 
}

Stmt_while::Stmt_while(int line, int column ,While_stmt* wstmt) : Stmt(line,column)
{
	this->while_stmt = wstmt; 
}

Stmt_compound::Stmt_compound(int line, int column, Compound_stmt* cs):Stmt(line,column)
{
	this->compound_stmt = cs; 
}

Stmt_cond::Stmt_cond(int line, int column, Cond_stmt* cs):Stmt(line,column)
{
	this->cond_stmt = cs;
}

Cond_stmt::Cond_stmt(int line, int column) : Node(line,column)
{
}

Constructor_program::Constructor_program(int Line, int Column, Smallc_program* s, Constructor* c):Smallc_program(Line, Column)
{
	smallc_program = s; 
	constructor = c; 
	this->smallc_program->father = this; 
	this->constructor->father = this; 


}



Type_specifier::Type_specifier(int line , int column, int t) : Node(line,column)
{
	type = t; 
}



Primary_string::Primary_string(int line, int column, string ss):Primary(line, column)
{
	value = ss; 
}



////////////////////accept function//////////////

void
Primary_string::accept(Visitor* v)
{
	v->visit(this);
}
void
TripleCondition::accept(Visitor* v)
{
	v->visit(this);
}
void
Constructor_program::accept(Visitor* v)
{
	v->visit(this);
}

void Id_variable::accept(Visitor* v)
{
	v->visit(this);
}

void Class_decl::accept(Visitor* v)
{
	v->visit(this);
};
void
Primary_list::accept(Visitor* v)
{
	v->visit(this);
}
void
Parentheses_expr::accept(Visitor* v)
{
	v->visit(this);
}


void
Primary_false::accept(Visitor* v)
{
	v->visit(this);
}

void
Exp_triplecondition::accept(Visitor* v)
{
	v->visit(this);
};

void
Smallc_program::accept(Visitor* v)
{
	v->visit(this);
};

void
Minus_expr::accept(Visitor* v)
{
	v->visit(this);
};
void
Expr_list::accept(Visitor* v)
{
	v->visit(this);
}

void
Func_program::accept(Visitor* v)
{
	v->visit(this);
};

void
Var_program::accept(Visitor* v)
{
	v->visit(this);
};

void Class_decl_program::accept(Visitor* v)
{
	v->visit(this);
};

void
Array_expr::accept(Visitor* v)
{
	v->visit(this);
}
void
Func_call_expr::accept(Visitor* v)
{
	v->visit(this);
}
void
Primary_null::accept(Visitor* v)
{
	v->visit(this);
}

void
Constructor::accept(Visitor* v)
{
	v->visit(this);
};

void
Func::accept(Visitor* v)
{
	v->visit(this);
};

void
Type_specifier::accept(Visitor* v)
{
	v->visit(this);
}

void
Array_func::accept(Visitor* v)
{
	v->visit(this);
};

void
Normal_func::accept(Visitor* v)
{
	v->visit(this);
};

void
Param_decl::accept(Visitor* v)
{
	v->visit(this);
};

void
Array_param_decl::accept(Visitor* v)
{
	v->visit(this);
};

void
Normal_param_decl::accept(Visitor* v)
{
	v->visit(this);
};

void
Param_decl_list::accept(Visitor* v)
{
	v->visit(this);
};

void
Compound_stmt::accept(Visitor* v)
{
	v->visit(this);
};

void
Compound_stmts::accept(Visitor* v)
{
	v->visit(this);
};

void
Primary_char::accept(Visitor* v)
{
	v->visit(this);
}

void
Continue_stmt::accept(Visitor* v)
{
	v->visit(this);
}
void
Var_decl::accept(Visitor* v)
{
	v->visit(this);
};

void
Var_decl_list::accept(Visitor* v)
{
	v->visit(this);
};

void
Not_expr::accept(Visitor* v)
{
	v->visit(this);
}
void
Variable_id::accept(Visitor* v)
{
	v->visit(this);
};

void
Id::accept(Visitor* v)
{
	v->visit(this);
};

void
Variable_assignment::accept(Visitor* v)
{
	v->visit(this);
};

void
Array_variable_assignment::accept(Visitor* v)
{
	v->visit(this);
};

void
Exp_primary::accept(Visitor* v)
{
	v->visit(this);
}
void
Array_variable_id::accept(Visitor* v)
{
	v->visit(this);
};
void
Primary_id::accept(Visitor* v)
{
	v->visit(this);
}

void
Stmt::accept(Visitor* v)
{
	v->visit(this);
};

void
Stmt_cond::accept(Visitor* v)
{
	v->visit(this);
};

void
Stmt_compound::accept(Visitor* v)
{
	v->visit(this);
};

void
Stmt_while::accept(Visitor* v)
{
	v->visit(this);
};

void
Stmt_assignstmt::accept(Visitor* v)
{
	v->visit(this);
};

void
Break_stmt::accept(Visitor* v)
{
	v->visit(this);
}

void
Stmt_expr::accept(Visitor* v)
{
	v->visit(this);
};

void
Cond_stmt::accept(Visitor* v)
{
	v->visit(this);
};

void
If_cond_stmt::accept(Visitor* v)
{
	v->visit(this);
};

void
Else_cond_stmt::accept(Visitor* v)
{
	v->visit(this);
};

void
While_stmt::accept(Visitor* v)
{
	v->visit(this);
};

void
Assign_stmt::accept(Visitor* v)
{
	v->visit(this);
};

void
Expr::accept(Visitor* v)
{
	v->visit(this);
};

void
Primary::accept(Visitor* v)
{
	v->visit(this);
};

void
Primary_num::accept(Visitor* v)
{
	v->visit(this);
};

void
Primary_float::accept(Visitor* v)
{
	v->visit(this);
};

void
Operator_expr::accept(Visitor* v)
{
	v->visit(this);
}

void
Operator::accept(Visitor* v)
{
	v->visit(this);
}


///////////////////////////// visit function in printvisitor class ////////////////

void
PrintVisitor::visit(Node* n)
{

};


void
PrintVisitor::visit( Class_decl* n )
{
	cout << "this is " << n->accmod<<" class declaration, class name is " << n->id->value << endl; 
	n->id->accept(this);
	n->smallc_program->accept(this);
	
};


void
PrintVisitor::visit( Smallc_program* n )
{
	cout << "this is function or class member declaration" << endl;
	
	

};


void
PrintVisitor::visit( Func_program* n )
{
	cout << " this is func_program declaration " << endl;
	n->func->accept(this);
};


void
PrintVisitor::visit( Var_program* n )
{
	cout << "this is variable declaration" << endl;
	n->var_decl->accept(this);

};


void
PrintVisitor::visit( Class_decl_program* n )
{
	cout << "this is inner class declaration " << endl;
	n->class_decl->accept(this);

};

void
PrintVisitor::visit( Constructor* n )
{
	cout << "this is constructor declaration"; 
	n->id->accept(this);
	n->param_decl_list->accept(this);
	n->compound_stmt->accept(this);
};

void
PrintVisitor::visit( Func* n )
{
	cout << "function declaration " << endl;
};

void
PrintVisitor::visit( Array_func* n )
{
	cout << "declaring function returns array " << endl;
	n->compound_stmt->accept(this);
	n->id->accept(this);
	n->param_decl_list->accept(this);

};

void
PrintVisitor::visit( Normal_func* n )
{
	cout << "declaring function with "<<n->type->type<< " return type " << endl;
	n->id->accept(this);
	n->param_decl_list->accept(this);
	n->compound_stmt->accept(this);
	
};

void
PrintVisitor::visit( Param_decl* n )
{
	cout << "declaring Param_decl " << endl;
	

};

void
PrintVisitor::visit( Array_param_decl* n )
{
	cout << "declaring Array_param_decl with type "<<n->type->type << endl;
	n->id->accept(this);
	
};

void
PrintVisitor::visit( Normal_param_decl* n )
{
	cout << "declaring Normal_param_decl with type "<<n->type->type << endl;
	n->id->accept(this);

};

void
PrintVisitor::visit( Param_decl_list* n )
{
	cout << "declaring Param_decl_list with size "<<n->list->size() << endl;
	
	for (int i = 0; i < n->list->size(); i++)
	{
		n->list->at(i)->accept(this);
	}

};

void
PrintVisitor::visit( Compound_stmt* n )
{
	cout << "declaring Compound_stmt" << endl;
	n->compound_stmts->accept(this);

};

void
PrintVisitor::visit( Compound_stmts* n )
{
	cout << "declaring Compound_stmts with size of "<<n->stmt_list->size() << endl;
	cout << "and variable_stmts number is " << n->var_decl_list->size() << endl;
	
	for (int i = 0; i < n->stmt_list->size(); i++)
	{
		n->stmt_list->at(i)->accept(this);
	}
	for (int i = 0; i < n->var_decl_list->size(); i++)
	{
		n->var_decl_list->at(i)->accept(this);
	}
	


};

void
PrintVisitor::visit( Var_decl* n )
{
	cout << "declaring Var_decl with type is "<<n->type->type << endl;
	n->var_decl_list->accept(this);
	
};

void
PrintVisitor::visit( Var_decl_list* n )
{
	 cout<<"declaring Var_decl_list with size of "<<n->list->size()<<" of variables" <<endl;
	 
	 for (int i = 0; i < n->list->size(); i++)
	 {
		 n->list->at(i)->accept(this);
	 }


};

void
PrintVisitor::visit( Variable_id* n )
{
	 cout<<"declaring Variable_id" <<endl;
	 

};

void
PrintVisitor::visit( Id* n )
{
	 cout<<"declaring Id with name is : "<<n->value <<endl;
	 
};

void
PrintVisitor::visit( Variable_assignment* n )
{
	 cout<<"declaring Variable_assignment" <<endl;
	 n->id->accept(this);
	 n->expr->accept(this);
};

void
PrintVisitor::visit( Array_variable_assignment* n )
{
	 cout<<"declaring Array_variable_assignment" <<endl;
	 n->id->accept(this);
	 n->primary_list->accept(this);

};

void
PrintVisitor::visit( Array_variable_id* n )
{
	 cout<<"declaring Array_variable_id" <<endl;
	 n->id->accept(this);

};

void
PrintVisitor::visit( Stmt* n )
{
	 cout<<"declaring Stmt" <<endl;
	 

};

void
PrintVisitor::visit( Stmt_cond* n )
{
	 cout<<"declaring Stmt_cond" <<endl;
	 n->cond_stmt->accept(this);

};

void
PrintVisitor::visit( Stmt_compound* n )
{
	 cout<<"declaring Stmt_compound" <<endl;
	 n->compound_stmt->accept(this);
	

};

void
PrintVisitor::visit( Stmt_while* n )
{
	 cout<<"declaring Stmt_while" <<endl;
	 n->while_stmt->accept(this);

};

void
PrintVisitor::visit( Stmt_assignstmt* n )
{
	 cout<<"declaring Stmt_assignstmt" <<endl;
	 n->assignment->accept(this);

};

void
PrintVisitor::visit( Stmt_expr* n )
{
	 cout<<"declaring Stmt_expr" <<endl;
	 n->expr->accept(this);
	 

};

void
PrintVisitor::visit( Cond_stmt* n )
{
	 cout<<"declaring Cond_stmt" <<endl;
	

};

void
PrintVisitor::visit( If_cond_stmt* n )
{
	 cout<<"declaring If_cond_stmt" <<endl;
	 n->expr->accept(this);
	 n->ifstmt->accept(this);
	

};

void
PrintVisitor::visit( Else_cond_stmt* n )
{
	 cout<<"declaring Else_cond_stmt" <<endl;
	 n->expr->accept(this);
	 n->ifstmt->accept(this);
	 n->elsestmt->accept(this);
	

};

void
PrintVisitor::visit( While_stmt* n )
{
	 cout<<"declaring While_stmt" <<endl;
	 n->expr->accept(this);
	 n->stmt->accept(this);


};

void
PrintVisitor::visit( Assign_stmt* n )
{
	 cout<<"declaring Assign_stmt" <<endl;
	 n->expr->accept(this);
	 n->id->accept(this);

};

void
PrintVisitor::visit( Expr* n )
{
	 cout<<"declaring Expr" <<endl;
	 

};

void
PrintVisitor::visit( Primary* n )
{
	 cout<<"declaring Primary" <<endl;
	 

};

void
PrintVisitor::visit( Primary_num* n )
{
	 cout<<"declaring Primary_num with value of "<<n->value <<endl;

};

void
PrintVisitor::visit (Primary_float* n )
{
	 cout<<"declaring Primary_float with value of "<<n->value <<endl;


};

void
PrintVisitor::visit (Primary_char* n )
{
	 cout<<"declaring Primary_char with value of " << n->value<<endl;


};

void
PrintVisitor::visit( Primary_string* n )
{
	 cout<<"declaring Primary_string with value of " << n->value <<endl;


};

void
PrintVisitor::visit( Primary_id* n )
{
	 cout<<"declaring Primary_id " <<endl;
	 n->id->accept(this);


};

void
PrintVisitor::visit( Primary_false* n )
{
	 cout<<"declaring Primary_false"<<endl;


};

void
PrintVisitor::visit( Primary_true* n )
{
	 cout<<"declaring Primary_true" <<endl;
	 

};

void
PrintVisitor::visit( Primary_null* n )
{
	 cout<<"declaring Primary_null" <<endl;

	 
};

void
PrintVisitor::visit( TripleCondition* n )
{
	 cout<<"declaring TripleCondition" <<endl;
	 n->expr1->accept(this);
	 n->expr2->accept(this);
	 n->expr3->accept(this);
	
};

void
PrintVisitor::visit( Exp_primary* n )
{
	 cout<<"declaring Exp_primary" <<endl;
	 n->primary->accept(this);

};

void
PrintVisitor::visit( Exp_triplecondition* n )
{
	 cout<<"declaring Exp_triplecondition" <<endl;
	 n->triple_condition->accept(this);


};

void
PrintVisitor::visit( Operator_expr* n )
{
	 cout<<"declaring Operator_expr" <<endl;
	 n->expr_left->accept(this);
	 n->expr_right->accept(this);
	 n->op->accept(this);
	 
};

void
PrintVisitor::visit( Operator* n )
{
	 cout<<"declaring Operator with code "<<n->op_code <<endl;
	 

};

void
PrintVisitor::visit( Not_expr* n )
{
	 cout<<"declaring Not_expr" <<endl;
	 n->expr->accept(this);
	

};

void
PrintVisitor::visit(  Parentheses_expr* n )
{
	 cout<<"declaring Parentheses_expr" <<endl;
	 n->expr->accept(this);
	 

};

void
PrintVisitor::visit( Minus_expr* n )
{
	 cout<<"declaring Minus_expr" <<endl;
	 n->expr->accept(this);
	 

};

void
PrintVisitor::visit( Func_call_expr* n )
{
	 cout<<"declaring Func_call_expr" <<endl;
	 n->id->accept(this);
	 n->list->accept(this);
	

};

void
PrintVisitor::visit( Array_expr* n )
{
	 cout<<"declaring Array_expr" <<endl;
	 n->expr->accept(this);
	 n->id->accept(this);
	 

};

void
PrintVisitor::visit( Expr_list* n )
{
	 cout<<"declaring Expr_list with size of "<<n->list->size()<<" expr " <<endl;
	 
	 for (int i = 0; i < n->list->size(); i++)
	 {
		 n->list->at(i)->accept(this);
	 }

};

void
PrintVisitor::visit( Primary_list* n )
{
	 cout<<"declaring Primary_list with size of "<<n->list->size()<<" primaries" <<endl;
	 
	 for (int i = 0; i < n->list->size(); i++)
	 {
		 n->list->at(i)->accept(this);
	 }

};

void
PrintVisitor::visit( Type_specifier* n )
{
	 cout<<"declaring Type_specifier with code "<<n->type <<endl;
	 

};

//void  Primary_char;
//void  Primary_string;
//void  Primary_id;
//void  Primary_false;
//void  Primary_true;
//void  Primary_null;
//void  TripleCondition;
//void  Exp_primary;
//void  Exp_triplecondition;
//void  Operator_expr;
//void  Operator;
//void  Not_expr;
//void   Parentheses_expr;
//void  Minus_expr;
//void  Func_call_expr;
//void  Array_expr;
//void  Expr_list;
//void  Primary_list;
//void  Type_specifier;
//void  Visitor;
//void  PrintVisitor;