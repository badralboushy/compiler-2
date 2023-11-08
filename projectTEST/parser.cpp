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

/* Written by Richard Stallman by simplifying the original so called
   ``semantic'' parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



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




/* Copy the first part of user declarations.  */
#line 1 "G:\\projectTEST_ast\\projectTEST\\projectTEST\\parser.y"

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



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

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
/* Line 196 of yacc.c.  */
#line 192 "parser.cpp"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 219 of yacc.c.  */
#line 204 "parser.cpp"

#if ! defined (YYSIZE_T) && defined (__SIZE_TYPE__)
# define YYSIZE_T __SIZE_TYPE__
#endif
#if ! defined (YYSIZE_T) && defined (size_t)
# define YYSIZE_T size_t
#endif
#if ! defined (YYSIZE_T) && (defined (__STDC__) || defined (__cplusplus))
# include <stddef.h> /* INFRINGES ON USER NAME SPACE */
# define YYSIZE_T size_t
#endif
#if ! defined (YYSIZE_T)
# define YYSIZE_T unsigned int
#endif

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

#if ! defined (yyoverflow) || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if defined (__STDC__) || defined (__cplusplus)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     define YYINCLUDED_STDLIB_H
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning. */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2005 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM ((YYSIZE_T) -1)
#  endif
#  ifdef __cplusplus
extern "C" {
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if (! defined (malloc) && ! defined (YYINCLUDED_STDLIB_H) \
	&& (defined (__STDC__) || defined (__cplusplus)))
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if (! defined (free) && ! defined (YYINCLUDED_STDLIB_H) \
	&& (defined (__STDC__) || defined (__cplusplus)))
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifdef __cplusplus
}
#  endif
# endif
#endif /* ! defined (yyoverflow) || YYERROR_VERBOSE */


