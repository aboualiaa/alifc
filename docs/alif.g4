grammar alif;

file
    : (stmt)* EOF
    ;

stmt
    : include_stmt
    | program_stmt
    ;

include_stmt
    : INCLUDE ALIF
    | INCLUDE WEBUI name? STRING
    | INCLUDE WEBUI MAIN STRING
    | INCLUDE UI name? STRING
    ;

program_stmt
    : window_stmt
    | class_stmt
    | func_stmt
    | func_call
    | bool_decl
    | if_stmt
    | var_def
    | var_decl
    | assignment_stmt
    | return_stmt
    | object_def
    | member_access
    ;

window_stmt
    : WIN MAIN program_stmt* ENDWIN
    | WIN name program_stmt* ENDWIN
    ;

class_stmt
    : CLASS name program_stmt* ENDCLASS
    ;

func_stmt
    : (FUNC MAIN) program_stmt* ENDFUN
    | FUNC (return_type)? name LPARENS (var_decl (COMMA var_decl)+)? RPARENS program_stmt* ENDFUN
    ;

return_type
    : C_STRING
    | C_NUMBER
    ;

return_stmt
    : RETURN additiveExpression
    ;

additiveExpression
    : (name | STRING) (PLUS (name | LINE | STRING))*
    ;


multiplicativeExpression
    : (name | STRING) (TIMES (name | LINE | STRING | NUMBER))*
    ;

bool_decl
    : BOOL name logical_op (TRUE | FALSE)
    ;

condition
    : name logical_op (TRUE | FALSE)
    ;

assignment_stmt
    : name EQ name
    | member_access EQ NUMBER
    | name EQ additiveExpression
    | name EQ multiplicativeExpression
    ;

func_call
    : (name | member_access) LPARENS parameter_list? RPARENS
    ;

parameter_list
    : parameter
    | parameter (COMMA parameter)*
    ;

parameter
    : (STRING | NUMBER)
    | func_call
    | name
    | additiveExpression
    ;

member_access
    : name SCOPE name
    ;

if_stmt
    : IF condition program_stmt (ELSE program_stmt)? ENDIF
    ;

var_def
    : PRIVATE? C_NUMBER name EQ NUMBER
    | PRIVATE? C_STRING name EQ STRING
    | PRIVATE? (C_STRING | C_NUMBER) name EQ func_call
    | PRIVATE? (C_STRING | C_NUMBER) name EQ additiveExpression
    ;

object_def
    : OBJECT name EQ func_call
    ;

var_decl
    : C_STRING name
    | C_NUMBER name
    ;

logical_op
    : GT_EQ
    | LT_EQ
    | LT
    | GT
    | EQ
    ;

name
    : IDENTIFIER
    ;

value
    : NUMBER
    | STRING
    | TRUE
    | FALSE
    ;

fragment NEWLINE
    : ( '\r'? '\n' | '\r')
    ;

// Keywords
FUNC : 'دالة';
MAIN : 'رئيسية';
CLASS : 'صنف';
ALIF : 'ألف';
WEBUI : 'واجهة_ويب';
UI : 'واجهة';
WIN: 'نافذة';
IF : 'إذا';
ELSE : 'وإلا';
ENDIF : 'نهاية إذا';
ENDFUN : 'نهاية دالة';
ENDWIN : 'نهاية نافذة';
C_NUMBER : 'عدد';
C_STRING : 'نص';
PRIVATE : 'خاص';
ENDCLASS : 'نهاية صنف';
BOOL : 'منطق';
TRUE : 'صحيح';
FALSE : 'خطأ';
RETURN : 'إرجاع';
LINE : 'سطر';
OBJECT : 'كائن';

// operators
PLUS: '+';
MINUS: '-';
TIMES: '*';
DIVIDED: '/';
LPARENS: '(';
RPARENS: ')';
COMMA: '،';
LBRACE: '{';
RBRACE: '}';
SCOPE: ':';
GT_EQ: '>=';
LT_EQ: '<=';
LT: '<';
GT: '>';
EQ: '=';
INCLUDE: '#';

NUMBER
    : ARABIC_DIGIT+ ((DOT_CHAR | FASILA) ARABIC_DIGIT+)?
    | FOREIGN_DIGIT+ (DOT_CHAR FOREIGN_DIGIT+)?
    ;

// &" is an escaped double quote
STRING
    : '"' (~'"' | '&"')* '"'
    ;

IDENTIFIER
    : ARABIC_LETTER IDENTIFIER_REST*
    ;

IDENTIFIER_REST
    : ARABIC_LETTER | ARABIC_DIGIT | FOREIGN_DIGIT | DOT_CHAR | UNDERSCORE
    ;

// 'ء' to 'ي'
ARABIC_LETTER
    : [\u0621-\u063A] | [\u0640-\u064A]
    ;

// '٠' to '٩'
ARABIC_DIGIT
    : [\u0660-\u0669]
    ;

// '0' to '9'
FOREIGN_DIGIT
    : [0-9]
    ;

// '_'
UNDERSCORE
    : [\u005F]
    ;

// '.'
DOT_CHAR
    : [\u002E]
    ;

// '٫'
FASILA
    : [\u066B]
    ;

COMMENT
    : '\\' (COMMENT | .)*? '/'
    ;
LINE_JOINING
    : '|' ~('\r' | '\n')*? '\r'? '\n'
    ;

fragment SPACES
    : [ \t]+
    ;
SKIPPING
    : (SPACES | COMMENT | LINE_JOINING | NEWLINE ) -> channel(HIDDEN)
    ;