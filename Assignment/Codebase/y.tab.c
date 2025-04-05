/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
extern int yylineno;
extern FILE *yyin;
extern int yyparse();
void yyerror(char *s);
int yylex();
extern int column;
extern char *yytext;
int skip_to_sync(void);
int has_errors = 0;

#line 86 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    T_ID = 258,                    /* T_ID  */
    T_NUM = 259,                   /* T_NUM  */
    T_INT = 260,                   /* T_INT  */
    T_FLOAT = 261,                 /* T_FLOAT  */
    T_CHAR = 262,                  /* T_CHAR  */
    T_DOUBLE = 263,                /* T_DOUBLE  */
    T_IF = 264,                    /* T_IF  */
    T_WHILE = 265,                 /* T_WHILE  */
    T_FOR = 266,                   /* T_FOR  */
    T_DO = 267,                    /* T_DO  */
    T_ELSE = 268,                  /* T_ELSE  */
    T_SWITCH = 269,                /* T_SWITCH  */
    T_CASE = 270,                  /* T_CASE  */
    T_BREAK = 271,                 /* T_BREAK  */
    T_DEFAULT = 272,               /* T_DEFAULT  */
    T_MAIN = 273,                  /* T_MAIN  */
    T_LE = 274,                    /* T_LE  */
    T_GE = 275,                    /* T_GE  */
    T_NE = 276,                    /* T_NE  */
    T_EQ = 277,                    /* T_EQ  */
    T_AND = 278,                   /* T_AND  */
    T_OR = 279,                    /* T_OR  */
    T_NOT = 280,                   /* T_NOT  */
    T_INC = 281,                   /* T_INC  */
    T_DEC = 282,                   /* T_DEC  */
    T_CHAR_QUOTE = 283             /* T_CHAR_QUOTE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define T_ID 258
#define T_NUM 259
#define T_INT 260
#define T_FLOAT 261
#define T_CHAR 262
#define T_DOUBLE 263
#define T_IF 264
#define T_WHILE 265
#define T_FOR 266
#define T_DO 267
#define T_ELSE 268
#define T_SWITCH 269
#define T_CASE 270
#define T_BREAK 271
#define T_DEFAULT 272
#define T_MAIN 273
#define T_LE 274
#define T_GE 275
#define T_NE 276
#define T_EQ 277
#define T_AND 278
#define T_OR 279
#define T_NOT 280
#define T_INC 281
#define T_DEC 282
#define T_CHAR_QUOTE 283

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 16 "parser.y"

    char *sval;

#line 199 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_T_ID = 3,                       /* T_ID  */
  YYSYMBOL_T_NUM = 4,                      /* T_NUM  */
  YYSYMBOL_T_INT = 5,                      /* T_INT  */
  YYSYMBOL_T_FLOAT = 6,                    /* T_FLOAT  */
  YYSYMBOL_T_CHAR = 7,                     /* T_CHAR  */
  YYSYMBOL_T_DOUBLE = 8,                   /* T_DOUBLE  */
  YYSYMBOL_T_IF = 9,                       /* T_IF  */
  YYSYMBOL_T_WHILE = 10,                   /* T_WHILE  */
  YYSYMBOL_T_FOR = 11,                     /* T_FOR  */
  YYSYMBOL_T_DO = 12,                      /* T_DO  */
  YYSYMBOL_T_ELSE = 13,                    /* T_ELSE  */
  YYSYMBOL_T_SWITCH = 14,                  /* T_SWITCH  */
  YYSYMBOL_T_CASE = 15,                    /* T_CASE  */
  YYSYMBOL_T_BREAK = 16,                   /* T_BREAK  */
  YYSYMBOL_T_DEFAULT = 17,                 /* T_DEFAULT  */
  YYSYMBOL_T_MAIN = 18,                    /* T_MAIN  */
  YYSYMBOL_T_LE = 19,                      /* T_LE  */
  YYSYMBOL_T_GE = 20,                      /* T_GE  */
  YYSYMBOL_T_NE = 21,                      /* T_NE  */
  YYSYMBOL_T_EQ = 22,                      /* T_EQ  */
  YYSYMBOL_T_AND = 23,                     /* T_AND  */
  YYSYMBOL_T_OR = 24,                      /* T_OR  */
  YYSYMBOL_T_NOT = 25,                     /* T_NOT  */
  YYSYMBOL_T_INC = 26,                     /* T_INC  */
  YYSYMBOL_T_DEC = 27,                     /* T_DEC  */
  YYSYMBOL_T_CHAR_QUOTE = 28,              /* T_CHAR_QUOTE  */
  YYSYMBOL_29_ = 29,                       /* '('  */
  YYSYMBOL_30_ = 30,                       /* ')'  */
  YYSYMBOL_31_ = 31,                       /* '{'  */
  YYSYMBOL_32_ = 32,                       /* '}'  */
  YYSYMBOL_33_ = 33,                       /* ';'  */
  YYSYMBOL_34_ = 34,                       /* '['  */
  YYSYMBOL_35_ = 35,                       /* ']'  */
  YYSYMBOL_36_ = 36,                       /* '='  */
  YYSYMBOL_37_ = 37,                       /* ':'  */
  YYSYMBOL_38_ = 38,                       /* ','  */
  YYSYMBOL_39_ = 39,                       /* '+'  */
  YYSYMBOL_40_ = 40,                       /* '-'  */
  YYSYMBOL_41_ = 41,                       /* '>'  */
  YYSYMBOL_42_ = 42,                       /* '<'  */
  YYSYMBOL_43_ = 43,                       /* '!'  */
  YYSYMBOL_44_ = 44,                       /* '*'  */
  YYSYMBOL_45_ = 45,                       /* '/'  */
  YYSYMBOL_46_ = 46,                       /* '%'  */
  YYSYMBOL_YYACCEPT = 47,                  /* $accept  */
  YYSYMBOL_P = 48,                         /* P  */
  YYSYMBOL_S = 49,                         /* S  */
  YYSYMBOL_50_1 = 50,                      /* $@1  */
  YYSYMBOL_51_2 = 51,                      /* $@2  */
  YYSYMBOL_swt = 52,                       /* swt  */
  YYSYMBOL_D = 53,                         /* D  */
  YYSYMBOL_el = 54,                        /* el  */
  YYSYMBOL_Arrayelements = 55,             /* Arrayelements  */
  YYSYMBOL_B = 56,                         /* B  */
  YYSYMBOL_Update = 57,                    /* Update  */
  YYSYMBOL_M = 58,                         /* M  */
  YYSYMBOL_COND = 59,                      /* COND  */
  YYSYMBOL_ForInit = 60,                   /* ForInit  */
  YYSYMBOL_AssignExpr = 61,                /* AssignExpr  */
  YYSYMBOL_E = 62,                         /* E  */
  YYSYMBOL_REL = 63,                       /* REL  */
  YYSYMBOL_LOG = 64,                       /* LOG  */
  YYSYMBOL_T = 65,                         /* T  */
  YYSYMBOL_F = 66,                         /* F  */
  YYSYMBOL_VarDeclr = 67,                  /* VarDeclr  */
  YYSYMBOL_ListVar = 68,                   /* ListVar  */
  YYSYMBOL_InitDeclarator = 69,            /* InitDeclarator  */
  YYSYMBOL_Type = 70                       /* Type  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   365

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  79
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  195

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   283


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    43,     2,     2,     2,    46,     2,     2,
      29,    30,    44,    39,    38,    40,     2,    45,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    37,    33,
      42,    36,    41,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    34,     2,    35,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    31,     2,    32,     2,     2,     2,     2,
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
      25,    26,    27,    28
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    26,    26,    27,    30,    31,    32,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      44,    47,    48,    49,    52,    53,    56,    57,    58,    59,
      62,    63,    66,    67,    70,    71,    74,    75,    78,    79,
      82,    83,    84,    87,    88,    89,    90,    91,    92,    95,
      96,    97,    98,    99,   102,   103,   104,   105,   106,   107,
     110,   111,   112,   115,   116,   117,   118,   121,   122,   123,
     124,   127,   130,   131,   134,   135,   138,   139,   140,   141
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "T_ID", "T_NUM",
  "T_INT", "T_FLOAT", "T_CHAR", "T_DOUBLE", "T_IF", "T_WHILE", "T_FOR",
  "T_DO", "T_ELSE", "T_SWITCH", "T_CASE", "T_BREAK", "T_DEFAULT", "T_MAIN",
  "T_LE", "T_GE", "T_NE", "T_EQ", "T_AND", "T_OR", "T_NOT", "T_INC",
  "T_DEC", "T_CHAR_QUOTE", "'('", "')'", "'{'", "'}'", "';'", "'['", "']'",
  "'='", "':'", "','", "'+'", "'-'", "'>'", "'<'", "'!'", "'*'", "'/'",
  "'%'", "$accept", "P", "S", "$@1", "$@2", "swt", "D", "el",
  "Arrayelements", "B", "Update", "M", "COND", "ForInit", "AssignExpr",
  "E", "REL", "LOG", "T", "F", "VarDeclr", "ListVar", "InitDeclarator",
  "Type", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-54)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-19)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      42,   -54,     4,    14,    -1,   -54,    -5,     5,   259,   -54,
      45,   -54,   -54,   -54,   -54,    17,    38,    41,    28,    44,
     -54,   -54,    56,    90,     1,   -54,    99,   231,   109,    29,
     -54,    65,    65,    12,   259,   111,   -54,   -54,   -54,   231,
      26,     2,   -54,   -54,   -54,   -54,   109,   109,   285,    30,
     -54,   105,   322,   -54,    81,   322,    88,    86,   -54,   120,
      92,   -54,   -54,    95,   231,   -54,   128,   102,   231,   130,
     310,   -54,   -54,   -54,   -54,   -54,   -54,   -54,    98,   109,
     109,   -54,   -54,   -54,   109,   109,   109,   109,   109,   112,
     167,   199,    65,   107,   -54,   134,   114,   -54,   113,   143,
     322,   -54,   115,   -54,   -54,   109,    30,    30,    30,    30,
     -54,   -54,   -54,   -54,   259,   -54,   259,   -54,   116,   118,
      -4,    73,   122,   109,   322,   123,   125,    12,    65,   111,
     117,   126,   148,   129,   131,   -54,   146,   231,   133,   -54,
     158,   135,   132,   259,   231,   145,   163,   231,    22,   231,
     -54,   151,   149,   153,   287,   -54,   -54,   150,   152,   155,
     -54,   -54,   159,   188,   259,   -54,   259,   164,   231,   175,
     -54,   163,   162,    65,   -54,   165,   169,   -54,   170,   -54,
     231,   166,   -54,   231,    -4,   -54,   181,   -54,   -54,   259,
     182,   203,    23,   231,   -54
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     3,     0,     0,     0,     1,     0,     0,     0,    19,
       0,    76,    77,    78,    79,     0,     0,     0,     0,     0,
      36,    37,     0,     0,     0,     4,     0,     0,     0,     0,
      45,     0,     0,    42,     0,     0,     2,    46,     6,     0,
      74,     0,    72,    20,    68,    69,     0,     0,     0,    53,
      66,     0,    43,    39,     0,    38,     0,     0,    41,     0,
       0,    24,    25,     0,     0,     5,     0,     0,     0,     0,
       0,    70,    56,    57,    58,    59,    60,    61,     0,     0,
       0,    54,    55,    62,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    74,    40,     0,     0,     7,     0,     0,
      75,    71,    74,    73,    67,     0,    49,    50,    51,    52,
      63,    64,    65,    48,     0,     9,     0,    12,     0,     0,
      23,    33,     0,     0,    44,     0,     0,    35,     0,     0,
       0,     0,     0,     0,     0,    47,    27,     0,     0,    34,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      11,     0,     0,     0,     0,    22,    17,    33,    31,     0,
      15,    29,     0,     0,     0,     8,     0,     0,     0,     0,
      32,     0,     0,     0,    28,     0,     0,    13,     0,    30,
       0,     0,    26,     0,    23,    16,     0,    14,    21,     0,
       0,    27,     0,     0,    10
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -54,   -54,   -27,   -54,   -54,    33,    89,    31,    48,    63,
     -54,    -2,   -31,   -54,   -28,   -25,   -54,   -54,    16,   -38,
     -54,   -54,   -53,   -23
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     3,    22,    64,    27,   131,    63,   149,   159,   134,
     138,    23,    54,    57,    24,    55,    84,    85,    49,    50,
      25,    41,    42,    26
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      43,    56,    38,    48,    52,    58,    94,    60,    30,    71,
      59,   129,    65,   130,     5,    10,   103,    11,    12,    13,
      14,    70,     4,   161,   161,     7,    47,    47,     6,    47,
      47,   162,    44,    45,    39,    68,     8,    97,    20,    21,
      69,   101,   100,     1,    47,    47,    31,     2,   110,   111,
     112,   163,   163,   164,   164,    20,    21,    51,    46,    34,
      66,   118,    67,   115,   117,    47,    53,    32,    44,    45,
      33,    20,    21,    35,    86,    87,    88,    47,    47,    28,
     124,    29,    47,    47,    47,    47,    47,   125,    36,   126,
      47,    20,    21,    37,    46,   106,   107,   141,   100,   139,
     108,   109,    40,    47,   140,    44,    45,   132,    89,   133,
     150,    90,    44,    45,    61,    62,   155,   156,    91,    92,
     160,    47,   165,    93,    95,    96,    47,   169,    20,    21,
      99,    46,    98,   102,   105,    20,    21,   175,    46,   176,
     113,   177,   181,    67,   119,   120,   122,   128,   121,   127,
     135,   123,   145,   185,   143,   136,   187,   137,   144,   148,
     146,   152,   190,   151,   147,   153,   194,   158,     9,   154,
      10,    47,    11,    12,    13,    14,    15,    16,    17,    18,
     157,    19,   166,   -18,   132,   167,   168,   172,   173,   174,
     171,   178,    99,    20,    21,   180,   186,   182,   114,   -18,
       9,   183,    10,   184,    11,    12,    13,    14,    15,    16,
      17,    18,   189,    19,   191,   -18,   192,   188,   142,   179,
     170,     0,   193,     0,     0,    20,    21,     0,     0,     0,
     116,   -18,     9,     0,    10,     0,    11,    12,    13,    14,
      15,    16,    17,    18,     0,    19,     0,   -18,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    20,    21,     0,
       9,     0,    10,   -18,    11,    12,    13,    14,    15,    16,
      17,    18,     0,    19,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    20,    21,     0,     9,     0,
      10,   -18,    11,    12,    13,    14,    15,    16,    17,    18,
       0,    19,     0,   -18,    72,    73,    74,    75,    76,    77,
       0,     0,     0,    20,    21,     0,     0,     0,     0,     0,
      78,     0,     0,     0,    79,    80,    81,    82,    83,    72,
      73,    74,    75,    76,    77,     0,     0,     0,     0,     0,
     104,    72,    73,    74,    75,    76,    77,     0,     0,    79,
      80,    81,    82,    83,     0,     0,     0,     0,     0,     0,
       0,    79,    80,    81,    82,    83
};

static const yytype_int16 yycheck[] =
{
      27,    32,     1,    28,    29,    33,    59,    34,    10,    47,
      33,    15,    39,    17,     0,     3,    69,     5,     6,     7,
       8,    46,    18,     1,     1,    30,    28,    29,    29,    31,
      32,     9,     3,     4,    33,    33,    31,    64,    26,    27,
      38,    68,    67,     1,    46,    47,    29,     5,    86,    87,
      88,    29,    29,    31,    31,    26,    27,    28,    29,    31,
      34,    92,    36,    90,    91,    67,     1,    29,     3,     4,
      29,    26,    27,    29,    44,    45,    46,    79,    80,    34,
     105,    36,    84,    85,    86,    87,    88,   114,    32,   116,
      92,    26,    27,     3,    29,    79,    80,   128,   123,   127,
      84,    85,     3,   105,   127,     3,     4,    34,     3,    36,
     137,    30,     3,     4,     3,     4,   143,   144,    30,    33,
     147,   123,   149,     3,    32,    30,   128,   154,    26,    27,
      28,    29,     4,     3,    36,    26,    27,   164,    29,   166,
      28,   168,   173,    36,    10,    31,     3,    29,    35,    33,
      28,    36,     4,   180,    37,    32,   183,    32,    32,    13,
      31,     3,   189,    30,    33,    30,   193,     4,     1,    37,
       3,   173,     5,     6,     7,     8,     9,    10,    11,    12,
      35,    14,    31,    16,    34,    36,    33,    32,    29,     1,
      38,    16,    28,    26,    27,    33,    30,    32,    31,    32,
       1,    32,     3,    33,     5,     6,     7,     8,     9,    10,
      11,    12,    31,    14,    32,    16,    13,   184,   129,   171,
     157,    -1,   191,    -1,    -1,    26,    27,    -1,    -1,    -1,
      31,    32,     1,    -1,     3,    -1,     5,     6,     7,     8,
       9,    10,    11,    12,    -1,    14,    -1,    16,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,    27,    -1,
       1,    -1,     3,    32,     5,     6,     7,     8,     9,    10,
      11,    12,    -1,    14,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    26,    27,    -1,     1,    -1,
       3,    32,     5,     6,     7,     8,     9,    10,    11,    12,
      -1,    14,    -1,    16,    19,    20,    21,    22,    23,    24,
      -1,    -1,    -1,    26,    27,    -1,    -1,    -1,    -1,    -1,
      35,    -1,    -1,    -1,    39,    40,    41,    42,    43,    19,
      20,    21,    22,    23,    24,    -1,    -1,    -1,    -1,    -1,
      30,    19,    20,    21,    22,    23,    24,    -1,    -1,    39,
      40,    41,    42,    43,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    39,    40,    41,    42,    43
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     5,    48,    18,     0,    29,    30,    31,     1,
       3,     5,     6,     7,     8,     9,    10,    11,    12,    14,
      26,    27,    49,    58,    61,    67,    70,    51,    34,    36,
      58,    29,    29,    29,    31,    29,    32,     3,     1,    33,
       3,    68,    69,    49,     3,     4,    29,    58,    62,    65,
      66,    28,    62,     1,    59,    62,    59,    60,    61,    70,
      49,     3,     4,    53,    50,    49,    34,    36,    33,    38,
      62,    66,    19,    20,    21,    22,    23,    24,    35,    39,
      40,    41,    42,    43,    63,    64,    44,    45,    46,     3,
      30,    30,    33,     3,    69,    32,    30,    49,     4,    28,
      62,    49,     3,    69,    30,    36,    65,    65,    65,    65,
      66,    66,    66,    28,    31,    49,    31,    49,    59,    10,
      31,    35,     3,    36,    62,    49,    49,    33,    29,    15,
      17,    52,    34,    36,    56,    28,    32,    32,    57,    61,
      70,    59,    53,    37,    32,     4,    31,    33,    13,    54,
      49,    30,     3,    30,    37,    49,    49,    35,     4,    55,
      49,     1,     9,    29,    31,    49,    31,    36,    33,    49,
      56,    38,    32,    29,     1,    49,    49,    49,    16,    55,
      33,    59,    32,    32,    33,    49,    30,    49,    52,    31,
      49,    32,    13,    54,    49
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    47,    48,    48,    49,    49,    50,    49,    49,    49,
      49,    49,    49,    49,    49,    49,    49,    49,    49,    51,
      49,    52,    52,    52,    53,    53,    54,    54,    54,    54,
      55,    55,    56,    56,    57,    57,    58,    58,    59,    59,
      60,    60,    60,    61,    61,    61,    61,    61,    61,    62,
      62,    62,    62,    62,    63,    63,    63,    63,    63,    63,
      64,    64,    64,    65,    65,    65,    65,    66,    66,    66,
      66,    67,    68,    68,    69,    69,    70,    70,    70,    70
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     7,     1,     1,     3,     0,     4,     9,     5,
      17,     8,     5,    10,    12,     8,    11,     8,     0,     0,
       3,     7,     3,     0,     1,     1,     4,     0,     3,     2,
       3,     1,     4,     0,     1,     0,     1,     1,     1,     1,
       2,     1,     0,     3,     6,     2,     2,     6,     5,     3,
       3,     3,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     3,     3,     1,     3,     1,     1,
       2,     4,     1,     3,     1,     3,     1,     1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 3: /* P: error  */
