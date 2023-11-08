#include <iostream>
#include "ast.h"
using namespace std; 


extern int yyerror(const char* s);
extern int yylex();
extern int yydebug;
extern int yyparse();
extern bool flage; 

extern Class_decl* root;



int main()
{
	flage = false;
	yydebug = 0;
	yyparse();
	if (flage == false) cout << "parsing done !!!" << endl;
	root;
	Visitor* visitor = new PrintVisitor();
	root->accept(visitor);
	return 0;

}
