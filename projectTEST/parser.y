%{
	#include "ast.h"

	#include <iostream>
	using std::cout;
	using std::endl;

	#include <string>
	using std::string;
			extern int yylex() ; 
			extern int getLine() ; 
			extern int getColumn(); 
			int yyerror(const char* s1) ;
			extern int yydebug;
			bool flage = false ;
			Class_decl* root ; 

%}

%union{

 Class_decl *tClass_decl;
 Smallc_program *tSmall_program;
 Constructor   *tConstructor;
 Func* tFunc;
 Param_decl* tParam_decl;
 Param_decl_list* tParam_decl_list;
 Compound_stmt* tCompound_stmt; 
 Compound_stmts* tCompound_stmts;
 Var_decl* tVar_decl; 
 Var_decl_list* tVar_decl_list; 
 Variable_id* tVariable_id; 
 Stmt* tStmt; 
 Cond_stmt* tCond_stmt; 
 While_stmt* tWhile_stmt; 
 Assign_stmt* tAssign_stmt; 
 Expr* tExpr;
 Primary* tPrimary;
 TripleCondition* tTripleCondition; 
 Operator* tOperator;
 Expr_list* tExpr_list;
 Primary_list* tPrimary_list;
 Id* tId;
 Primary_num  *tPrimary_num;
 Primary_float* tPrimary_float;
 Primary_char* tPrimary_char;
 Primary_string* tPrimary_string;
 char* taccmod ; 
 int* tint ; 
 Type_specifier * ttype_specifier ; 

}

 %type <tClass_decl> class_decl
 %type <tSmall_program> smallc_program
 %type <tConstructor> constructor
 %type <tFunc> func
 %type <tParam_decl> param_decl
 %type <tParam_decl_list> param_decl_list
 %type <tCompound_stmt> compound_stmt
 %type <tCompound_stmts> compound_stmts
 %type <tVar_decl> var_decl
 %type <tVar_decl_list> var_decl_list 
 %type <tVariable_id> variable_id
 %type <tStmt> stmt
 %type <tCond_stmt> cond_stmt
 %type <tWhile_stmt> while_stmt 
 %type <tAssign_stmt> assignstmt 
 %type <tExpr> expr
 %type <tPrimary> primary
 %type <tTripleCondition> triplecondition 
 %type <tOperator> operator
 %type <tExpr_list> expr_list
 %type <tPrimary_list> primary_list
 %type <tPrimary_float> FLOATNUM
 %type <tPrimary_char> CHARCONST
 %type <tPrimary_string> STRINGCONST
 %type <ttype_specifier> type_specifier

%token <tId> ID
%token <tPrimary_num> INTNUM
%token <taccmod> ACCMOD
%token INT FLOAT CHAR STRING BOOL RETURN BREAK CONTINUE WHILE IF ELSE 
%token FLOATNUM CHARCONST STRINGCONST TRUE FALSE NUL IS_EQUAL SPACECOM CLASS
%nonassoc IF_PREC 
%nonassoc ELSE
%nonassoc ID
%nonassoc '<' '>' '&&' '||' IS_EQUAL
%right '!'


%right '=' 
%left '+' '-'
%left '*' '/' 

%right '('
%left  ')'
%nonassoc OP
%right ':'
%left '?' 

%%

class_decl: ACCMOD CLASS ID '{'smallc_program'}'
					{
						$$ = new Class_decl(getLine(),getColumn(),$1,$3,$5 );
						root = $$ 

					
					}
			|CLASS ID '{' smallc_program '}'
					{
					$$ = new Class_decl(getLine(), getColumn(),"private" ,$2, $4) ; 
					root = $$ ; 
					}
;

smallc_program: 
					{
					// i don't know what to do here ......................
					}
				|smallc_program func 
					{
					$$ = new Func_program(getLine(),getColumn(),$1 ,$2);
					}

				|smallc_program var_decl
					{
					$$ = new Var_program(getLine(),getColumn(),$1,$2); 
					
					}
				|smallc_program class_decl
					{
						$$ = new Class_decl_program(getLine(),getColumn(),$1,$2);
					}
				|smallc_program constructor
					{
					$$ = new Constructor_program(getLine() , getColumn(), $1, $2);
					}

