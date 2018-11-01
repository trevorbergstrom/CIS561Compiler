// A Bison parser, made by GNU Bison 3.1.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.


// First part of user declarations.

#line 37 "quack.tab.cxx" // lalr1.cc:407

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "quack.tab.hxx"

// User implementation prologue.

#line 51 "quack.tab.cxx" // lalr1.cc:415
// Unqualified %code blocks.
#line 19 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:416

	#include "lex.yy.h"
	#undef yylex
	#define yylex lexer.yylex
	void dump(AST::ASTNode* n);

#line 60 "quack.tab.cxx" // lalr1.cc:416


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (/*CONSTCOND*/ false)
# endif


// Suppress unused-variable warnings by "using" E.
#define YYUSE(E) ((void) (E))

// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)


namespace yy {
#line 155 "quack.tab.cxx" // lalr1.cc:491

  /// Build a parser object.
  parser::parser (yy::Lexer& lexer_yyarg, AST::ASTNode** root_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      lexer (lexer_yyarg),
      root (root_yyarg)
  {}

  parser::~parser ()
  {}


  /*---------------.
  | Symbol types.  |
  `---------------*/

  parser::syntax_error::syntax_error (const location_type& l, const std::string& m)
    : std::runtime_error (m)
    , location (l)
  {}

  // basic_symbol.
  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol ()
    : value ()
    , location ()
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (const basic_symbol& other)
    : Base (other)
    , value (other.value)
    , location (other.location)
  {
  }

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const semantic_type& v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}


