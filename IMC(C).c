#include <stdio.h>
int main(){
	float peso;
	float altura;
	float imc;
	printf("Informe seu peso, em KG:");
	scanf("%f", &peso);
	printf("Agora, informe sua altura, em metros:");
	scanf("%f", &altura);
	imc = peso/(altura * altura);
	
	if (imc <= 18.5)
    {
        printf ("Seu IMC \202 de: %.2f", imc);
        printf("Est\240 na classifica\207\306o de: Abaixo do peso");
    }
	else if(imc <= 24.9)
    {
        printf("Seu IMC \202 de:  %.2f",imc);
        printf("Est\240 na classifica\207\306o de: Peso normal");
    }
    else if(imc >= 25.0 && imc <= 29.9)
    {
        printf("Seu IMC \202 de: %.2f",imc);
        printf("Est\240 na classifica\207\306o de: Sobrepeso");
    }
	else if(imc >= 30.0 && imc <= 34.9)
	{
   		printf("Seu IMC \202 de: %.2f",imc);   
   		printf("Est\240 na classifica\207\306o de: Obesidade grau 1");
	}
	else if(imc >= 35.0 && imc <= 39.9)
	{
		printf("Seu IMC \202 de: %.2f",imc);   
   		printf("Est\240 na classifica\207\306o de: Obesidade grau 2");
	}
	else{
	
	printf("Seu IMC \202 de: %.2f",imc);   
   	printf("Est\240 na classifica\207\306o de: Obesidade grau 3");
	}
	return 0;
}