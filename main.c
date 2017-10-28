/******************************************
        Created by Gabriel Santamaria
            TP - Plus ou moins
                26/10/2017
            https://lc.cx/NQxc
******************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MIN 1

int main(void)
{
    /*
    *   Définition des fonctions et des variables
    */
    /* Les fonctions */
    void solo(void); /* Fonction du jeu en solo */
    void meister(void); /* Fonction du jeu en Meister Mode */
    void duel(void); /* Fonction du jeu en mode Duel ! */
    /* Les variables */
    int mode; /* Mode de jeu que l'utilisateur a choisi */
    /*
    *   Début du programme
    */
    /* Formules de politesse et choix du mode de jeu par le joueur */
    printf("Bonjour jeune joueur des contrees lointaines !\n");
    printf("Si tu es ici, c'est que tu veux te mesurer a moi !\n");
    printf("Modes de jeu disponibles :\n");
    printf("1. Solo\n");
    printf("2. Meister Mode\n");
    printf("3. Duel\n");
    printf("Mode de jeu souhaite (1, 2 ou 3) : ");
    scanf("%d", &mode); /* On met la réponse dans la variable mode */
    if (mode == 2)
    {
        printf("Je comprends... Tu as trop peur de me defier, tu joues donc contre moins fort... C'est tout a ton honneur :/\n\n");
        printf("Le mode de jeu \"Meister Mode\" est super !\n");
        printf("Il y a deux joueur : le maitre de jeu et le joueur\n");
        printf("Le but du maître de jeu est de choisir un nombre mytere que le joueur ne trouvera pas.\nLe maitre de jeu defini aussi le nombre de coups maximum que le joueur peut effectuer avant de trouver le nombre.\n");
        printf("Le but du joueur est tout simplement de trouver le nombre mystere en faisant le moins de coups possible !\n\n\n\n");
        meister();
    } else if (mode == 3)
    {
        printf("Le mode de jeu \"Duel\" est cooooo-oool !!\n");
        printf("Deux joueurs s'affrontent :\n");
        printf("Ils doivent trouver le nombre mystère de leur adversaire le plus rapidement possible !.\n");
        printf("Bonne partie !\n\n\n\n");
    	duel();
    } else
    {
        printf("Le mode de jeu solo est tres simple !\n");
        printf("L'ordinateur choisi un nombre aleatoirement et toi, tu dois le trouver !\n");
        printf("Il existe plusieurs niveau de difficulté : dans le niveau facile, l'ordinateur choisi un nombre entre 1 et 100\n                                            dans le niveau moyen, l'ordinateur choisi un nombre entre 1 et 1,000\n                                            dans le niveau difficile, l'ordinateur choisi un nombre entre 1 et 10,000\n\n\n");
        printf("Le but du jeu est donc de trouver ce nombre avec le moins d'essais possible !\n\n\n\n");
        solo();
    }
    return 0;
}