; 


constructor: ID '(' param_decl_list ')' compound_stmt
					{
					$$ = new Constructor (getLine(),getColumn(),$1 , $3, $5);
					}
			
;


func: type_specifier ID '(' param_decl_list ')' compound_stmt
			{
			$$= new Normal_func(getLine(),getColumn(),$1,$2,$4,$6);
			}
	|type_specifier '['']' ID '(' param_decl_list ')' compound_stmt
			{
			$$ = new Array_func(getLine(),getColumn(), $1, $4 ,$6 , $8);
			}
;
type_specifier: INT
					{
						$$ = new Type_specifier(getLine(),getColumn(),1) ; 
					}
				|FLOAT
					{
						$$ = new Type_specifier(getLine(),getColumn(),2) ; 
					}
				|CHAR
					{
						$$ = new Type_specifier(getLine(),getColumn(),3) ; 

					}
				|STRING
					{
						$$ = new Type_specifier(getLine(),getColumn(),4) ; 
					}
				|BOOL
					{
						$$ = new Type_specifier(getLine(),getColumn(),5) ; 
					}
;

param_decl_list:
			{
				$$ = new Param_decl_list(getLine(),getColumn());
			}
				|param_decl
			{
				$$ = new Param_decl_list(getLine(),getColumn(),$1);
			}
				|param_decl_list ',' param_decl 
			{
				$1->add_param($3);
				$$ = $1 ; 
			
			}
;
param_decl:		type_specifier ID
			{
				$$ = new Normal_param_decl(getLine(),getColumn(),$1,$2);
			}
				|type_specifier ID '['']' 
			{
				$$ = new Array_param_decl(getLine(),getColumn(),$1,$2);
			}
;

compound_stmt:'{' compound_stmts '}'
					{
						$$ = new Compound_stmt(getLine(),getColumn(),$2);
					}
;
compound_stmts:  
					{
						$$ = new Compound_stmts(getLine(),getColumn());
					}
				|compound_stmts var_decl
					{
						if ( $1 == NULL) $1 = new Compound_stmts(getLine(),getColumn());
						$1->add_var($2);
						$$ = $1 ; 
					}
				|compound_stmts stmt
					{
						if ($1 == NULL) new Compound_stmts(getLine(),getColumn());
						$1->add_stmt($2);
						$$ = $1 ; 
					}
;
var_decl: type_specifier var_decl_list ';'	
					{
						$$ = new Var_decl(getLine(),getColumn(),$1,$2);
					}
;
var_decl_list:	variable_id	
					{
						$$ = new Var_decl_list(getLine(),getColumn(), $1);
					}
				|var_decl_list ',' variable_id
					{
						$1->add_var($3);
						$$ = $1 ; 
					}
; 
variable_id:	ID
					{
						$$  = new Id_variable(getLine(),getColumn(),$1) ; 
					}
				|ID '=' expr
					{
						$$ = new Variable_assignment(getLine(),getColumn(),$1,$3);
					}
				|ID '['']' '=' '{' primary_list '}'
					{
						$$ = new Array_variable_assignment(getLine(),getColumn(),$1,$6);
					}
				|ID '['']'
					{
						$$ = new Array_variable_id(getLine(),getColumn(),$1);
					}
; 




stmt: compound_stmt
					{
						$$ = new Stmt_compound(getLine(),getColumn(),$1);
					
					}
		|cond_stmt
					{
						$$ = new Stmt_cond(getLine(),getColumn(),$1);
					}
		|while_stmt
					{
						$$ = new Stmt_while(getLine(),getColumn(),$1);

					}
		|BREAK ';'
					{
					$$ = new Break_stmt(getLine(), getColumn());
					}
		|assignstmt ';'
					{
						$$ = new Stmt_assignstmt(getLine(),getColumn(),$1);
					}

		|CONTINUE ';' 
					{
						$$ = new Continue_stmt(getLine(), getColumn());		
					}
		|RETURN expr ';'
					{
						$$ = new Stmt_expr(getLine(),getColumn(),$2);
					}

