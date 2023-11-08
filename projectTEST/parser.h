/* A Bison parser, made by GNU Bison 2.1.  */

/* Skeleton parser for Yacc-like parsing with Bison,
   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ID = 258,
     INTNUM = 259,
     ACCMOD = 260,
     INT = 261,
     FLOAT = 262,
     CHAR = 263,
     STRING = 264,
     BOOL = 265,
     RETURN = 266,
     BREAK = 267,
     CONTINUE = 268,
     WHILE = 269,
     IF = 270,
     ELSE = 271,
     FLOATNUM = 272,
     CHARCONST = 273,
     STRINGCONST = 274,
     TRUE = 275,
     FALSE = 276,
     NUL = 277,
     IS_EQUAL = 278,
     SPACECOM = 279,
     CLASS = 280,
     IF_PREC = 281,
     OP = 282
   };
#endif
/* Tokens.  */
#define ID 258
#define INTNUM 259
#define ACCMOD 260
#define INT 261
#define FLOAT 262
#define CHAR 263
#define STRING 264
#define BOOL 265
#define RETURN 266
#define BREAK 267
#define CONTINUE 268
#define WHILE 269
#define IF 270
#define ELSE 271
#define FLOATNUM 272
#define CHARCONST 273
#define STRINGCONST 274
#define TRUE 275
#define FALSE 276
#define NUL 277
#define IS_EQUAL 278
#define SPACECOM 279
#define CLASS 280
#define IF_PREC 281
#define OP 282




#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
#line 20 "G:\\projectTEST_ast\\projectTEST\\projectTEST\\parser.y"
typedef union YYSTYPE {

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

} YYSTYPE;
/* Line 1447 of yacc.c.  */
#line 126 "parser.h"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;