/* Fonction du jeu en solo */
void solo(void)
{
    int nb; /* Nombre aléatoire, généré par la machine (nombre mystère)*/
    int x; /* Nombre que l'utilisateur va entrer */
    int difficulte; /* Difficulté choisie par l'utilisateur ( 1 = Facile ; 2 = Moyen ; 3 = Difficile) */
    int max; /* Nombre maximum */
    int essai = 0; /* Nombre d'essais que l'utilisateur a fait avant de trouver le nombre mystère */
    int continuer = 1; /* L'utilisateur veut-il continuer ? */
    char reponse_continu; /* Réponse de l'utilisateur lorsqu'on va lui demander s'il veut continuer ou non */
    /* Un peu d'art, pour plus de fun */
    printf("  ,ad8888ba,    88888888ba   88888888ba,    88  \n");
    printf(" d8\"'    `\"8b   88      \"8b  88      `\"8b   88  \n");
    printf("d8'        `8b  88      ,8P  88        `8b  88  \n");
    printf("88          88  88aaaaaa8P'  88         88  88  \n");
    printf("88          88  88\"\"\"\"88'    88         88  88  \n");
    printf("Y8,        ,8P  88    `8b    88         8P  88  \n");
    printf(" Y8a.    .a8P   88     `8b   88      .a8P   88  \n");
    printf("  `\"Y8888Y\"'    88      `8b  88888888Y\"'    88  \n\n\n\n");
    /* Fin de l'art incroyable ! */
    /* Pacotilles et choix du niveau de difficulté */
    printf("Super ! Je vois que tu souhaites te mesurer au boss des boss ! On m'appelle \"The Terminator\" dans le milleu :)\n");
    printf("Choisissez un niveau de difficulte :\n");
    printf("1 = Facile\n2 = Moyen\n3 = Difficile\n");
    printf("Niveau de difficulte : ");
    scanf("%d", &difficulte);
    /* Switch pour définir la valeur de max (= valeur maximale du nombre mystère) */
    switch (difficulte)
    {
        case 1 : max = 100;
                 break;
        case 2 : max = 1000;
                 break;
        case 3 : max = 10000;
                 break;
        default : max = 100;
                  break;
    }
    srand(time(NULL)); /* Initialisation du générateur de nombres aléatoires */
    nb = (rand() % (max - MIN + 1)) + MIN; /* Génération du nombre aléatoire entre MAX - MIN */
    printf("J'espere que tu es pret a jouer car c'est parti !\n"); /* On motive un peut le joueur :p */
    /* Lancement de la boucle infinie, jusqu'à que le joueur trouve le nombre mystère */
    while(continuer == 1)
    {
        printf("Quel est le nombre ? ");
        scanf("%d", &x);
        if (x > nb)
        {
            printf("C'est moins !\n"); /* On affiche au joueur que le nombre mystère est inférieur à ce qu'il a entré */
            essai++; /* On ajoute +1 à la variable essai */
        } else if (x < nb)
        {
            printf("C'est plus !\n"); /* On affiche au joueur que le nombre mystère est supérieur à ce qu'il a entré */
            essai++; /* On ajoute +1 à la variable essai */
        } else if (x == nb)
        {
            printf("Bravo ! Tu as trouve le nombre mystere ! C'etais %d ! Tu l'as trouve en %d essais !\n", nb, essai + 1);
            printf("Veux-tu rejouer ? (Y/N) ");
            scanf(" %c", &reponse_continu);
            if (reponse_continu == 'y' || reponse_continu == 'Y')
            {
                printf("1 = Facile\n2 = Moyen\n3 = Difficile\n");
                printf("Niveau de difficulte : ");
                scanf("%d", &difficulte);
                /* Switch pour définir la valeur de max (= valeur maximale du nombre mystère) */
                switch (difficulte)
                {
                    case 1 : max = 100;
                             break;
                    case 2 : max = 1000;
                             break;
                    case 3 : max = 10000;
                             break;
                    default : max = 100;
                              break;
                }
                nb = (rand() % (max - MIN + 1)) + MIN; /* Génération d'un nouveau nombre aléatoire, pour la nouvelle partie */
                essai = 0; /* Réinitialisation de la variable du nombre d'essais */
                continuer = 1;
            } else if (reponse_continu == 'n' || reponse_continu == 'N'){
                continuer = 0;
            }
        }
    }
    printf("Ce fut un plaisir de jouer avec toi (meme si tu es bien moins fort que moi) !\n");
    printf("A une prochaine fois !\n");
}

