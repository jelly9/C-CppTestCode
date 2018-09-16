/*  Grammar rules
 *  exp -> term exp_tail
 *  exp_tail -> addop term exp_tail | empty
 *      addpp -> + | -
 *  term -> factor term_tail
 *  term_tail -> mulop factor term_tail | empty
 *      mulop -> * | /
 *  factor -> ( exp  ) | num
 */

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int exp_x();
int exp_tail(int lvalue);
int term();
int term_tail(int lvalue);
int factor();
void next();
void match(char token);

enum E_TOKEN
{
    E_NUM = 0,
};

const char *g_src;
char g_token;  // + - * / (  ) E_NUM
int g_value;   // if g_token is E_NUM, g_value is its value

int exp_x()
{
    int lvalue = term();
    return exp_tail(lvalue);

}

int exp_tail(int lvalue)
{
    int value = 0;
    switch (g_token) {
    case '+':
        match('+');
        value = lvalue + term();
        return exp_tail(value);
    case '-':
        match('-');
        value = lvalue - term();
        return exp_tail(value);
    default:
        return lvalue;

    }

}

int term()
{
    int lvalue = factor();
    return term_tail(lvalue);

}

int term_tail(int lvalue)
{
    int value = 0, tmp = 0;
    switch (g_token) {
    case '*':
        match('*');
        value = lvalue * factor();
        return term_tail(value);
    case '/':
        match('/');
        tmp = factor();
        if (tmp != 0) {
            value = lvalue / tmp;

        } else {
            printf("error divided by 0\n");
            exit(-1);

        }
        return term_tail(value);
    default:
        return lvalue;

    }

}

int factor()
{
    int value = 0;
    if (g_token == '(') {
        match('(');
        value = exp_x();
        match(')');
    } else {
        value = g_value;
        match(E_NUM);

    }
    return value;
}

void match(char token)
{
    if (token != g_token) {
        if (token == E_NUM) {
            printf("expect number, real is %c(ascii %u)\n", g_token, g_token);

        } else {
            printf("expcet %c, real is %c(%u)\n", token, g_token, g_token);

        }
        exit(-1);

    }
    next();

}

void next()
{
    while (*g_src == ' ')
        ++g_src;

    if (*g_src == '+'
        || *g_src == '-'
        || *g_src == '*'
        || *g_src == '/'
        || *g_src == '('
        || *g_src == ')') {
        g_token = *g_src++;

    } else if (isdigit(*g_src)) {
        g_value = 0;
        while(isdigit(*g_src)) {
            g_value = g_value * 10 + (*g_src) - '0';
            ++g_src;

        }
        g_token = (char)E_NUM;

    } else if (*g_src == '\0') {
        return; // expression end

    } else {
        printf("input error: %c", *g_src);
        exit(-1);

    }
}

int main()
{
    const char *test = "1+2+4* 16/ (3-1)";
    int result = 0;
    g_src = test;
    next();
    result = exp_x();
    printf("%s = %d\n", test, result);
    return 0;
}
