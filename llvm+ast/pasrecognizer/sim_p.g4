// Pascal 文件的最基础文法，以这种形式方便通过 antrl 来生成 ast。
// 没有lexer.g4 和 parser.g4 文件
// 因为只需要把当前这个文件，用idea的antlr4插件，就可以生成src里generated的那些文件！
grammar sim_p;

program
    :program_head program_body SPOT
    ;
program_head
    :PROGRAM ID LEFTPAREN ID (COMMA ID)* RIGHTPAREN SEMICOLON
    ;
program_body
    :(CONST const_de (SEMICOLON const_de)* SEMICOLON|) (VAR var_de (SEMICOLON var_de)* SEMICOLON|)  compound_statement
    ;
const_de
    :ID EQUAL const_variable
    ;
    //var_de (SEMICOLON var_de)*
var_de
    : identifier(COMMA identifier)* COLON type
    ;
identifier
    :ID
    ;
type
    :standrad_type
    |RECORD record_body END
    |ARRAY LBRACK period (COMMA period)* RBRACK OF type
    ;
standrad_type
    :INTEGER
    |REAL
    |BOOLEAN
    |CHAR
    ;
record_body
    :var_de (SEMICOLON var_de)*
    |empty
    ;
period
    :const_variable SPOT SPOT const_variable
    ;
const_variable
    :PLUS ID
    |MINUS ID
    |ID
    |PLUS num
    |MINUS num
    |num
    |LETTER
    ;
//identifier_list
//    :identifier (COMMA identifier)*
//    ;
compound_statement
    :BEGIN statement_list END
    ;
statement_list
    :statement (SEMICOLON statement)*
    ;
statement
    :variable ASSIGNOP expression             #statement1
    |empty                             #statement2
    ;

variable
    :ID (id_varpart)*
    ;
id_varpart
    :LBRACK expression_list RBRACK
    |SPOT ID
    ;


////////////////
expression_list
    :expression (COMMA expression)*
    ;
expression
    :simple_expression relop simple_expression
    |simple_expression
    ;
simple_expression
    :term
    |PLUS term
    |MINUS term
    |simple_expression addop term
    ;
term
    :term mulop factor
    |factor
    ;
factor
    :unsign_const_variable
    |variable
    |ID LEFTPAREN expression_list RIGHTPAREN
    |LEFTPAREN expression RIGHTPAREN
    |NOT factor
    ;
unsign_const_variable
    :ID
    |num
    |LETTER
    ;
/////////////////


num
    :digits (SPOT digits|) (EXPONENT|)
    ;

empty
   ://空
   ;
digits
    :DIGIT+
    ;
mulop
    :STAR
    |DIVIDE
    |DIV
    |MOD
    |AND
    ;
addop
    :PLUS
    |MINUS
    |OR
    ;
relop
    :EQUAL
    |NOTEQUAL
    |LESS
    |LESSEQUAL
    |GREATE
    |GREATEEQUAL
    ;




//
STAR:'*'
    ;
DIVIDE:'/';
NOTEQUAL:'<>';
LESS:'<';
LESSEQUAL:'<=';
GREATE:'>';
GREATEEQUAL:'>=';
//

EXPONENT
    : ('e'|'E') ('+' | '-')? ('0' .. '9') +
    ;

FUNCTION
    :F U N C T I O N
    ;
PROCEDURE
    :P R O C E D U R E
    ;
NOT
    :N O T
    ;
DIV
    :D I V
    ;
MOD
    :M O D
    ;
AND
    :A N D
    ;

DOWNTO
    :D O W N T O
    ;
TO
    :T O
    ;
UNTIL
    :U N T I L
    ;
REPEAT
    :R E P E A T
    ;
FOR
    :F O R
    ;
WHILE
    :W H I L E
    ;
DO
    :D O
    ;
CASE
    :C A S E
    ;
ASSIGNOP
    :':='
    ;
IF
    :I F
    ;
THEN
    :T H E N
    ;

LBRACK
   : '['
   ;
RBRACK
   : ']'
   ;
LEFTPAREN
    :'('
    ;
RIGHTPAREN
    :')'
    ;
INTEGER
    :I N T E G E R
    ;
REAL
    :R E A L
    ;
BOOLEAN
    :B O O L E A N
    ;
CHAR
    :C H A R
    ;
PROGRAM
    :P R O G R A M
    ;
CONST
    :C O N S T
    ;
TYPE
    :T Y P E
    ;
RECORD
    :R E C O R D
    ;
BEGIN
    :B E G I N
    ;
END
    :E N D
    ;
ARRAY
    :A R R A Y
    ;
OF
    :O F
    ;
OR
    :O R
    ;
VAR
    :V A R
    ;
SPOT
    :'.'
    ;
SEMICOLON
    :';'
    ;
COMMA
    :','
    ;
EQUAL
   :'='
   ;
PLUS
   :'+'
   ;
COLON
   :':'
   ;

MINUS
   :'-'
   ;
ELSE
    :E L S E
    ;
LETTER
    :'\''('a' .. 'z' | 'A' .. 'Z')'\''
    ;
DIGIT
    :('0' .. '9')
    ;
ID
    :('a' .. 'z' | 'A' .. 'Z') ('a' .. 'z' | 'A' .. 'Z'|'0' .. '9')*
    ;

WS
   : [ \t\r\n] -> skip
   ;


COMMENT_1
   : '(*' .*? '*)' -> skip
   ;


COMMENT_2
   : '{' .*? '}' -> skip
   ;

fragment A
   : ('a' | 'A')
   ;


fragment B
   : ('b' | 'B')
   ;


fragment C
   : ('c' | 'C')
   ;


fragment D
   : ('d' | 'D')
   ;


fragment E
   : ('e' | 'E')
   ;


fragment F
   : ('f' | 'F')
   ;


fragment G
   : ('g' | 'G')
   ;


fragment H
   : ('h' | 'H')
   ;


fragment I
   : ('i' | 'I')
   ;


fragment J
   : ('j' | 'J')
   ;


fragment K
   : ('k' | 'K')
   ;


fragment L
   : ('l' | 'L')
   ;


fragment M
   : ('m' | 'M')
   ;


fragment N
   : ('n' | 'N')
   ;


fragment O
   : ('o' | 'O')
   ;


fragment P
   : ('p' | 'P')
   ;


fragment Q
   : ('q' | 'Q')
   ;


fragment R
   : ('r' | 'R')
   ;


fragment S
   : ('s' | 'S')
   ;


fragment T
   : ('t' | 'T')
   ;


fragment U
   : ('u' | 'U')
   ;


fragment V
   : ('v' | 'V')
   ;


fragment W
   : ('w' | 'W')
   ;


fragment X
   : ('x' | 'X')
   ;


fragment Y
   : ('y' | 'Y')
   ;


fragment Z
   : ('z' | 'Z')
   ;

//fragment EXPONENT
//   : ('e'|'E') ('+' | '-')? ('0' .. '9') +
//   ;