  /// Constructor for valueless symbols.
  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const location_type& l)
    : Base (t)
    , value ()
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::~basic_symbol ()
  {
    clear ();
  }

  template <typename Base>
  void
  parser::basic_symbol<Base>::clear ()
  {
    Base::clear ();
  }

  template <typename Base>
  bool
  parser::basic_symbol<Base>::empty () const
  {
    return Base::type_get () == empty_symbol;
  }

  template <typename Base>
  void
  parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    value = s.value;
    location = s.location;
  }

  // by_type.
  parser::by_type::by_type ()
    : type (empty_symbol)
  {}

  parser::by_type::by_type (const by_type& other)
    : type (other.type)
  {}

  parser::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  void
  parser::by_type::clear ()
  {
    type = empty_symbol;
  }

  void
  parser::by_type::move (by_type& that)
  {
    type = that.type;
    that.clear ();
  }

  int
  parser::by_type::type_get () const
  {
    return type;
  }


  // by_state.
  parser::by_state::by_state ()
    : state (empty_state)
  {}

  parser::by_state::by_state (const by_state& other)
    : state (other.state)
  {}

  void
  parser::by_state::clear ()
  {
    state = empty_state;
  }

  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  parser::by_state::by_state (state_type s)
    : state (s)
  {}

  parser::symbol_number_type
  parser::by_state::type_get () const
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[state];
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (const stack_symbol_type& that)
    : super_type (that.state, that.location)
  {
    value = that.value;
  }

  parser::stack_symbol_type::stack_symbol_type (state_type s, symbol_type& that)
    : super_type (s, that.value, that.location)
  {
    // that is emptied.
    that.type = empty_symbol;
  }

  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    location = that.location;
    return *this;
  }


  template <typename Base>
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);

    // User destructor.
    YYUSE (yysym.type_get ());
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " ("
        << yysym.location << ": ";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  void
  parser::yypush_ (const char* m, state_type s, symbol_type& sym)
  {
    stack_symbol_type t (s, sym);
    yypush_ (m, t);
  }

  void
  parser::yypush_ (const char* m, stack_symbol_type& s)
  {
    if (m)
      YY_SYMBOL_PRINT (m, s);
    yystack_.push (s);
  }

  void
  parser::yypop_ (unsigned n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::parse ()
  {
    // State.
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, yyla);

    // A new symbol was pushed on the stack.
  yynewstate:
    YYCDEBUG << "Entering state " << yystack_[0].state << '\n';

    // Accept?
    if (yystack_[0].state == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    // Backup.
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            yyla.type = yytranslate_ (yylex (&yyla.value, &yyla.location));
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      goto yydefault;

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", yyn, yyla);
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* If YYLEN is nonzero, implement the default value of the
         action: '$$ = $1'.  Otherwise, use the top of the stack.

         Otherwise, the following line sets YYLHS.VALUE to garbage.
         This behavior is undocumented and Bison users should not rely
         upon it.  */
      if (yylen)
        yylhs.value = yystack_[yylen - 1].value;
      else
        yylhs.value = yystack_[0].value;

      // Default location.
      {
        slice<stack_symbol_type, stack_type> slice (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, slice, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2:
#line 74 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
    {
}
#line 580 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 3:
#line 78 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
    {
	}
#line 587 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 4:
#line 80 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
    {
	}
#line 594 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 5:
#line 84 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
    {
	}
#line 601 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 6:
#line 86 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
    {
	}
#line 608 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 7:
#line 90 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
    {
	}
#line 615 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 8:
#line 94 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
    {
	}
#line 622 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 9:
#line 96 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
    {
	}
#line 629 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 10:
#line 100 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
    {
	}
#line 636 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 11:
#line 104 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
    {
	}
#line 643 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 12:
#line 106 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
    {
	}
#line 650 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 13:
#line 110 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
    {
	}
#line 657 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 14:
#line 114 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
    {
	}
#line 664 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 15:
#line 116 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
    {
	}
#line 671 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 16:
#line 120 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
    {
	}
#line 678 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 17:
#line 122 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
    {
	}
#line 685 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 18:
#line 124 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
    {
	}
#line 692 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 19:
#line 128 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
    {
	}
#line 699 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 20:
#line 134 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
    {
	}
#line 706 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 21:
#line 137 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
    {
	}
#line 713 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 22:
#line 139 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
    {
	}
#line 720 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 23:
#line 142 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
    {
	}
#line 727 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 24:
#line 145 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
    {
	}
#line 734 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 25:
#line 147 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
    {
	}
#line 741 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 26:
#line 151 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
    {
	}
#line 748 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 27:
#line 155 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
    {
	}
#line 755 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 28:
#line 159 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
    {
	}
#line 762 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 29:
#line 161 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
    {
	}
#line 769 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 30:
#line 163 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
    {
	}
#line 776 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 31:
#line 167 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
    {
	}
#line 783 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 32:
#line 171 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
    {
	}
#line 790 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 33:
#line 175 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
    {
	}
#line 797 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 34:
#line 179 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
    {
	}
#line 804 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 35:
#line 183 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
    {
	}
#line 811 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 36:
#line 185 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
    {
	}
#line 818 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 37:
#line 189 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
    {
	}
#line 825 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 38:
#line 191 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
    {
	}
#line 832 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 39:
#line 195 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
    {
	}
#line 839 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 40:
#line 197 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
    {
	}
#line 846 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 41:
#line 199 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
    {
	}
#line 853 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 42:
#line 201 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
    {
	}
#line 860 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 43:
#line 203 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
    {
	}
#line 867 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 44:
#line 205 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
    {
	}
#line 874 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 45:
#line 207 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
    {
	}
#line 881 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 46:
#line 209 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
    {
	}
#line 888 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 47:
#line 211 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
    {
	}
#line 895 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 48:
#line 215 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
    {
	}
#line 902 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 49:
#line 217 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
    {
	}
#line 909 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 50:
#line 219 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
    {
	}
#line 916 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 51:
#line 221 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
    {
	}
#line 923 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 52:
#line 223 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
    {
	}
#line 930 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 53:
#line 225 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
    {
	}
#line 937 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 54:
#line 227 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
    {
	}
#line 944 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 55:
#line 229 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
    {
	}
#line 951 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 56:
#line 233 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
    {
	}
#line 958 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 57:
#line 235 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
    {
	}
#line 965 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 58:
#line 239 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
    {
	}
#line 972 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 59:
#line 241 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
    {
	}
#line 979 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 60:
#line 243 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
    {
	}
#line 986 "quack.tab.cxx" // lalr1.cc:870
    break;


#line 990 "quack.tab.cxx" // lalr1.cc:870
            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, yylhs);
    }
    goto yynewstate;

  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yyla.location, yysyntax_error_ (yystack_[0].state, yyla));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;
    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yyterror_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yyerror_range[1].location = yystack_[0].location;
          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = yyn;
      yypush_ ("Shifting", error_token);
    }
    goto yynewstate;

    // Accept.
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    // Abort.
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (state_type, const symbol_type&) const
  {
    return YY_("syntax error");
  }


  const signed char parser::yypact_ninf_ = -25;

  const signed char parser::yytable_ninf_ = -1;

  const short
  parser::yypact_[] =
  {
     -25,    22,    17,   -25,    35,    87,   -25,    19,    36,    38,
     -25,   -25,    15,    15,    15,    15,    15,    15,   -25,   -25,
      28,   101,   -25,   -25,    64,    15,    34,   -25,   211,   164,
     180,   180,    47,   196,    67,    15,    15,    15,    15,    15,
      15,    15,    15,    15,    15,    15,    15,    15,    72,   -25,
      87,    18,   -18,   -25,   211,   -17,   -25,    76,   -25,   -25,
     -25,   -25,    48,   122,    31,    31,    31,    31,    31,    31,
      79,    79,    47,    47,    54,    54,    55,     6,    81,    78,
      64,   -25,    15,    56,    62,    37,    -3,    15,   -25,    15,
      84,   -25,   -25,   -25,    96,   -25,   211,    97,   -25,   -25,
      15,    77,   -25,   -25,   143,   -12,    80,   -25,   -25,   180,
     -25,   -25,   -25,    64,    87,   -25,    30,    82,   107,    77,
     -25,   -25
  };

  const unsigned char
  parser::yydefact_[] =
  {
       3,     0,     5,     1,     0,     2,     4,     0,     0,    37,
      39,    40,    35,     0,     0,     0,     0,     0,     6,    32,
      41,     0,     5,     7,    16,    58,     0,    41,    36,     0,
       0,     0,    46,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    30,
      11,     0,     0,    18,    60,     0,    31,     0,     5,    21,
      27,    47,     0,     0,    53,    54,    55,    48,    49,    50,
      51,    52,    42,    43,    45,    44,    38,     0,     0,     9,
       0,    57,     0,     0,     0,     0,    24,     0,    29,    58,
       0,    10,    12,    19,     0,    17,    59,     0,    33,    26,
       0,     0,    22,    20,     0,     0,     0,     8,     5,     0,
      25,    28,    56,    16,    34,    23,     0,    14,     0,     0,
      15,    13
  };

  const signed char
  parser::yypgoto_[] =
  {
     -25,   -25,   -25,   -14,   -25,   -25,   -25,   -25,   -25,   -25,
      -1,    33,   -25,   -25,   -25,   -25,   -24,   -25,   -25,   -25,
      -5,   -11,    40
  };

  const signed char
  parser::yydefgoto_[] =
  {
      -1,     1,     2,     5,     6,     7,    23,    77,    92,   119,
      52,    53,    18,    86,   102,   103,    59,    19,    84,    26,
      27,    21,    55
  };

  const unsigned char
  parser::yytable_[] =
  {
      20,    28,    29,    30,    31,    32,    33,    60,    50,   100,
     101,    79,    81,    90,    54,    80,    82,   112,     9,    10,
      11,    82,     3,     4,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    91,     8,    16,
       9,    10,    11,    17,    85,    20,    12,    13,    14,    22,
      78,    15,    42,    43,    44,    45,    46,    47,    48,   117,
      34,    16,    35,    80,    24,    17,    25,    51,    99,    56,
      62,    96,    46,    47,    48,    76,   104,   110,    54,    83,
      20,    48,    87,    89,    93,   115,    94,   106,    97,   109,
       9,    10,    11,    98,   114,   121,    12,    13,    14,   107,
     108,    15,    44,    45,    46,    47,    48,    58,   113,    20,
     120,    16,   116,    95,   118,    17,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,   105,
       0,     0,     0,     0,     0,     0,    49,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
       0,     0,     0,     0,     0,     0,     0,    88,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,     0,     0,     0,     0,     0,     0,     0,   111,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,     0,     0,    57,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,     0,     0,
      58,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,     0,    61,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48
  };

  const signed char
  parser::yycheck_[] =
  {
       5,    12,    13,    14,    15,    16,    17,    31,    22,    12,
      13,    29,    29,     7,    25,    33,    33,    29,     3,     4,
       5,    33,     0,     6,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    31,     3,    24,
       3,     4,     5,    28,    58,    50,     9,    10,    11,    30,
      32,    14,    21,    22,    23,    24,    25,    26,    27,    29,
      32,    24,    34,    33,    28,    28,    28,     3,    31,    35,
       3,    82,    25,    26,    27,     3,    87,   101,    89,     3,
      85,    27,    34,    28,     3,   109,     8,     3,    32,   100,
       3,     4,     5,    31,   108,   119,     9,    10,    11,     3,
       3,    14,    23,    24,    25,    26,    27,    30,    28,   114,
       3,    24,   113,    80,    32,    28,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    89,
      -1,    -1,    -1,    -1,    -1,    -1,    35,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    -1,    -1,    30,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    -1,    -1,
      30,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    -1,    29,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,    37,    38,     0,     6,    39,    40,    41,     3,     3,
       4,     5,     9,    10,    11,    14,    24,    28,    48,    53,
      56,    57,    30,    42,    28,    28,    55,    56,    57,    57,
      57,    57,    57,    57,    32,    34,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    35,
      39,     3,    46,    47,    57,    58,    35,    30,    30,    52,
      52,    29,     3,    57,    57,    57,    57,    57,    57,    57,
      57,    57,    57,    57,    57,    57,     3,    43,    32,    29,
      33,    29,    33,     3,    54,    39,    49,    34,    35,    28,
       7,    31,    44,     3,     8,    47,    57,    32,    31,    31,
      12,    13,    50,    51,    57,    58,     3,     3,     3,    57,
      52,    35,    29,    28,    39,    52,    46,    29,    32,    45,
       3,    52
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,    36,    37,    38,    38,    39,    39,    40,    41,    41,
      42,    43,    43,    44,    45,    45,    46,    46,    46,    47,
      48,    49,    49,    50,    51,    51,    52,    48,    48,    48,
      48,    48,    48,    53,    54,    55,    55,    56,    56,    57,
      57,    57,    57,    57,    57,    57,    57,    57,    57,    57,
      57,    57,    57,    57,    57,    57,    57,    57,    58,    58,
      58
  };

  const unsigned char
  parser::yyr2_[] =
  {
       0,     2,     2,     0,     2,     0,     2,     2,     7,     5,
       4,     0,     2,     7,     0,     2,     0,     3,     1,     3,
       5,     0,     2,     3,     0,     2,     3,     3,     6,     4,
       2,     3,     1,     5,     4,     0,     1,     1,     3,     1,
       1,     1,     3,     3,     3,     3,     2,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     6,     4,     0,     3,
       1
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "$end", "error", "$undefined", "IDENT", "STR_LIT", "INT_LIT", "CLASS",
  "DEF", "EXTENDS", "RETURN", "TYPECASE", "IF", "ELIF", "ELSE", "WHILE",
  "AND", "OR", "NOT", "EQUALS", "ATMOST", "ATLEAST", "'<'", "'>'", "'+'",
  "'-'", "'/'", "'*'", "'.'", "'('", "')'", "'{'", "'}'", "':'", "','",
  "'='", "';'", "$accept", "program", "classes", "statements", "class",
  "class_signature", "class_body", "methods", "method", "return",
  "formal_args", "formal_arg", "statement", "elifs", "elif", "else",
  "statement_block", "typecase", "type_alt", "ret_r_exp", "l_expr",
  "r_expr", "actual_args", YY_NULLPTR
  };


  const unsigned char
  parser::yyrline_[] =
  {
       0,    74,    74,    78,    80,    84,    86,    90,    94,    96,
     100,   104,   106,   110,   114,   116,   120,   122,   124,   128,
     132,   137,   139,   142,   145,   147,   151,   155,   159,   161,
     163,   167,   171,   175,   179,   183,   185,   189,   191,   195,
     197,   199,   201,   203,   205,   207,   209,   211,   215,   217,
     219,   221,   223,   225,   227,   229,   233,   235,   239,   241,
     243
  };

  // Print the state stack on the debug stream.
  void
  parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << '\n';
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  parser::yy_reduce_print_ (int yyrule)
  {
    unsigned yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  // Symbol number corresponding to token number t.
  parser::token_number_type
  parser::yytranslate_ (int t)
  {
    static
    const token_number_type
    translate_table[] =
    {
     0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      28,    29,    26,    23,    33,    24,    27,    25,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    32,    35,
      21,    34,    22,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    30,     2,    31,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20
    };
    const unsigned user_token_number_max_ = 275;
    const token_number_type undef_token_ = 2;

    if (static_cast<int> (t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }


} // yy
#line 1424 "quack.tab.cxx" // lalr1.cc:1181
#line 246 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:1182

#include "Messages.h"

void yy::parser::error(const location_type& loc, const std::string& msg)
{
  report::error_at(loc, msg);
}

void dump(AST::ASTNode* n) {
    // std::cout << "*** Building: " << n->str() << std::endl;
}