/* Fontion du jeu en Meister Mode */
void meister(void)
{
    /*
        Ce mode de jeu comporte deux joueurs. Le joueur n°1 est le "maître de jeu" : c'est lui qui choisi le nombre mytère
        Le maître de jeu choisi aussi le nombre de coups maximals que le joueur n°2 a le droit de faire.
        Le joueur n°2 doit tout simplement trouver le nombre mystère que le joueur n°1 a choisi dans un nombre de coups défini par le joueur n°1
    */
    int nb; /* Nombre que le joueur 1 choisi */
    int max; /* Nombre de coups maximum, défini par le joueur n°1 (minimum de 1) */
    int x; /* Nombre que le joueur 2 va entrer */
    int essai = 0; /* Nombre d'essais que le joueur n°2 a fait avant de trouver le nombre mystère */
    int continuer = 1; /* Valeur booléenne qui permet de controler la boucle du jeu */
    char reponse_continu; /* Réponse des joueurs pour continuer ou non */
    /* Un peu d'art, pour plus de fun */
    printf(" /$$      /$$         /$$           /$$                             /$$      /$$               /$$ \n");
    printf("| $$$    /$$$        |__/          | $$                            | $$$    /$$$              | $$         \n");
    printf("| $$$$  /$$$$ /$$$$$$ /$$ /$$$$$$$/$$$$$$   /$$$$$$  /$$$$$$       | $$$$  /$$$$ /$$$$$$  /$$$$$$$ /$$$$$$ \n");
    printf("| $$ $$/$$ $$/$$__  $| $$/$$_____|_  $$_/  /$$__  $$/$$__  $$      | $$ $$/$$ $$/$$__  $$/$$__  $$/$$__  $$\n");
    printf("| $$  $$$| $| $$$$$$$| $|  $$$$$$  | $$   | $$$$$$$| $$  \\__/      | $$  $$$| $| $$  \\ $| $$  | $| $$$$$$$$\n");
    printf("| $$\\  $ | $| $$_____| $$\\____  $$ | $$ /$| $$_____| $$            | $$\\  $ | $| $$  | $| $$  | $| $$_____/\n");
    printf("| $$ \\/  | $|  $$$$$$| $$/$$$$$$$/ |  $$$$|  $$$$$$| $$            | $$ \\/  | $|  $$$$$$|  $$$$$$|  $$$$$$$\n");
    printf("|__/     |__/\\_______|__|_______/   \\___/  \\_______|__/            |__/     |__/\\______/ \\_______/\\_______/\n\n\n\n");
    /* Fin de l'art incroyable ! */
    printf("Hey ! J'espere que vous allez bien et que vous etes pret pour vous foutre dessus !\n");
    printf("Joueur 1, choisissez un nombre mystère : ");
    scanf("%d", &nb);
    printf("Joueur 1, choisissez le nombre maximum de coups (minimum 1) : ");
    scanf("%d", &max);
    if (max < 1)
    {
        max = 1;
    }
    printf("Joueur 2 ! C'est votre tour ! Trouvez le nombre mystere !\n");
    /* Lancement de la boucle infinie, jusqu'à que le joueur n°2 trouve le nombre mystère */
    while(continuer == 1)
    {
        if (essai >= max) /* Si le nombre d'essais dépasse le nombre que le joueur 1 a défini, on arrête la boucle et on notifie le joueur qu'il a perdu ! */
        {
            printf("Dommage ! Tu as perdu ! Le nombre mystère que le joueur 1 a choisi etait %d\n", nb);
            /* On invite les joueurs à rejouer :) */
            printf("Vous voulez rejouer ? (Y/N) ");
            scanf(" %c", &reponse_continu);
            if (reponse_continu == 'y' || reponse_continu == 'Y')
            {
                /* On réinvite le joueur 1 à définir un nombre mystère et un nombre de coups */
                printf("Joueur 1, choisissez un nombre mystère : ");
                scanf("%d", &nb);
                printf("Joueur 1, choisissez le nombre maximum de coups (minimum 1) : ");
                scanf("%d", &max);
                if (max < 1)
                {
                    max = 1;
                }
                printf("Joueur 2 ! C'est votre tour ! Trouvez le nombre mystere !\n");
                essai = 0; /* Réinitialisation de la variable du nombre d'essais */
                continuer = 1;
            } else if (reponse_continu == 'n' || reponse_continu == 'N'){
                continuer = 0;
            }
        }
        /* On demande au joueur 2 le nombre mystère */
        printf("Quel est le nombre ? ");
        scanf("%d", &x);
        if (x > nb)
        {
            printf("C'est moins !\n"); /* On affiche au joueur que le nombre mystère est inférieur à ce qu'il a entré */
            essai++; /* On ajoute +1 à la variable essai */
        } else if (x < nb)
        {
            printf("C'est plus !\n"); /* On affiche au joueur que le nombre mystère est supérieur à ce qu'il a entré */
            essai++; /* On ajoute +1 à la variable essai */
        } else if (x == nb)
        {
            printf("Bravo ! Tu as trouve le nombre mystere ! C'etais %d ! Tu l'as trouve en %d essais !\n", nb, essai + 1);
            printf("Vous voulez rejouer ? (Y/N) ");
            scanf(" %c", &reponse_continu);
            if (reponse_continu == 'y' || reponse_continu == 'Y')
            {
                /* On réinvite le joueur 1 à définir un nombre mystère et un nombre de coups */
                printf("Joueur 1, choisissez un nombre mystère : ");
                scanf("%d", &nb);
                printf("Joueur 1, choisissez le nombre maximum de coups (minimum 1) : ");
                scanf("%d", &max);
                if (max < 1)
                {
                    max = 1;
                }
                printf("Joueur 2 ! C'est votre tour ! Trouvez le nombre mystere !\n");
                essai = 0; /* Réinitialisation de la variable du nombre d'essais */
                continuer = 1;
            } else if (reponse_continu == 'n' || reponse_continu == 'N'){
                continuer = 0;
            }
        }
    }
	printf("C'etait cool cette parti ! N'hesitez pas a revenir quand vous voulez !\n");
}

