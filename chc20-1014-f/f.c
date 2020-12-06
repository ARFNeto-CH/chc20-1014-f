#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int y[4];

}   Pacote;

void test(int testt[]);
void test_2(int* testt);
void test_3(int(*)[]);
void test_st(Pacote  pct);
void test_st2(Pacote* pct);

int main(void)
{
	int  y[] = { 1,2,3,4 };
	int  z[] = { 5,6,7,8 };

	printf("y antes %4i %4i %4i %4i Endereco de y: %p \n",
		y[0], y[1], y[2], y[3],
		y);
	printf("z antes %4i %4i %4i %4i Endereco de z: %p\n",
		z[0], z[1], z[2], z[3],
		z);

	printf("\nchamando test() com vetor y\n");
	test(y);
	printf("y em main() depois de test() %4i %4i %4i %4i Endereco de y: %p \n",
		y[0], y[1], y[2], y[3],
		y);

	printf("\nchamando test() com vetor z\n");
	test(z);

	printf("\ny depois %4i %4i %4i %4i\n", y[0], y[1], y[2], y[3]);
	printf("z depois %4i %4i %4i %4i\n", z[0], z[1], z[2], z[3]);

	// chamando usando o ponteiro
	printf("\nchamando test_2() (usando ponteiro) com vetor z\n");
	test_2(z);

	// chamando usando o ponteiro com int (*)[]
	printf("\nchamando test_3() (usando int (*)[]) com vetor z\n");
	printf("z antes %4i %4i %4i %4i Endereco de z: %p \n",
		z[0], z[1], z[2], z[3],
		z);
	test_3(&z);

	Pacote p;
	p.y[0] = 9;
	p.y[1] = 10;
	p.y[2] = 11;
	p.y[3] = 12;

	// passagem por valor

	printf("\nvetor 'p' na estrutura antes\t\
 %4i %4i %4i %4i. Endereco: %p\n",
		p.y[0], p.y[1], p.y[2], p.y[3],
		&p);
	test_st(p);
	printf("vetor na estrutura em main() no retorno\t\
 %4i %4i %4i %4i\n", p.y[0], p.y[1], p.y[2], p.y[3]);

	printf("\nPassando afinal a estrutura por referencia\n");
	test_st2(&p);
	printf("vetor na estrutura em main() no retorno\t\
 %4i %4i %4i %4i\n", p.y[0], p.y[1], p.y[2], p.y[3]);

	return 0;
}

void test(int testt[])
{
	printf("Vetor 'testt' entrando em test():\t%4i %4i %4i %4i Endereco de testt: %p\n",
		testt[0], testt[1], testt[2], testt[3],
		testt);

	testt[0] = 20;
	testt[1] = 21;
	//testt = (int[]){ -1, -2, -3, -4, -5, -6, -7, -8 };
	testt[2] = 22;
	testt[3] = 23;

	//int outro = 2;
	//testt = &outro;
	//*testt = 2222;
//	printf("Vetor 'testt' saindo   de test():\t\
//%4i %4i %4i %4i %4i %4i %4i %4i\n",
//testt[0], testt[1], testt[2], testt[3],
//testt[4], testt[5], testt[6], testt[7]);
//	printf("Endereco de testt: %p\n", testt);

	printf("Vetor 'testt' saindo   de test():\t\
%4i %4i %4i %4i\n",
testt[0], testt[1], testt[2], testt[3]);

}

void test_2(int* testt)
{
	printf("Vetor 'testt' entrando em test_2():\t%4i %4i %4i %4i Endereco de testt: %p\n",
		testt[0], testt[1], testt[2], testt[3],
		testt);
	testt[0] = -20;
	testt[1] = -19;
	testt[2] = -18;
	testt[3] = -17;
	int outro = 0;
	//testt = &outro; // aqui daria erro: testt nao pode apontar para outra coisa
	printf("Vetor 'testt' dentro  de  test_2():\t%4i %4i %4i %4i\n",
		testt[0], testt[1], testt[2], testt[3]);
}

void test_3(int(*testt)[])
{
	printf("Vetor 'testt' entrando em test_3():\t%4i %4i %4i %4i Endereco de testt: %p\n",
		(*testt)[0], (*testt)[1], (*testt)[2], (*testt)[3],
		testt);
	(*testt)[0] = 1;
	(*testt)[3] = 2;
	(*testt)[0] = 3;
	(*testt)[3] = 4;
	int outro = 0;
	//testt = &outro; // aqui daria erro: testt nao pode apontar para outra coisa
	printf("Vetor 'testt'  saindo  de test_3():\t%4i %4i %4i %4i Endereco de testt: %p\n",
		(*testt)[0],
		(*testt)[1],
		(*testt)[2],
		(*testt)[3],
		testt);
};

void test_st(Pacote pct)
{
	printf("(passagem por valor)\n\
vetor 'pct' entrando em test_st():\t\
 %4i %4i %4i %4i Endereco: %p\n",
		pct.y[0], pct.y[1],
		pct.y[2], pct.y[3],
		&pct);
	pct.y[0] = 15;
	pct.y[1] = 16;
	pct.y[2] = 17;
	pct.y[3] = 18;
	printf("\
vetor 'pct'  saindo de  test_st():\t\
 %4i %4i %4i %4i Endereco: %p\n",
		pct.y[0], pct.y[1],
		pct.y[2], pct.y[3],
		&pct);
};

void test_st2(Pacote* pct)
{
	printf("(passagem por referencia)\n\
vetor 'pct' entrando em test_st2():\t\
 %4i %4i %4i %4i Endereco: %p\n",
		pct->y[0], pct->y[1],
		pct->y[2], pct->y[3],
		pct);
	pct->y[0] = 40;
	pct->y[1] = 41;
	pct->y[2] = 42;
	pct->y[3] = 43;
	printf("\
vetor 'pct' entrando em test_st2():\t\
 %4i %4i %4i %4i\n",
		pct->y[0], pct->y[1],
		pct->y[2], pct->y[3]);
};

// fim