#line 27 "parser.y"
          { has_errors = 1; skip_to_sync(); yyerrok; if (yylex() == 0) YYABORT; }
#line 1399 "y.tab.c"
    break;

  case 6: /* $@1: %empty  */
#line 32 "parser.y"
                     { has_errors = 1; printf("Error: missing semicolon, line number: %d, token: %s\n", yylineno, yytext); skip_to_sync(); yyerrok; if (yylex() == 0) YYABORT; }
#line 1405 "y.tab.c"
    break;

  case 19: /* $@2: %empty  */
#line 44 "parser.y"
          { has_errors = 1; printf("Error: syntax error, line number: %d, token: %s\n", yylineno, yytext); skip_to_sync(); yyerrok; if (yylex() == 0) YYABORT; }
#line 1411 "y.tab.c"
    break;

  case 28: /* el: T_ELSE '(' error  */
#line 58 "parser.y"
                      { has_errors = 1; printf("Error: syntax error, line number: %d, token: else\n", yylineno); skip_to_sync(); yyerrok; }
#line 1417 "y.tab.c"
    break;

  case 29: /* el: T_ELSE error  */
#line 59 "parser.y"
                  { has_errors = 1; printf("Error: dangling else, line number: %d, token: else\n", yylineno); skip_to_sync(); yyerrok; }
