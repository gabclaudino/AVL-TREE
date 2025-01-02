struct No *cria_No(int chave);

int altura_t(struct No *n);

int FatDeBalanc(struct No * n);

struct No* rot_esq(struct No* x);

struct No* rot_dir(struct No* y);

struct No *insere(struct No* no, int chave);

struct No *remover(struct No* no, int chave);

int maior (int a, int b);

void emordem(struct No *n);