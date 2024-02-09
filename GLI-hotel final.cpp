/*Gustavo Leite Ioels - Rodrigo Poinha Romero - Gabriel Mason 
GLI RPR GMG
Projeto hotel
criar um programa para gerenciar a entrada de dados de um hotel 
*/

#include<stdio.h>

void funcmapa(struct stinfo map[21][15]); 
void funcreserva(struct stinfo res[21][15]); 
void funcCheckin(struct stinfo check[21][15]); 
void funcOut(struct stinfo out[21][15]); 
void funcCancel(struct stinfo cancel[21][15]); 
void funcTaxaoc(struct stinfo tax[21][15]);
void funcInfo(struct stinfo inf[21][15]);
void fclear();

//coleta de dados para a FuncInfo
struct stinfo
{
	char nome[40];
	char cpf[40];
	char tel[40];
	char email[40];
	char ender[40];
	char status;
};



main()
{
	int op;
	int an, ap;
	struct stinfo mp[21][15];
	
	 for(an=20; an>0; an--) 
        for(ap=1; ap<15;ap++) {    // atribui '.' a tabela
           mp[an][ap].status = '.'; 
		}
	do 
	{
	printf("\n\n");
	printf("{==========================}\n");
	printf("{Boas vindas ao hotel Mason}\n");
	printf("{==========================}\n");
	printf("  ------------------------\n");
	printf("  | 1 - Check-in         |\n"); 
	printf("  | 2 - Check-out        |\n");
	printf("  | 3 - Reservar Quarto  |\n");
	printf("  | 4 - Cancelar Reserva |\n");
	printf("  | 5 - Mapa De Ocupacao |\n");
	printf("  | 6 - Informacoes      |\n");
	printf("  | 7 - Taxa de ocupacao |\n");
	printf("  | 8 - Sair do programa |\n");
	printf("  ------------------------\n");
	printf(" Qual Opcao deseja utilizar:");
	scanf("%d", &op);
	
	switch (op) //indica as operacoes
		{
		case 1:
			funcCheckin(mp);	
			break;
		case 2:
			funcOut(mp);
			break;
		case 3:
			funcreserva(mp);
			break;
		case 4:
			funcCancel(mp);
			break;
		case 5:
			funcmapa(mp);
			break;
		case 6:
			funcInfo(mp);
			break;
		case 7:
			funcTaxaoc(mp);
			break;
		}
	
	}
	while(op!=8);
}
	//função que cria o mapa do hotel
void funcmapa(struct stinfo map[21][15]) 
{
	int an, ap;
	
	printf("\n\t");
	
	for(ap=1; ap<15; ap++)
		 printf("%2d ", ap); 
          printf("\n\n");                
          
        for(an=20; an>0;an--) { 
            printf(" %2d:\t", an);          
              
        	for(ap=1; ap<15; ap++) 
                  printf(" %c ", map[an][ap].status); 
		  		printf("\n"); 
		}

	
		
}
	//função que efetua a reserva
void funcreserva(struct stinfo res[21][15])
{
	
	int an, ap;
	
	printf("insira o apartamento que deseja fazer a reserva(andar, apartamento):");
	scanf("%d,%d", &an,&ap);
	
	if(res[an][ap].status!='.') //verifica se o apartamento esta livre
	{
		printf("o apartamento ja esta reservado/ocupado, por favor tente outro apartamento.\n");
		}	
	else
	{
		res[an][ap].status = 'R'; //efetua a reserva do apartamento
		printf("Seu apartamento foi reservado com sucesso.\n");
	}
	if(an<=0 || an>20 || ap<=0 || ap>14) //verifica se o apartamento existe
	{
		printf("Este apartamento nao existe.\n");
	}

}
	//função que efetua o check in
void funcCheckin(struct stinfo check[21][15])
{
	int an, ap;
	
	printf("Insira qual apartamento deseja fazer o check-in(separado por virgula):");
	scanf("%d,%d", &an, &ap);
	
	if(check[an][ap].status=='o' ) //verifica se o apartamento esta disponivel para check in 
		{
			printf("apartamento ja esta reservado/ocupado\n");
		}
	else
	{
		fclear();							
		printf("Nome do hospede: ");
		gets(check[an][ap].nome);
		printf("Endereco do hospede: ");
		gets(check[an][ap].ender);
		printf("CPF do hospede: ");			//coleta de informações para o check-in
		gets(check[an][ap].cpf);
		printf("Telefone do hospede: ");
		gets(check[an][ap].tel);
		printf("Email do hospede: ");
		gets(check[an][ap].email);
		

		check[an][ap].status = 'o'; //efetua o check-in 
		printf("Seu check-in foi efetuado com sucesso\n");
		}	
		
}
	//funçâo que efetua o check-out
void funcOut(struct stinfo out[21][15])
{
	int an, ap;
	
	printf("insira qual apartamento deseja fazer o check-out(separado por virgula):");
	scanf("%d,%d", &an, &ap);
	
	if(out[an][ap].status=='o')
		{
		out[an][ap].status = '.';	//efetua o check-out
		printf("seu check-out foi efetuado com sucesso\n ");
		}
		else 
		printf("selecione um apartamento que esta ocupado\n.");
}
	//funçâo que cancela uma reserva
void funcCancel(struct stinfo cancel[21][15])
{
	int an, ap;
	
	printf("insira qual apartamento deseja cancelar a reserva(separado por virgula):");
	scanf("%d,%d",&an, &ap);
	
	if(cancel[an][ap].status!='R') //verifica se apenas um apartamento reservado foi selecionado
	{
		printf("este apartamento nao possui reservas\n");
	}
	else
		cancel[an][ap].status = '.'; //cancela a reserva
		printf("Sua reserva foi cancelada\n");
}
	//função que faz a taxa de hospedes
void funcTaxaoc(struct stinfo tax[21][15])
{
	int an, ap;
	float N1,N2;
	
	for(an=20; an>0; an--) 
        for(ap=1; ap<15;ap++)
    
		if(tax[an][ap].status=='o') //coleta dados sobre os quartos ocupados
		{
			N1=N1+1;
		}
		else if(tax[an][ap].status=='R') //coleta dados sobre os quartos reservados
		{
			N2=N2+1; 
		}
	N1=(N1*100)/280; //efeuta o calculo de % de ocupação 
	N2=(N2*100)/280; //efeuta o calculo de % de reserva
	printf("A taxa de ocupacao do hotel e %4.2f %%\n", N1);
	printf("A taxa de reservas do hotel e %4.2f %%\n", N2);
}

void fclear()
{
	char carac;
    while( (carac = fgetc(stdin)) != EOF && carac != '\n') {}
}
	//função que da informação sobre o hospede
void funcInfo(struct stinfo inf[21][15])
{
	int an, ap;
	
	printf("Insira o apartamento(separado por virgula):");
	scanf("%d,%d",&an,&ap);
	
	if(inf[an][ap].status=='.')
		{
		printf("Insira um apartamento que esta ocupado\n");
		}

			else
			{
				printf("Nome: %s\n", inf[an][ap].nome);
				printf("Endereco: %s\n", inf[an][ap].ender);
				printf("CPF: %s\n", inf[an][ap].cpf);         //mostra as informações coletadas no check-in
				printf("Telefone: %s\n", inf[an][ap].tel);
				printf("Email: %s\n", inf[an][ap].email);
			}
	
	

}
	
	
	
	