#if (! defined (yyoverflow) \
     && (! defined (__cplusplus) \
	 || (defined (YYSTYPE_IS_TRIVIAL) && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  short int yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (short int) + sizeof (YYSTYPE))			\
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined (__GNUC__) && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (0)
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (0)

#endif

#if defined (__STDC__) || defined (__cplusplus)
   typedef signed char yysigned_char;
#else
   typedef short int yysigned_char;
#endif

/* YYFINAL -- State number of the termination state. */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   256

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  23
/* YYNRULES -- Number of rules. */
#define YYNRULES  74
/* YYNRULES -- Number of states. */
#define YYNSTATES  140

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   282

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const unsigned char yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    31,     2,     2,     2,     2,    29,     2,
      37,    38,    35,    33,    46,    34,     2,    36,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    40,    47,
      27,    32,    28,    41,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    44,     2,    45,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    42,    30,    43,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    39
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const unsigned char yyprhs[] =
{
       0,     0,     3,    10,    16,    17,    20,    23,    26,    29,
      35,    42,    51,    53,    55,    57,    59,    61,    62,    64,
      68,    71,    76,    80,    81,    84,    87,    91,    93,    97,
      99,   103,   111,   115,   117,   119,   121,   124,   127,   130,
     134,   140,   148,   154,   158,   164,   166,   170,   173,   177,
     179,   182,   187,   192,   193,   195,   199,   201,   203,   205,
     207,   209,   211,   213,   215,   217,   219,   221,   223,   225,
     227,   229,   231,   233,   237
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const yysigned_char yyrhs[] =
{
      49,     0,    -1,     5,    25,     3,    42,    50,    43,    -1,
      25,     3,    42,    50,    43,    -1,    -1,    50,    52,    -1,
      50,    58,    -1,    50,    49,    -1,    50,    51,    -1,     3,
      37,    54,    38,    56,    -1,    53,     3,    37,    54,    38,
      56,    -1,    53,    44,    45,     3,    37,    54,    38,    56,
      -1,     6,    -1,     7,    -1,     8,    -1,     9,    -1,    10,
      -1,    -1,    55,    -1,    54,    46,    55,    -1,    53,     3,
      -1,    53,     3,    44,    45,    -1,    42,    57,    43,    -1,
      -1,    57,    58,    -1,    57,    61,    -1,    53,    59,    47,
      -1,    60,    -1,    59,    46,    60,    -1,     3,    -1,     3,
      32,    66,    -1,     3,    44,    45,    32,    42,    70,    43,
      -1,     3,    44,    45,    -1,    56,    -1,    62,    -1,    63,
      -1,    12,    47,    -1,    64,    47,    -1,    13,    47,    -1,
      11,    66,    47,    -1,    15,    37,    66,    38,    61,    -1,
      15,    37,    66,    38,    61,    16,    61,    -1,    14,    37,
      66,    38,    61,    -1,     3,    32,    66,    -1,    66,    41,
      66,    40,    66,    -1,    69,    -1,    66,    68,    66,    -1,
      31,    66,    -1,    37,    66,    38,    -1,    65,    -1,    34,
      66,    -1,     3,    37,    67,    38,    -1,     3,    44,    66,
      45,    -1,    -1,    66,    -1,    67,    24,    66,    -1,    33,
      -1,    34,    -1,    35,    -1,    36,    -1,    27,    -1,    28,
      -1,    30,    -1,    23,    -1,    29,    -1,     4,    -1,    17,
      -1,    18,    -1,    19,    -1,     3,    -1,    20,    -1,    21,
      -1,    22,    -1,    70,    46,    69,    -1,    69,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short int yyrline[] =
{
       0,   104,   104,   111,   119,   122,   127,   132,   136,   144,
     152,   156,   161,   165,   169,   174,   178,   185,   188,   192,
     199,   203,   209,   215,   218,   224,   231,   236,   240,   246,
     250,   254,   258,   267,   272,   276,   281,   285,   290,   294,
     301,   306,   311,   316,   321,   326,   330,   334,   338,   342,
     346,   350,   354,   361,   364,   368,   375,   379,   383,   387,
     391,   395,   399,   403,   407,   412,   416,   420,   424,   428,
     432,   436,   440,   445,   450
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals. */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "INTNUM", "ACCMOD", "INT", "FLOAT",
  "CHAR", "STRING", "BOOL", "RETURN", "BREAK", "CONTINUE", "WHILE", "IF",
  "ELSE", "FLOATNUM", "CHARCONST", "STRINGCONST", "TRUE", "FALSE", "NUL",
  "IS_EQUAL", "SPACECOM", "CLASS", "IF_PREC", "'<'", "'>'", "'&&'", "'||'",
  "'!'", "'='", "'+'", "'-'", "'*'", "'/'", "'('", "')'", "OP", "':'",
  "'?'", "'{'", "'}'", "'['", "']'", "','", "';'", "$accept", "class_decl",
  "smallc_program", "constructor", "func", "type_specifier",
  "param_decl_list", "param_decl", "compound_stmt", "compound_stmts",
  "var_decl", "var_decl_list", "variable_id", "stmt", "cond_stmt",
  "while_stmt", "assignstmt", "triplecondition", "expr", "expr_list",
  "operator", "primary", "primary_list", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const unsigned short int yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,    60,    62,    38,
     124,    33,    61,    43,    45,    42,    47,    40,    41,   282,
      58,    63,   123,   125,    91,    93,    44,    59
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned char yyr1[] =
{
       0,    48,    49,    49,    50,    50,    50,    50,    50,    51,
      52,    52,    53,    53,    53,    53,    53,    54,    54,    54,
      55,    55,    56,    57,    57,    57,    58,    59,    59,    60,
      60,    60,    60,    61,    61,    61,    61,    61,    61,    61,
      62,    62,    63,    64,    65,    66,    66,    66,    66,    66,
      66,    66,    66,    67,    67,    67,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    69,    69,    69,    69,    69,
      69,    69,    69,    70,    70
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     6,     5,     0,     2,     2,     2,     2,     5,
       6,     8,     1,     1,     1,     1,     1,     0,     1,     3,
       2,     4,     3,     0,     2,     2,     3,     1,     3,     1,
       3,     7,     3,     1,     1,     1,     2,     2,     2,     3,
       5,     7,     5,     3,     5,     1,     3,     2,     3,     1,
       2,     4,     4,     0,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned char yydefact[] =
{
       0,     0,     0,     0,     0,     0,     1,     0,     4,     4,
       0,     0,     0,    12,    13,    14,    15,    16,     3,     7,
       8,     5,     0,     6,     2,    17,    29,     0,     0,    27,
       0,     0,    18,     0,    17,     0,     0,     0,    26,    20,
       0,     0,    69,    65,    66,    67,    68,    70,    71,    72,
       0,     0,     0,    49,    30,    45,     0,    32,     0,    29,
      28,     0,    23,     9,    19,    53,     0,    47,    50,     0,
      63,    60,    61,    64,    62,    56,    57,    58,    59,     0,
       0,     0,     0,    17,    21,     0,    54,     0,     0,    48,
       0,    46,    10,     0,     0,     0,     0,     0,     0,     0,
       0,    22,     0,    33,    24,    25,    34,    35,     0,     0,
      51,    52,     0,    69,    74,     0,     0,     0,     0,    36,
      38,     0,     0,    37,    55,    44,    31,     0,    11,    43,
      39,     0,     0,    73,     0,     0,    42,    40,     0,    41
};

/* YYDEFGOTO[NTERM-NUM]. */
static const yysigned_char yydefgoto[] =
{
      -1,    19,    10,    20,    21,    30,    31,    32,   103,    85,
      23,    28,    29,   105,   106,   107,   108,    53,    54,    87,
      80,    55,   115
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -89
static const short int yypact[] =
{
      15,    23,    52,    57,    55,    26,   -89,    31,   -89,   -89,
       9,    77,    44,   -89,   -89,   -89,   -89,   -89,   -89,   -89,
     -89,   -89,     1,   -89,   -89,   157,    10,    48,   -36,   -89,
      91,     0,   -89,    87,   157,    50,    98,   100,   -89,    68,
      71,   157,   -31,   -89,   -89,   -89,   -89,   -89,   -89,   -89,
      87,    87,    87,   -89,   215,   -89,     5,    82,    78,    12,
     -89,    72,   -89,   -89,   -89,    87,    87,    29,    75,   152,
     -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,    87,
      87,    71,    80,   157,   -89,    18,   215,    11,   117,   -89,
     168,    92,   -89,   151,    21,    94,    87,    76,    81,    97,
     104,   -89,   100,   -89,   -89,   -89,   -89,   -89,    95,    87,
     -89,   -89,    87,   -89,   -89,    46,    71,    87,   102,   -89,
     -89,    87,    87,   -89,   215,    92,   -89,   151,   -89,   215,
     -89,   183,   199,   -89,    85,    85,   -89,   103,    85,   -89
};

/* YYPGOTO[NTERM-NUM].  */
static const short int yypgoto[] =
{
     -89,   139,   147,   -89,   -89,    -8,   -33,   107,   -40,   -89,
      74,   -89,   120,   -63,   -89,   -89,   -89,   -89,   -43,   -89,
     -89,   -88,   -89
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const unsigned char yytable[] =
{
      63,    56,    22,    22,    26,   114,    65,    67,    68,    69,
      37,    38,    12,    66,     1,    13,    14,    15,    16,    17,
       1,    95,    86,    88,    13,    14,    15,    16,    17,    96,
      97,    98,    99,   100,     2,   109,    90,    91,    40,   133,
       2,    92,    33,    81,    33,    27,    41,    34,     4,   110,
      94,    41,    18,   118,    35,     5,    35,     6,     7,   116,
      62,   101,    75,    76,    77,    78,   124,    41,     8,   125,
      79,   136,   137,     9,   129,   139,   128,   102,   131,   132,
      12,    25,     1,    13,    14,    15,    16,    17,    95,   126,
      42,    43,   127,    36,    39,    57,    96,    97,    98,    99,
     100,    58,     2,    59,    44,    45,    46,    47,    48,    49,
      77,    78,    61,    62,    82,    83,    79,    84,    50,   138,
      24,    51,    93,   119,    52,    70,   117,    62,   120,    71,
      72,    73,    74,    79,   121,    75,    76,    77,    78,     3,
      70,   122,   123,    79,    71,    72,    73,    74,    64,   130,
      75,    76,    77,    78,   113,    43,    11,    60,    79,   104,
       0,     0,   111,    13,    14,    15,    16,    17,    44,    45,
      46,    47,    48,    49,     0,    70,     0,     0,     0,    71,
      72,    73,    74,     0,     0,    75,    76,    77,    78,     0,
      89,    70,     0,    79,     0,    71,    72,    73,    74,     0,
       0,    75,    76,    77,    78,     0,    70,     0,   112,    79,
      71,    72,    73,    74,     0,     0,    75,    76,    77,    78,
       0,   134,    70,     0,    79,     0,    71,    72,    73,    74,
       0,     0,    75,    76,    77,    78,     0,   135,    70,     0,
      79,     0,    71,    72,    73,    74,     0,     0,    75,    76,
      77,    78,     0,     0,     0,     0,    79
};

static const short int yycheck[] =
{
      40,    34,    10,    11,     3,    93,    37,    50,    51,    52,
      46,    47,     3,    44,     5,     6,     7,     8,     9,    10,
       5,     3,    65,    66,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    25,    24,    79,    80,    38,   127,
      25,    81,    32,    38,    32,    44,    46,    37,    25,    38,
      83,    46,    43,    96,    44,     3,    44,     0,     3,    38,
      42,    43,    33,    34,    35,    36,   109,    46,    42,   112,
      41,   134,   135,    42,   117,   138,   116,    85,   121,   122,
       3,    37,     5,     6,     7,     8,     9,    10,     3,    43,
       3,     4,    46,    45,     3,    45,    11,    12,    13,    14,
      15,     3,    25,     3,    17,    18,    19,    20,    21,    22,
      35,    36,    44,    42,    32,    37,    41,    45,    31,    16,
      43,    34,    42,    47,    37,    23,    32,    42,    47,    27,
      28,    29,    30,    41,    37,    33,    34,    35,    36,     0,
      23,    37,    47,    41,    27,    28,    29,    30,    41,    47,
      33,    34,    35,    36,     3,     4,     9,    37,    41,    85,
      -1,    -1,    45,     6,     7,     8,     9,    10,    17,    18,
      19,    20,    21,    22,    -1,    23,    -1,    -1,    -1,    27,
      28,    29,    30,    -1,    -1,    33,    34,    35,    36,    -1,
      38,    23,    -1,    41,    -1,    27,    28,    29,    30,    -1,
      -1,    33,    34,    35,    36,    -1,    23,    -1,    40,    41,
      27,    28,    29,    30,    -1,    -1,    33,    34,    35,    36,
      -1,    38,    23,    -1,    41,    -1,    27,    28,    29,    30,
      -1,    -1,    33,    34,    35,    36,    -1,    38,    23,    -1,
      41,    -1,    27,    28,    29,    30,    -1,    -1,    33,    34,
      35,    36,    -1,    -1,    -1,    -1,    41
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned char yystos[] =
{
       0,     5,    25,    49,    25,     3,     0,     3,    42,    42,
      50,    50,     3,     6,     7,     8,     9,    10,    43,    49,
      51,    52,    53,    58,    43,    37,     3,    44,    59,    60,
      53,    54,    55,    32,    37,    44,    45,    46,    47,     3,
      38,    46,     3,     4,    17,    18,    19,    20,    21,    22,
      31,    34,    37,    65,    66,    69,    54,    45,     3,     3,
      60,    44,    42,    56,    55,    37,    44,    66,    66,    66,
      23,    27,    28,    29,    30,    33,    34,    35,    36,    41,
      68,    38,    32,    37,    45,    57,    66,    67,    66,    38,
      66,    66,    56,    42,    54,     3,    11,    12,    13,    14,
      15,    43,    53,    56,    58,    61,    62,    63,    64,    24,
      38,    45,    40,     3,    69,    70,    38,    32,    66,    47,
      47,    37,    37,    47,    66,    66,    43,    46,    56,    66,
      47,    66,    66,    69,    38,    38,    61,    61,    16,    61
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (0)


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (N)								\
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (0)
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
              (Loc).first_line, (Loc).first_column,	\
              (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (0)

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)		\
do {								\
  if (yydebug)							\
    {								\
      YYFPRINTF (stderr, "%s ", Title);				\
      yysymprint (stderr,					\
                  Type, Value);	\
      YYFPRINTF (stderr, "\n");					\
    }								\
} while (0)

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_stack_print (short int *bottom, short int *top)
#else
static void
yy_stack_print (bottom, top)
    short int *bottom;
    short int *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (/* Nothing. */; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_reduce_print (int yyrule)
#else
static void
yy_reduce_print (yyrule)
    int yyrule;
#endif
{
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu), ",
             yyrule - 1, yylno);
  /* Print the symbols being reduced, and their result.  */
  for (yyi = yyprhs[yyrule]; 0 <= yyrhs[yyi]; yyi++)
    YYFPRINTF (stderr, "%s ", yytname[yyrhs[yyi]]);
  YYFPRINTF (stderr, "-> %s\n", yytname[yyr1[yyrule]]);
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (Rule);		\
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined (__GLIBC__) && defined (_STRING_H)
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
#   if defined (__STDC__) || defined (__cplusplus)
yystrlen (const char *yystr)
#   else
yystrlen (yystr)
     const char *yystr;
#   endif
{
  const char *yys = yystr;

  while (*yys++ != '\0')
    continue;

  return yys - yystr - 1;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined (__GLIBC__) && defined (_STRING_H) && defined (_GNU_SOURCE)
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
#   if defined (__STDC__) || defined (__cplusplus)
yystpcpy (char *yydest, const char *yysrc)
#   else
yystpcpy (yydest, yysrc)
     char *yydest;
     const char *yysrc;
#   endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      size_t yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

#endif /* YYERROR_VERBOSE */



#if YYDEBUG
/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yysymprint (FILE *yyoutput, int yytype, YYSTYPE *yyvaluep)
#else
static void
yysymprint (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);


# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  switch (yytype)
    {
      default:
        break;
    }
  YYFPRINTF (yyoutput, ")");
}

#endif /* ! YYDEBUG */
/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
        break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM);
# else
int yyparse ();
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM)
# else
int yyparse (YYPARSE_PARAM)
  void *YYPARSE_PARAM;
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
int
yyparse (void)
#else
int
yyparse ()
    ;
#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  short int yyssa[YYINITDEPTH];
  short int *yyss = yyssa;
  short int *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK   (yyvsp--, yyssp--)

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* When reducing, the number of symbols on the RHS of the reduced
     rule.  */
  int yylen;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed. so pushing a state here evens the stacks.
     */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack. Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	short int *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	short int *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

/* Do appropriate processing given the current state.  */
/* Read a look-ahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to look-ahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;


  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  yystate = yyn;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 105 "G:\\projectTEST_ast\\projectTEST\\projectTEST\\parser.y"
    {
						(yyval.tClass_decl) = new Class_decl(getLine(),getColumn(),(yyvsp[-5].taccmod),(yyvsp[-3].tId),(yyvsp[-1].tSmall_program) );
						root = (yyval.tClass_decl) 

					
					;}
    break;

  case 3:
#line 112 "G:\\projectTEST_ast\\projectTEST\\projectTEST\\parser.y"
    {
					(yyval.tClass_decl) = new Class_decl(getLine(), getColumn(),"private" ,(yyvsp[-3].tId), (yyvsp[-1].tSmall_program)) ; 
					root = (yyval.tClass_decl) ; 
					;}
    break;

  case 4:
#line 119 "G:\\projectTEST_ast\\projectTEST\\projectTEST\\parser.y"
    {
					// i don't know what to do here ......................
					;}
    break;

  case 5:
#line 123 "G:\\projectTEST_ast\\projectTEST\\projectTEST\\parser.y"
    {
					(yyval.tSmall_program) = new Func_program(getLine(),getColumn(),(yyvsp[-1].tSmall_program) ,(yyvsp[0].tFunc));
					;}
    break;

  case 6:
#line 128 "G:\\projectTEST_ast\\projectTEST\\projectTEST\\parser.y"
    {
					(yyval.tSmall_program) = new Var_program(getLine(),getColumn(),(yyvsp[-1].tSmall_program),(yyvsp[0].tVar_decl)); 
					
					;}
    break;

  case 7:
#line 133 "G:\\projectTEST_ast\\projectTEST\\projectTEST\\parser.y"
    {
						(yyval.tSmall_program) = new Class_decl_program(getLine(),getColumn(),(yyvsp[-1].tSmall_program),(yyvsp[0].tClass_decl));
					;}
    break;

  case 8:
#line 137 "G:\\projectTEST_ast\\projectTEST\\projectTEST\\parser.y"
    {
					(yyval.tSmall_program) = new Constructor_program(getLine() , getColumn(), (yyvsp[-1].tSmall_program), (yyvsp[0].tConstructor));
					;}
    break;

  case 9:
#line 145 "G:\\projectTEST_ast\\projectTEST\\projectTEST\\parser.y"
    {
					(yyval.tConstructor) = new Constructor (getLine(),getColumn(),(yyvsp[-4].tId) , (yyvsp[-2].tParam_decl_list), (yyvsp[0].tCompound_stmt));
					;}
    break;

  case 10:
#line 153 "G:\\projectTEST_ast\\projectTEST\\projectTEST\\parser.y"
    {
			(yyval.tFunc)= new Normal_func(getLine(),getColumn(),(yyvsp[-5].ttype_specifier),(yyvsp[-4].tId),(yyvsp[-2].tParam_decl_list),(yyvsp[0].tCompound_stmt));
			;}
    break;

  case 11:
#line 157 "G:\\projectTEST_ast\\projectTEST\\projectTEST\\parser.y"
    {
			(yyval.tFunc) = new Array_func(getLine(),getColumn(), (yyvsp[-7].ttype_specifier), (yyvsp[-4].tId) ,(yyvsp[-2].tParam_decl_list) , (yyvsp[0].tCompound_stmt));
			;}
    break;

  case 12:
#line 162 "G:\\projectTEST_ast\\projectTEST\\projectTEST\\parser.y"
    {
						(yyval.ttype_specifier) = new Type_specifier(getLine(),getColumn(),1) ; 
					;}
    break;

  case 13:
#line 166 "G:\\projectTEST_ast\\projectTEST\\projectTEST\\parser.y"
    {
						(yyval.ttype_specifier) = new Type_specifier(getLine(),getColumn(),2) ; 
					;}
    break;

  case 14:
#line 170 "G:\\projectTEST_ast\\projectTEST\\projectTEST\\parser.y"
    {
						(yyval.ttype_specifier) = new Type_specifier(getLine(),getColumn(),3) ; 

					;}
    break;

  case 15:
#line 175 "G:\\projectTEST_ast\\projectTEST\\projectTEST\\parser.y"
    {
						(yyval.ttype_specifier) = new Type_specifier(getLine(),getColumn(),4) ; 
					;}
    break;

  case 16:
#line 179 "G:\\projectTEST_ast\\projectTEST\\projectTEST\\parser.y"
    {
						(yyval.ttype_specifier) = new Type_specifier(getLine(),getColumn(),5) ; 
					;}
    break;

  case 17:
#line 185 "G:\\projectTEST_ast\\projectTEST\\projectTEST\\parser.y"
    {
				(yyval.tParam_decl_list) = new Param_decl_list(getLine(),getColumn());
			;}
    break;

  case 18:
#line 189 "G:\\projectTEST_ast\\projectTEST\\projectTEST\\parser.y"
    {
				(yyval.tParam_decl_list) = new Param_decl_list(getLine(),getColumn(),(yyvsp[0].tParam_decl));
			;}
    break;

  case 19:
#line 193 "G:\\projectTEST_ast\\projectTEST\\projectTEST\\parser.y"
    {
				(yyvsp[-2].tParam_decl_list)->add_param((yyvsp[0].tParam_decl));
				(yyval.tParam_decl_list) = (yyvsp[-2].tParam_decl_list) ; 
			
			;}
    break;

  case 20:
#line 200 "G:\\projectTEST_ast\\projectTEST\\projectTEST\\parser.y"
    {
				(yyval.tParam_decl) = new Normal_param_decl(getLine(),getColumn(),(yyvsp[-1].ttype_specifier),(yyvsp[0].tId));
			;}
    break;

  case 21:
#line 204 "G:\\projectTEST_ast\\projectTEST\\projectTEST\\parser.y"
    {
				(yyval.tParam_decl) = new Array_param_decl(getLine(),getColumn(),(yyvsp[-3].ttype_specifier),(yyvsp[-2].tId));
			;}
    break;

  case 22:
#line 210 "G:\\projectTEST_ast\\projectTEST\\projectTEST\\parser.y"
    {
						(yyval.tCompound_stmt) = new Compound_stmt(getLine(),getColumn(),(yyvsp[-1].tCompound_stmts));
					;}
    break;

  case 23:
#line 215 "G:\\projectTEST_ast\\projectTEST\\projectTEST\\parser.y"
    {
						(yyval.tCompound_stmts) = new Compound_stmts(getLine(),getColumn());
					;}
    break;

  case 24:
#line 219 "G:\\projectTEST_ast\\projectTEST\\projectTEST\\parser.y"
    {
						if ( (yyvsp[-1].tCompound_stmts) == NULL) (yyvsp[-1].tCompound_stmts) = new Compound_stmts(getLine(),getColumn());
						(yyvsp[-1].tCompound_stmts)->add_var((yyvsp[0].tVar_decl));
						(yyval.tCompound_stmts) = (yyvsp[-1].tCompound_stmts) ; 
					;}
    break;

  case 25:
#line 225 "G:\\projectTEST_ast\\projectTEST\\projectTEST\\parser.y"
    {
						if ((yyvsp[-1].tCompound_stmts) == NULL) new Compound_stmts(getLine(),getColumn());
						(yyvsp[-1].tCompound_stmts)->add_stmt((yyvsp[0].tStmt));
						(yyval.tCompound_stmts) = (yyvsp[-1].tCompound_stmts) ; 
					;}
    break;

  case 26:
#line 232 "G:\\projectTEST_ast\\projectTEST\\projectTEST\\parser.y"
    {
						(yyval.tVar_decl) = new Var_decl(getLine(),getColumn(),(yyvsp[-2].ttype_specifier),(yyvsp[-1].tVar_decl_list));
					;}
    break;

  case 27:
#line 237 "G:\\projectTEST_ast\\projectTEST\\projectTEST\\parser.y"
    {
						(yyval.tVar_decl_list) = new Var_decl_list(getLine(),getColumn(), (yyvsp[0].tVariable_id));
					;}
    break;

  case 28:
#line 241 "G:\\projectTEST_ast\\projectTEST\\projectTEST\\parser.y"
    {
						(yyvsp[-2].tVar_decl_list)->add_var((yyvsp[0].tVariable_id));
						(yyval.tVar_decl_list) = (yyvsp[-2].tVar_decl_list) ; 
					;}
    break;

  case 29:
#line 247 "G:\\projectTEST_ast\\projectTEST\\projectTEST\\parser.y"
    {
						(yyval.tVariable_id)  = new Id_variable(getLine(),getColumn(),(yyvsp[0].tId)) ; 
					;}
    break;

  case 30:
#line 251 "G:\\projectTEST_ast\\projectTEST\\projectTEST\\parser.y"
    {
						(yyval.tVariable_id) = new Variable_assignment(getLine(),getColumn(),(yyvsp[-2].tId),(yyvsp[0].tExpr));
					;}
    break;

  case 31:
#line 255 "G:\\projectTEST_ast\\projectTEST\\projectTEST\\parser.y"
    {
						(yyval.tVariable_id) = new Array_variable_assignment(getLine(),getColumn(),(yyvsp[-6].tId),(yyvsp[-1].tPrimary_list));
					;}
    break;

  case 32:
#line 259 "G:\\projectTEST_ast\\projectTEST\\projectTEST\\parser.y"
    {
						(yyval.tVariable_id) = new Array_variable_id(getLine(),getColumn(),(yyvsp[-2].tId));
					;}
    break;

  case 33:
#line 268 "G:\\projectTEST_ast\\projectTEST\\projectTEST\\parser.y"
    {
						(yyval.tStmt) = new Stmt_compound(getLine(),getColumn(),(yyvsp[0].tCompound_stmt));
					
					;}
    break;

  case 34:
#line 273 "G:\\projectTEST_ast\\projectTEST\\projectTEST\\parser.y"
    {
						(yyval.tStmt) = new Stmt_cond(getLine(),getColumn(),(yyvsp[0].tCond_stmt));
					;}
    break;

  case 35:
#line 277 "G:\\projectTEST_ast\\projectTEST\\projectTEST\\parser.y"
    {
						(yyval.tStmt) = new Stmt_while(getLine(),getColumn(),(yyvsp[0].tWhile_stmt));

					;}
    break;

  case 36:
#line 282 "G:\\projectTEST_ast\\projectTEST\\projectTEST\\parser.y"
    {
					(yyval.tStmt) = new Break_stmt(getLine(), getColumn());
					;}
    break;

  case 37:
#line 286 "G:\\projectTEST_ast\\projectTEST\\projectTEST\\parser.y"
    {
						(yyval.tStmt) = new Stmt_assignstmt(getLine(),getColumn(),(yyvsp[-1].tAssign_stmt));
					;}
    break;

  case 38:
#line 291 "G:\\projectTEST_ast\\projectTEST\\projectTEST\\parser.y"
    {
						(yyval.tStmt) = new Continue_stmt(getLine(), getColumn());		
					;}
    break;

  case 39:
#line 295 "G:\\projectTEST_ast\\projectTEST\\projectTEST\\parser.y"
    {
						(yyval.tStmt) = new Stmt_expr(getLine(),getColumn(),(yyvsp[-1].tExpr));
					;}
    break;

  case 40:
#line 302 "G:\\projectTEST_ast\\projectTEST\\projectTEST\\parser.y"
    {
					(yyval.tCond_stmt) = new If_cond_stmt(getLine(),getColumn(),(yyvsp[-2].tExpr),(yyvsp[0].tStmt));

					;}
    break;

  case 41:
#line 307 "G:\\projectTEST_ast\\projectTEST\\projectTEST\\parser.y"
    {
					(yyval.tCond_stmt) = new Else_cond_stmt(getLine(),getColumn(),(yyvsp[-4].tExpr),(yyvsp[-2].tStmt),(yyvsp[0].tStmt)); 
					;}
    break;

  case 42:
#line 312 "G:\\projectTEST_ast\\projectTEST\\projectTEST\\parser.y"
    {
					(yyval.tWhile_stmt) = new While_stmt(getLine(),getColumn(),(yyvsp[-2].tExpr),(yyvsp[0].tStmt)) ; 
					;}
    break;

  case 43:
#line 317 "G:\\projectTEST_ast\\projectTEST\\projectTEST\\parser.y"
    {
					(yyval.tAssign_stmt) = new Assign_stmt(getLine(),getColumn(),(yyvsp[-2].tId),(yyvsp[0].tExpr));
					;}
    break;

  case 44:
#line 322 "G:\\projectTEST_ast\\projectTEST\\projectTEST\\parser.y"
    {
						(yyval.tTripleCondition) = new TripleCondition(getLine(),getColumn(),(yyvsp[-4].tExpr),(yyvsp[-2].tExpr),(yyvsp[0].tExpr));
					;}
    break;

  case 45:
#line 327 "G:\\projectTEST_ast\\projectTEST\\projectTEST\\parser.y"
    {
						(yyval.tExpr) = new Exp_primary(getLine(),getColumn(),(yyvsp[0].tPrimary));
					;}
    break;

  case 46:
#line 331 "G:\\projectTEST_ast\\projectTEST\\projectTEST\\parser.y"
    {
						(yyval.tExpr) = new Operator_expr(getLine(),getColumn(),(yyvsp[-1].tOperator),(yyvsp[-2].tExpr),(yyvsp[0].tExpr));
					;}
    break;

  case 47:
#line 335 "G:\\projectTEST_ast\\projectTEST\\projectTEST\\parser.y"
    {
						(yyval.tExpr) = new Not_expr(getLine(),getColumn(),(yyvsp[0].tExpr));
					;}
    break;

  case 48:
#line 339 "G:\\projectTEST_ast\\projectTEST\\projectTEST\\parser.y"
    {
						(yyval.tExpr) = new Parentheses_expr(getLine(),getColumn(),(yyvsp[-1].tExpr));
					;}
    break;

  case 49:
#line 343 "G:\\projectTEST_ast\\projectTEST\\projectTEST\\parser.y"
    {
					(yyval.tExpr) = new Exp_triplecondition(getLine(),getColumn(),(yyvsp[0].tTripleCondition));
					;}
    break;

  case 50:
#line 347 "G:\\projectTEST_ast\\projectTEST\\projectTEST\\parser.y"
    {
						(yyval.tExpr) = new Minus_expr(getLine(),getColumn(),(yyvsp[0].tExpr));
					;}
    break;

  case 51:
#line 351 "G:\\projectTEST_ast\\projectTEST\\projectTEST\\parser.y"
    {
					(yyval.tExpr) = new Func_call_expr(getLine(),getColumn(),(yyvsp[-3].tId),(yyvsp[-1].tExpr_list));	
					;}
    break;

  case 52:
#line 355 "G:\\projectTEST_ast\\projectTEST\\projectTEST\\parser.y"
    {
					(yyval.tExpr) = new Array_expr(getLine(),getColumn(),(yyvsp[-3].tId),(yyvsp[-1].tExpr));
					
					;}
    break;

  case 53:
#line 361 "G:\\projectTEST_ast\\projectTEST\\projectTEST\\parser.y"
    {
					(yyval.tExpr_list) = new Expr_list(getLine(),getColumn());
					;}
    break;

  case 54:
#line 365 "G:\\projectTEST_ast\\projectTEST\\projectTEST\\parser.y"
    {
					(yyval.tExpr_list) = new Expr_list(getLine(),getColumn(),(yyvsp[0].tExpr));
					;}
    break;

  case 55:
#line 369 "G:\\projectTEST_ast\\projectTEST\\projectTEST\\parser.y"
    {
					(yyvsp[-2].tExpr_list)-> add_expr((yyvsp[0].tExpr));
					(yyval.tExpr_list) = (yyvsp[-2].tExpr_list) ; 
					;}
    break;

  case 56:
#line 376 "G:\\projectTEST_ast\\projectTEST\\projectTEST\\parser.y"
    {
					(yyval.tOperator) = new Operator(getLine(), getColumn(),1);
				;}
    break;

  case 57:
#line 380 "G:\\projectTEST_ast\\projectTEST\\projectTEST\\parser.y"
    {
					(yyval.tOperator) = new Operator(getLine(), getColumn(),2);
				;}
    break;

  case 58:
#line 384 "G:\\projectTEST_ast\\projectTEST\\projectTEST\\parser.y"
    {
					(yyval.tOperator) = new Operator(getLine(), getColumn(),3);
				;}
    break;

  case 59:
#line 388 "G:\\projectTEST_ast\\projectTEST\\projectTEST\\parser.y"
    {
					(yyval.tOperator) = new Operator(getLine(), getColumn(),4);
				;}
    break;

  case 60:
#line 392 "G:\\projectTEST_ast\\projectTEST\\projectTEST\\parser.y"
    {
					(yyval.tOperator) = new Operator(getLine(), getColumn(),5);
				;}
    break;

  case 61:
#line 396 "G:\\projectTEST_ast\\projectTEST\\projectTEST\\parser.y"
    {
					(yyval.tOperator) = new Operator(getLine(), getColumn(),6);
				;}
    break;

  case 62:
#line 400 "G:\\projectTEST_ast\\projectTEST\\projectTEST\\parser.y"
    {
					(yyval.tOperator) = new Operator(getLine(), getColumn(),7);
				;}
    break;

  case 63:
#line 404 "G:\\projectTEST_ast\\projectTEST\\projectTEST\\parser.y"
    {
					(yyval.tOperator) = new Operator(getLine(), getColumn(),8);
				;}
    break;

  case 64:
#line 408 "G:\\projectTEST_ast\\projectTEST\\projectTEST\\parser.y"
    {
					(yyval.tOperator) = new Operator(getLine(), getColumn(),9);
				;}
    break;

  case 65:
#line 413 "G:\\projectTEST_ast\\projectTEST\\projectTEST\\parser.y"
    {
					(yyval.tPrimary) = (yyvsp[0].tPrimary_num) ; 
				;}
    break;

  case 66:
#line 417 "G:\\projectTEST_ast\\projectTEST\\projectTEST\\parser.y"
    {
					(yyval.tPrimary) = (yyvsp[0].tPrimary_float) ;
				;}
    break;

  case 67:
#line 421 "G:\\projectTEST_ast\\projectTEST\\projectTEST\\parser.y"
    {
					(yyval.tPrimary) = (yyvsp[0].tPrimary_char) ; 
				;}
    break;

  case 68:
#line 425 "G:\\projectTEST_ast\\projectTEST\\projectTEST\\parser.y"
    {
					(yyval.tPrimary) = (yyvsp[0].tPrimary_string) ;
				;}
    break;

  case 69:
#line 429 "G:\\projectTEST_ast\\projectTEST\\projectTEST\\parser.y"
    {
					(yyval.tPrimary) = new Primary_id( getLine(), getColumn(), (yyvsp[0].tId)); 
				;}
    break;

  case 70:
#line 433 "G:\\projectTEST_ast\\projectTEST\\projectTEST\\parser.y"
    {
					(yyval.tPrimary) = new Primary_true(getLine(), getColumn());
				;}
    break;

  case 71:
#line 437 "G:\\projectTEST_ast\\projectTEST\\projectTEST\\parser.y"
    {
					(yyval.tPrimary) = new Primary_false(getLine(), getColumn());
				;}
    break;

  case 72:
#line 441 "G:\\projectTEST_ast\\projectTEST\\projectTEST\\parser.y"
    {
					(yyval.tPrimary) = new Primary_null(getLine() , getColumn()) ; 
				;}
    break;

  case 73:
#line 446 "G:\\projectTEST_ast\\projectTEST\\projectTEST\\parser.y"
    {
					(yyvsp[-2].tPrimary_list)->add_primary((yyvsp[0].tPrimary));
					(yyval.tPrimary_list) = (yyvsp[-2].tPrimary_list) ; 
				;}
    break;

  case 74:
#line 451 "G:\\projectTEST_ast\\projectTEST\\projectTEST\\parser.y"
    {
					(yyval.tPrimary_list) = new Primary_list(getLine(),getColumn(),(yyvsp[0].tPrimary));
				;}
    break;


      default: break;
    }

/* Line 1126 of yacc.c.  */
#line 1867 "parser.cpp"

  yyvsp -= yylen;
  yyssp -= yylen;


  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (YYPACT_NINF < yyn && yyn < YYLAST)
	{
	  int yytype = YYTRANSLATE (yychar);
	  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
	  YYSIZE_T yysize = yysize0;
	  YYSIZE_T yysize1;
	  int yysize_overflow = 0;
	  char *yymsg = 0;
#	  define YYERROR_VERBOSE_ARGS_MAXIMUM 5
	  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
	  int yyx;

#if 0
	  /* This is so xgettext sees the translatable formats that are
	     constructed on the fly.  */
	  YY_("syntax error, unexpected %s");
	  YY_("syntax error, unexpected %s, expecting %s");
	  YY_("syntax error, unexpected %s, expecting %s or %s");
	  YY_("syntax error, unexpected %s, expecting %s or %s or %s");
	  YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
#endif
	  char *yyfmt;
	  char const *yyf;
	  static char const yyunexpected[] = "syntax error, unexpected %s";
	  static char const yyexpecting[] = ", expecting %s";
	  static char const yyor[] = " or %s";
	  char yyformat[sizeof yyunexpected
			+ sizeof yyexpecting - 1
			+ ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
			   * (sizeof yyor - 1))];
	  char const *yyprefix = yyexpecting;

	  /* Start YYX at -YYN if negative to avoid negative indexes in
	     YYCHECK.  */
	  int yyxbegin = yyn < 0 ? -yyn : 0;

	  /* Stay within bounds of both yycheck and yytname.  */
	  int yychecklim = YYLAST - yyn;
	  int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
	  int yycount = 1;

	  yyarg[0] = yytname[yytype];
	  yyfmt = yystpcpy (yyformat, yyunexpected);

	  for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	      {
		if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
		  {
		    yycount = 1;
		    yysize = yysize0;
		    yyformat[sizeof yyunexpected - 1] = '\0';
		    break;
		  }
		yyarg[yycount++] = yytname[yyx];
		yysize1 = yysize + yytnamerr (0, yytname[yyx]);
		yysize_overflow |= yysize1 < yysize;
		yysize = yysize1;
		yyfmt = yystpcpy (yyfmt, yyprefix);
		yyprefix = yyor;
	      }

	  yyf = YY_(yyformat);
	  yysize1 = yysize + yystrlen (yyf);
	  yysize_overflow |= yysize1 < yysize;
	  yysize = yysize1;

	  if (!yysize_overflow && yysize <= YYSTACK_ALLOC_MAXIMUM)
	    yymsg = (char *) YYSTACK_ALLOC (yysize);
	  if (yymsg)
	    {
	      /* Avoid sprintf, as that infringes on the user's name space.
		 Don't have undefined behavior even if the translation
		 produced a string with the wrong number of "%s"s.  */
	      char *yyp = yymsg;
	      int yyi = 0;
	      while ((*yyp = *yyf))
		{
		  if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		    {
		      yyp += yytnamerr (yyp, yyarg[yyi++]);
		      yyf += 2;
		    }
		  else
		    {
		      yyp++;
		      yyf++;
		    }
		}
	      yyerror (yymsg);
	      YYSTACK_FREE (yymsg);
	    }
	  else
	    {
	      yyerror (YY_("syntax error"));
	      goto yyexhaustedlab;
	    }
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror (YY_("syntax error"));
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
        {
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
        }
      else
	{
	  yydestruct ("Error: discarding", yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (0)
     goto yyerrorlab;

yyvsp -= yylen;
  yyssp -= yylen;
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping", yystos[yystate], yyvsp);
      YYPOPSTACK;
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token. */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK;
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  return yyresult;
}


#line 456 "G:\\projectTEST_ast\\projectTEST\\projectTEST\\parser.y"



int yyerror(const char *s1)
{
	flage = true ;
	cout << "Syntax Error : " << "line : "<< getLine()  << " column : " << getColumn() << endl;
	return 1;
}

