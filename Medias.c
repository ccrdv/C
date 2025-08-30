#include <stdio.h>
#include <locale.h>
#include <windows.h>
float n, n2, m, c;
char s;
int conta(){
	n += n2;

}
int main(){
	SetConsoleOutputCP(65001);
	setlocale(LC_ALL, "pt_BR.UTF-8");
	printf("Calculadora automática de médias:\n");
	ponto:
	printf("Digite a primeira nota:\n");
	scanf("%f", &n);
	printf("Deseja colocar outra nota?: (s/n)\n");
	scanf(" %c", &s);
	if (s != 's' && s != 'n'){
		printf("Por favor, digite apenas 's' ou 'n'\n");

		goto ponto;
	}
	c = 1;
	while (s == 's'){
		printf("Digite a próxima nota:\n");
		scanf("%f", &n2);
		c++;
		conta();
		printf("Deseja colocar outra nota?: (s/n)\n");
		scanf(" %c", &s);
	}
	m = n/c;
	printf("Sua média para as %.0f notas é %.2f.", c, m);
	return 0;
}