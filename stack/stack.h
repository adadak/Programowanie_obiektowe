typedef struct stack tstack;

tstack *init(void);
void close(tstack *s);
int isempty(tstack *s);
int push(tstack *s, int el);
int pop(tstack *s);
