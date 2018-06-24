#include <stdio.h>
#include <math.h>
#include <float.h>
float altura_plat, fp, altura_bola, Xp, X0, Xb1, Xb2, Vb1, Vb2, e, Vap, Vaf, Vp, T, ts, td, Xi;

int main()
{
printf ("Uma plataforma eh capaz de oscilar de 0 a 2 metros acima do chao. Sobre essa plataforma uma bola de propriedades predefinidas eh liberada e pode ou nao quicar. Este programa simula o comportamento desse sistema.\n");
printf ("Entre com a posicao da inicial da plataforma em relacao ao solo, em metros.\n");
scanf ("%f", &altura_plat);
printf ("Entre com a frequencia oscilatoria da plataforma.\n");
scanf ("%f", &fp);
printf ("Entre com a posicao inicial da bola.\n");
scanf ("%f", &altura_bola);
printf ("Entre com o coeficiente de retorno da bola.\n");
scanf("%f", &e);
if ((altura_plat <= 2) && (altura_plat > 1))
{
	Xi = altura_plat - 1;
}
else if ((altura_plat <= 1) && (altura_plat >= 0))
{
	Xi = 1 - altura_plat;
}
else {
	printf("posicao fora dos limites");
}
;
if (altura_bola < altura_plat)
{
	printf("a bola estah fora da plataforma.\n");
}
else 
{
	FILE *arquivo_oscilador;
	arquivo_oscilador = fopen ("arq_oscilador", "w");
	if(arquivo_oscilador == NULL)
	{
     printf("Erro na abertura do arquivo!");
     return 1;
	}
	if (altura_bola == altura_plat)
{
	FILE*arquivo_oscilador;
	arquivo_oscilador = fopen ("arq_oscilador", "w");
	if(arquivo_oscilador == NULL)
	{
     printf("Erro na abertura do arquivo!");
     return 1;
	}
	for (T = 0; T <= 10; T++) {
		Xp = cos((2 * 3.14 * fp * T) + acos(Xi));
		X0 = Xp;
		fprintf (arquivo_oscilador, "%f ","%f ", "%f ", X0, Xp, T);
	}
	fclose(arquivo_oscilador);
} else {
	FILE *arquivo_oscilador;
	arquivo_oscilador = fopen ("arq_oscilador", "w");
	if(arquivo_oscilador == NULL)
	{
     printf("Erro na abertura do arquivo!");
     return 1;
	}
	T = 0;
	do {
		td = 0;
		ts = 0;
		do {		
		Xp = cos((2 * 3.14 * fp * T) + acos(Xi));
		Vp = - (2 * 3.14 * fp) * (sin((2 * 3.14 * fp * T) + acos(Xi)));
		Xb1 = (altura_bola - (10 * (pow(td,2)))) / 2;
		Vb1 = 10 * td;
		X0 = Xb1;
		fprintf (arquivo_oscilador, "%f ","%f ", "%f ", X0, Xp, T);
			
	if (Xp == Xb1)
	{
		Vap = Vb1 + Vp;
		Vaf = Vap * e;
		do {
			Xp = cos((2 * 3.14 * fp * T) + acos(Xi));
			Vp = - (2 * 3.14 * fp) * (sin((2 * 3.14 * fp * T) + acos(Xi)));
			Xb2 = Xb1 + (Vaf * ts) - ((10 * (pow(ts,2))) / 2);
			Vb2 = Vaf - (10 * ts);
			X0 = Xb2; 
			ts = ts + 1;
			fprintf (arquivo_oscilador, "%f ","%f ", "%f ", X0, Xp, T);
			T = T + 1;
		} while (Vb2 > 0);
		Xb2 = altura_bola;
		T = T - 1;
	} else {
		Vap = Vb1 + Vp;
		Vaf = Vap * e;
	}	
		td = td + 1;
		T = T + 1;
	} while (Xb1 >= Xp);
	} while (Vaf > 0);
	fclose(arquivo_oscilador);
}

  printf("Os dados podem ser consultados no arquivo arq_oscilador");
  
 } 
 }