/* Fonction du jeu en mode Duel ! */
void duel(void)
{
	/*
		Ce mode de jeu comporte lui aussi deux joueurs. Au début de la partie, chacun choisi son nombre mystère.
		Lorsque la partie commence, l'ordinateur tire au sort celui qui commence. Le joueur qui commence fait une première tentative pour trouver le nombre
		mystère de l'autre joueur, s'il échoue, c'est à l'autre joueur d'essayer de deviner son nombre mystère, etc...
		Lorsqu'un joueur trouve le nombre mystère de l'autre joueur, la partie s'arrête et il a gagné.
	*/
    int nb1; /* Nombre mystère du joueur 1 */
    int nb2; /* Nombre mystère du joueur 2 */
   	int start; /* "Id" du joueur qui va commencer à jouer */
   	int x; /* Nombre que les joueurs vont entrer */
    int essai1 = 0; /* Nombre d'essais que le joueur n°1 a fait avant de trouver le nombre mystère */
    int essai2 = 0; /* Nombre d'essais que je joueur n°2 a fait avant de trouver le nombre mystère */
    int i = 0; /* Compteur */
    int continuer = 1; /* Valeur booléenne qui permet de controler la boucle du jeu */
    char reponse_continu; /* Réponse des joueurs pour continuer ou non */
    /* Un peu d'art, pour plus de fun */
    printf(" _______   __    __   _______  __          __  \n");
    printf("|       \\ |  |  |  | |   ____||  |        |  | \n");
    printf("|  .--.  ||  |  |  | |  |__   |  |        |  | \n");
    printf("|  |  |  ||  |  |  | |   __|  |  |        |  | \n");
    printf("|  '--'  ||  `--'  | |  |____ |  `----.   |__| \n");
    printf("|_______/  \\______/  |_______||_______|   (__) \n\n\n\n");
	/* Fin de l'art incroyable ! */
	printf("Youhouuuuuu ! C'est l'heure du du-du-du-du-du-duel !\n");
	printf("Joueur 1, choisissez un nombre mystere : ");
	scanf("%d", &nb1);
	printf("Joueur 2, choisissez un nombre mystere : ");
	scanf("%d", &nb2);
	printf("\n\n\n\n\nTres bien ! Je vais tirer au sort celui qui va commencer !\n");
	printf("...\n");
	printf("...\n");
	srand(time(NULL)); /* Initialisation du générateur de nombres aléatoires */
	start = (rand() % (2 - 1 + 1)) + 1; /* Génération du nombre aléatoire entre 1 et 2, ce nombre déterminera celui qui va commencer */
	printf("C'est bon ! Celui qui vas commencer sera... ... ");
	if (start == 1)
	{
		printf("le Joueur 1 !\n");
	} else if (start == 2)
	{
		printf("le Joueur 2 !\n");
	}
    /* Lancement de la boucle infinie, jusqu'à que le joueur n°2 trouve le nombre mystère */
    while(continuer == 1)
    {
    	i++; /* On incrémente i de 1 à chaque tour de la boucle */
    	if (start == 1) /* Dans le cas pù c'est le joueur 1 qui doit commencer */
    	{
	    	if (i % 2 == 1) /* Si i est impair, alors c'est le tour du joueur 1 */
	    	{
		    	printf("Joueur 1, quel est le nombre ? "); /* On demande le nombre au joueur 1 */
		    	scanf("%d", &x);
		    	if (x > nb2)
		    	{
		    		printf("C'est moins !\n");
		    		essai1++; /* On incrémente le nombre d'essais du joueur de 1 à chaque fois qu'il se trompe */
		    	} else if (x < nb2)
		    	{
		    		printf("C'est plus !\n");
		    		essai1++; /* On incrémente le nombre d'essais du joueur de 1 à chaque fois qu'il se trompe */
		    	} else if (x == nb2)
		    	{
		    		printf("Le joueur 1 a gagne ! Le nombre mystere etait : %d, il l'a trouve en %d coups ! Bravo !\n", nb2, essai1);
					printf("Vous voulez rejouer ? (Y/N) ");
					scanf(" %c", &reponse_continu);
		            if (reponse_continu == 'y' || reponse_continu == 'Y')
		            {
		                /* On réinvite le joueur 1 à définir un nombre mystère et un nombre de coups */
						printf("Joueur 1, choisissez un nombre mystere : ");
						scanf("%d", &nb1);
						printf("Joueur 2, choisissez un nombre mystere : ");
						scanf("%d", &nb2);
						printf("\n\n\n\n\nTres bien ! Je vais tirer au sort celui qui va commencer !\n");
						printf("...\n");
						printf("...\n");
						start = (rand() % (2 - 1 + 1)) + 1; /* Génération du nombre aléatoire entre 1 et 2, ce nombre déterminera celui qui va commencer */
						printf("C'est bon ! Celui qui vas commencer sera... ... ");
						if (start == 1)
						{
							printf("le Joueur 1 !\n");
						} else if (start == 2)
						{
							printf("le Joueur 2 !\n");
						}
		                essai1 = essai2 = 0; /* Réinitialisation de la variable du nombre d'essais */
		                continuer = 1;
		            } else if (reponse_continu == 'n' || reponse_continu == 'N'){
		                continuer = 0;
		            }
		    	}
	    	} else if (i % 2 == 0) /* Si i est pair, c'est au tour du joueur 2 */
	    	{
	    		printf("Joueur 2, quel est le nombre ? "); /* On demande le nombre au joueur 2 */
				scanf("%d", &x);
		    	if (x > nb1)
		    	{
		    		printf("C'est moins !\n");
		    		essai2++; /* On incrémente le nombre d'essais du joueur de 1 à chaque fois qu'il se trompe */
		    	} else if (x < nb1)
		    	{
		    		printf("C'est plus !\n");
		    		essai2++; /* On incrémente le nombre d'essais du joueur de 1 à chaque fois qu'il se trompe */
		    	} else if (x == nb1)
		    	{
		    		printf("Le joueur 2 a gagne ! Le nombre mystere etait : %d, il l'a trouve en %d coups ! Bravo !\n", nb1, essai2);
					printf("Vous voulez rejouer ? (Y/N) ");
					scanf(" %c", &reponse_continu);
		            if (reponse_continu == 'y' || reponse_continu == 'Y')
		            {
		                /* On réinvite le joueur 1 à définir un nombre mystère et un nombre de coups */
						printf("Joueur 1, choisissez un nombre mystere : ");
						scanf("%d", &nb1);
						printf("Joueur 2, choisissez un nombre mystere : ");
						scanf("%d", &nb2);
						printf("\n\n\n\n\nTres bien ! Je vais tirer au sort celui qui va commencer !\n");
						printf("...\n");
						printf("...\n");
						start = (rand() % (2 - 1 + 1)) + 1; /* Génération du nombre aléatoire entre 1 et 2, ce nombre déterminera celui qui va commencer */
						printf("C'est bon ! Celui qui vas commencer sera... ... ");
						if (start == 1)
						{
							printf("le Joueur 1 !\n");
						} else if (start == 2)
						{
							printf("le Joueur 2 !\n");
						}
		                essai1 = essai2 = 0; /* Réinitialisation de la variable du nombre d'essais */
		                continuer = 1;
		            } else if (reponse_continu == 'n' || reponse_continu == 'N'){
		                continuer = 0;
		            }
		    	}
	    	}
	    } else if (start == 2) /* Sinon, si c'est le joueur 2 qui doit commencer */
    	{
	    	if (i % 2 == 1) /* Si i est impair, c'est le tour du joueur 2 */
	    	{
		    	printf("Joueur 2, quel est le nombre ? ");
		    	scanf("%d", &x);
		    	if (x > nb1)
		    	{
		    		printf("C'est moins !\n");
		    		essai2++; /* On incrémente le nombre d'essais du joueur de 1 à chaque fois qu'il se trompe */
		    	} else if (x < nb1)
		    	{
		    		printf("C'est plus !\n");
		    		essai2++; /* On incrémente le nombre d'essais du joueur de 1 à chaque fois qu'il se trompe */
		    	} else if (x == nb1)
		    	{
		    		printf("Le joueur 2 a gagne ! Le nombre mystere etait : %d, il l'a trouve en %d coups ! Bravo !\n", nb1, essai2);
					printf("Vous voulez rejouer ? (Y/N) ");
					scanf(" %c", &reponse_continu);
		            if (reponse_continu == 'y' || reponse_continu == 'Y')
		            {
		                /* On réinvite le joueur 1 à définir un nombre mystère et un nombre de coups */
						printf("Joueur 1, choisissez un nombre mystere : ");
						scanf("%d", &nb1);
						printf("Joueur 2, choisissez un nombre mystere : ");
						scanf("%d", &nb2);
						printf("\n\n\n\n\nTres bien ! Je vais tirer au sort celui qui va commencer !\n");
						printf("...\n");
						printf("...\n");
						start = (rand() % (2 - 1 + 1)) + 1; /* Génération du nombre aléatoire entre 1 et 2, ce nombre déterminera celui qui va commencer */
						printf("C'est bon ! Celui qui vas commencer sera... ... ");
						if (start == 1)
						{
							printf("le Joueur 1 !\n");
						} else if (start == 2)
						{
							printf("le Joueur 2 !\n");
						}
		                essai1 = essai2 = 0; /* Réinitialisation de la variable du nombre d'essais */
		                continuer = 1;
		            } else if (reponse_continu == 'n' || reponse_continu == 'N'){
		                continuer = 0;
		            }
		    	}
	    	} else if (i % 2 == 0) /* Si i est pair, c'est le tour du joueur 1 */
	    	{
	    		printf("Joueur 1, quel est le nombre ? ");
				scanf("%d", &x);
		    	if (x > nb2)
		    	{
		    		printf("C'est moins !\n");
		    		essai1++; /* On incrémente le nombre d'essais du joueur de 1 à chaque fois qu'il se trompe */
		    	} else if (x < nb2)
		    	{
		    		printf("C'est plus !\n");
		    		essai1++; /* On incrémente le nombre d'essais du joueur de 1 à chaque fois qu'il se trompe */
		    	} else if (x == nb2)
		    	{
		    		printf("Le joueur 1 a gagne ! Le nombre mystere etait : %d, il l'a trouve en %d coups ! Bravo !\n", nb2, essai1);
					printf("Vous voulez rejouer ? (Y/N) ");
					scanf(" %c", &reponse_continu);
		            if (reponse_continu == 'y' || reponse_continu == 'Y')
		            {
		                /* On réinvite le joueur 1 à définir un nombre mystère et un nombre de coups */
						printf("Joueur 1, choisissez un nombre mystere : ");
						scanf("%d", &nb1);
						printf("Joueur 2, choisissez un nombre mystere : ");
						scanf("%d", &nb2);
						printf("\n\n\n\n\nTres bien ! Je vais tirer au sort celui qui va commencer !\n");
						printf("...\n");
						printf("...\n");
						start = (rand() % (2 - 1 + 1)) + 1; /* Génération du nombre aléatoire entre 1 et 2, ce nombre déterminera celui qui va commencer */
						printf("C'est bon ! Celui qui vas commencer sera... ... ");
						if (start == 1)
						{
							printf("le Joueur 1 !\n");
						} else if (start == 2)
						{
							printf("le Joueur 2 !\n");
						}
		                essai1 = essai2 = 0; /* Réinitialisation de la variable du nombre d'essais */
		                continuer = 1;
		            } else if (reponse_continu == 'n' || reponse_continu == 'N'){
		                continuer = 0;
		            }
		    	}
	    	}
	    }

    }
	printf("C'etait cool cette parti ! N'hesitez pas a revenir quand vous voulez !\n");
}