#line 1423 "y.tab.c"
    break;

  case 39: /* COND: error  */
#line 79 "parser.y"
             { has_errors = 1; printf("Error: syntax error, line number: %d, token: %s\n", yylineno, yytext); skip_to_sync(); yyerrok; if (yylex() == 0) YYABORT; }
#line 1429 "y.tab.c"
    break;


#line 1433 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 144 "parser.y"


void yyerror(char *s) {
    if (strcmp(s, "Unrecognized token") == 0) {
        printf("Error: Unrecognized token, line number: %d, token: %s\n", yylineno, yytext);
    }
}

int skip_to_sync(void) {
    int c;
    int brace_count = 0;
    while ((c = yylex()) != 0) {
        if (c == '{') {
            brace_count++;
        } else if (c == '}') {
            brace_count--;
            if (brace_count < 0) {
                printf("Error: unmatched closing brace, line number: %d, token: %s\n", yylineno, yytext);
                has_errors = 1;
                return c;
            }
        } else if (c == ';' && brace_count == 0) {
            return c;
        } else if (c == ':' && brace_count == 0) {
            printf("Error: Unrecognized token, line number: %d, token: %s\n", yylineno, yytext);
            has_errors = 1;
            return c;
        } else if (c == T_ELSE && brace_count == 0) {
            return c;
        } else if (c == T_IF && brace_count == 0) {
            return c;
        } else if (c == T_WHILE && brace_count == 0) {
            return c;
        }
    }
    if (brace_count > 0) {
        printf("Error: %d unmatched opening brace(s), line number: %d\n", brace_count, yylineno);
        has_errors = 1;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    FILE *fp;
    has_errors = 0;
    if (argc > 1) {
        fp = fopen(argv[1], "r");
        if (!fp) {
            perror("Error opening input file");
            exit(1);
        }
        yyin = fp;
    }
    yylineno = 1;
    column = 1;
    if (!yyparse() && !has_errors)
        printf("Valid syntax\n");
    else
        printf("Parsing failed.\n");
    if (argc > 1)
        fclose(fp);
    return 0;
}