;

cond_stmt:	IF '(' expr ')' stmt	%prec IF_PREC 
					{
					$$ = new If_cond_stmt(getLine(),getColumn(),$3,$5);

					}
			|IF '(' expr ')' stmt ELSE stmt
					{
					$$ = new Else_cond_stmt(getLine(),getColumn(),$3,$5,$7); 
					}
;
while_stmt: WHILE '(' expr ')' stmt 
					{
					$$ = new While_stmt(getLine(),getColumn(),$3,$5) ; 
					}
;
assignstmt: ID '=' expr
					{
					$$ = new Assign_stmt(getLine(),getColumn(),$1,$3);
					}
;
triplecondition: expr '?' expr ':' expr 
					{
						$$ = new TripleCondition(getLine(),getColumn(),$1,$3,$5);
					}
;
expr: primary
					{
						$$ = new Exp_primary(getLine(),getColumn(),$1);
					}
	|expr operator expr		%prec OP
					{
						$$ = new Operator_expr(getLine(),getColumn(),$2,$1,$3);
					}
	|'!' expr 
					{
						$$ = new Not_expr(getLine(),getColumn(),$2);
					}
	| '(' expr ')'
					{
						$$ = new Parentheses_expr(getLine(),getColumn(),$2);
					}
	|triplecondition
					{
					$$ = new Exp_triplecondition(getLine(),getColumn(),$1);
					}
	|'-' expr
					{
						$$ = new Minus_expr(getLine(),getColumn(),$2);
					}
	|ID '(' expr_list ')'
					{
					$$ = new Func_call_expr(getLine(),getColumn(),$1,$3);	
					}
	|ID '['expr ']' 
					{
					$$ = new Array_expr(getLine(),getColumn(),$1,$3);
					
					}
;
expr_list: 
					{
					$$ = new Expr_list(getLine(),getColumn());
					}
			|expr
					{
					$$ = new Expr_list(getLine(),getColumn(),$1);
					}
			|expr_list SPACECOM expr
					{
					$1-> add_expr($3);
					$$ = $1 ; 
					}
;

operator: '+'
				{
					$$ = new Operator(getLine(), getColumn(),1);
				}
		|'-'
				{
					$$ = new Operator(getLine(), getColumn(),2);
				}
		|'*'
				{
					$$ = new Operator(getLine(), getColumn(),3);
				}
		|'/'
				{
					$$ = new Operator(getLine(), getColumn(),4);
				}
		|'<'
				{
					$$ = new Operator(getLine(), getColumn(),5);
				}
		|'>'
				{
					$$ = new Operator(getLine(), getColumn(),6);
				}
		|'||'
				{
					$$ = new Operator(getLine(), getColumn(),7);
				}
		|IS_EQUAL
				{
					$$ = new Operator(getLine(), getColumn(),8);
				}
		|'&&'
				{
					$$ = new Operator(getLine(), getColumn(),9);
				}
;
primary:INTNUM
				{
					$$ = $1 ; 
				}
		|FLOATNUM
				{
					$$ = $1 ;
				}
		|CHARCONST
				{
					$$ = $1 ; 
				}
		|STRINGCONST
				{
					$$ = $1 ;
				}
		|ID
				{
					$$ = new Primary_id( getLine(), getColumn(), $1); 
				}
		|TRUE
				{
					$$ = new Primary_true(getLine(), getColumn());
				}
		|FALSE
				{
					$$ = new Primary_false(getLine(), getColumn());
				}
		|NUL
				{
					$$ = new Primary_null(getLine() , getColumn()) ; 
				}
;
primary_list: primary_list ',' primary
				{
					$1->add_primary($3);
					$$ = $1 ; 
				}
				| primary
				{
					$$ = new Primary_list(getLine(),getColumn(),$1);
				}
;
	
%%


int yyerror(const char *s1)
{
	flage = true ;
	cout << "Syntax Error : " << "line : "<< getLine()  << " column : " << getColumn() << endl;
	return 1;
}
