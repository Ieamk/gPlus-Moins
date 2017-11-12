/******************************************
        Created by Gabriel Santamaria
            TP - Plus ou moins
                26/10/2017
            https://lc.cx/NQxc
******************************************/
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#define MIN 1
/*
    Les fonctions
*/
void text_color(int t,int f);
void nb_secure(int *);
void mode_choose(int *, int *);
void mode_restart(int *, int *, int *);
/*      MODE SOLO    */
void solo(void); /* Fonction du jeu en solo */
void solo_start(int *, int *, int *); /* Fonction d'initialisation du mode Solo */
void solo_win(int *, int *);    /* Notification au joueur s'il a gagné */
void solo_control(int *, int *, int *, int *); /* Fonction de controle du mode solo */
/*      MEISTER MODE    */
void meister(void); /* Fonction du jeu en Meister Mode */
void meister_start(int *, int *, int *, int *); /* Fonction de lancement du mode Meister */
void meister_win(int, int, int); /* Fonction notification gagné / perdu */
void meister_control(int *, int *, int *, int *, int *); /* Fonction de contrôle du mode Meister */
/*      MODE DUEL    */
void duel(void); /* Fonction du jeu en mode Duel ! */
void duel_start(int *, int *, int *, int *, int *, int *, int *); /* Fonction de lancement du duel */
void duel_win(int, int, int, int, int, int); /* Fonction lorsqu'un joueur gagne le duel */
void duel_control(int, int, int *, int *, int *, int *, int *, int *, int *); /* Fonction de controle du mode DUEL */

int main(void)
{
    int mode_init = 1; /* Variable pour initialiser le choix des modes de jeu */
    int mode_play = 0; /* Variable pour demander si on relance le jeu ou non */
    int continuer = 1;

    /*
    *   Début du programme
    */
    /* Formules de politesse et choix du mode de jeu par le joueur */
    puts("Bonjour jeune joueur des contrees lointaines !\n");
    puts("Si tu es ici, c'est que tu veux te mesurer a moi !");
    while(continuer)
    {
        if (mode_init)
        {
            mode_choose(&mode_init, &mode_play);
        } else if (mode_play)
        {
            mode_restart(&mode_play, &mode_init, &continuer);
        }
    }
    puts("C'etait incroyable de jouer avec vous ! Au revoir !");
    return 0;
}
/*
    Fonction de changement de la couleur du texte
*/
void text_color(int t,int f)
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
             SetConsoleTextAttribute(H, (f * 16 + t));
}
/*
    Fonction de demande du nombre sécurisée
*/
void nb_secure(int * x)
{
    int saisie;
    do
    {
        printf("Quel est le nombre ? "); /* On demande le nombre dans que la réponse n'est pas satisfaisante */
        saisie = scanf("%d", x);
        scanf("%*[^\n]"); /* On vide le buffer (mémoire tampon) */
    }while(saisie != 1);
}
/*
    Fonction pour choisir le mode de jeu
*/
void mode_choose(int * mode_init, int * mode_play)
{
    int mode; /* Mode de jeu que l'utilisateur a choisi */
    *mode_init = 0;
    puts("Modes de jeu disponibles :\n1. Solo\n2. Meister Mode\n3. Duel"); // Montre les infos a chaque changement de mode
    printf("Mode de jeu souhaite (1, 2 ou 3) : ");
    scanf("%d", &mode); /* On met la réponse dans la variable mode */
    if (mode == 2)
    {
        puts("Je comprends... Tu as trop peur de me defier, tu joues donc contre moins fort... C'est tout a ton honneur :/\n\nLe mode de jeu \"Meister Mode\" est super !\nIl y a deux joueur : le maitre de jeu et le joueur\nLe but du maître de jeu est de choisir un nombre mytere que le joueur ne trouvera pas.");
        puts("Le maitre de jeu defini aussi le nombre de coups maximum que le joueur peut effectuer avant de trouver le nombre.\nLe but du joueur est tout simplement de trouver le nombre mystere en faisant le moins de coups possible !\n\n\n\n");
        meister();
        *mode_play = 1; /* On demande au joueur s'il veut changer de mode de jeu */
    } else if (mode == 3)
    {
        puts("Le mode de jeu \"Duel\" est cooooo-oool !!\nDeux joueurs s'affrontent :\nIls doivent trouver le nombre mystère de leur adversaire le plus rapidement possible !.\nBonne partie !\n\n\n\n");
        duel();
        *mode_play = 1; /* On demande au joueur s'il veut changer de mode de jeu */
    } else
    {
        puts("Le mode de jeu solo est tres simple !");
        puts("L'ordinateur choisi un nombre aleatoirement et toi, tu dois le trouver !");
        puts("Il existe plusieurs niveau de difficulte : dans le niveau facile, l'ordinateur choisi un nombre entre 1 et 100\n                                            dans le niveau moyen, l'ordinateur choisi un nombre entre 1 et 1,000\n                                            dans le niveau difficile, l'ordinateur choisi un nombre entre 1 et 10,000\n");
        puts("Le but du jeu est donc de trouver ce nombre avec le moins d'essais possible !\n");
        solo();
        *mode_play = 1; /* On demande au joueur s'il veut changer de mode de jeu */
    }
}

/*
    Fonction de restart du jeu
*/
void mode_restart(int * mode_play, int * mode_init, int * continuer)
{
    char x;
   *mode_play = 0;
    printf("Voulez-vous continuer a jouer ? (O / N) : "); /* On demande le nombre dans que la réponse n'est pas satisfaisante */
    scanf(" %c", &x);

    if (x == 'o' || x == 'O')
    {
        *mode_init = 1;
    } else if (x == 'n' || x == 'N')
    {
        *continuer = 0;
    }
}

/* Fonction du jeu en solo */
void solo(void)
{
    int nb; /* Nombre aléatoire, généré par la machine (nombre mystère)*/
    int essai = 0; /* Nombre d'essais que l'utilisateur a fait avant de trouver le nombre mystère */
    int continuer = 1; /* L'utilisateur veut-il continuer ? */
    int init = 1;
    /* Un peu d'art, pour plus de fun */
    puts("  ,ad8888ba,    88888888ba   88888888ba,    88  ");
    puts(" d8\"'    `\"8b   88      \"8b  88      `\"8b   88  ");
    puts("d8'        `8b  88      ,8P  88        `8b  88  ");
    puts("88          88  88aaaaaa8P'  88         88  88  ");
    puts("88          88  88\"\"\"\"88'    88         88  88  ");
    puts("Y8,        ,8P  88    `8b    88         8P  88  ");
    puts(" Y8a.    .a8P   88     `8b   88      .a8P   88  ");
    puts("  `\"Y8888Y\"'    88      `8b  88888888Y\"'    88  \n\n\n");
    /* Fin de l'art incroyable ! */
    /* Pacotilles et choix du niveau de difficulté */
    puts("Super ! Je vois que tu souhaites te mesurer au boss des boss ! On m'appelle \"The Terminator\" dans le milleu :)");
    puts("J'espere que tu es pret a jouer car c'est parti !\n"); /* On motive un peut le joueur :p */
    srand(time(NULL)); /* Initialisation du générateur de nombres aléatoires */
    /* Lancement de la boucle infinie, jusqu'à que le joueur trouve le nombre mystère */
    while(continuer)
    {
        if (init)
        {
            /* On initialise la partie ! */
            solo_start(&init, &nb, &essai);
        }
        solo_control(&nb, &essai, &continuer, &init);
    }
    puts("Ce fut un plaisir de jouer avec toi (meme si tu es bien moins fort que moi) !");
    puts("A une prochaine fois !\n");
}
/*
    Fonction de lancement de la partie
    Demande le niveau de difficulté et lance la partie
*/
void solo_start(int * init, int * nb, int * essai)
{
    int max;
    int difficulte;
    /* Réinitialisation des essais du joueur et mise à 0 de l'initialisation */
    *essai = *init = 0;
    puts("Choisissez un niveau de difficulte :\n");
    puts("    1 = Facile\n    2 = Moyen\n    3 = Difficile");
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
    *nb = (rand() % (max - MIN + 1)) + MIN; /* Génération du nombre aléatoire entre MAX - MIN */
}
/*
    Fonction lorsque le joueur gagne
    Mode solo
*/
void solo_win(int * nb, int * essai)
{
    int i; /* Chiffre qui va nous permettre de définir l'exclamation */
    char * exclamation[4] = {
        "Bastante !",
        "Inimaginable !",
        "Passable.",
        "Bof, tu peux mieux faire..."
    };
    /*
        On change la formule d'exclamation en fonction du nombre d'essais effectués pour trouver
        le nombre mystère
    */
    if (*essai <= 5)
    {
        i = 0;
    } else if (*essai <= 10)
    {
        i = 1;
    } else if (*essai <= 15)
    {
        i = 2;
    } else
    {
        i = 3;
    }
    printf("%s Tu as trouve le nombre mystere ! C'etais %d ! Tu l'as trouve en %d essais !\n", exclamation[i], *nb, *essai);
}
/*
    Fonction de contrôle du mode solo
*/
void solo_control(int * nb, int * essai, int * continuer, int * init)
{
    int x;
    char reponse_continu;
    text_color(11, 0); /* On change la couleur du texte */
    /* On demande au joueur le nombre mystère, avec la fonction nb_secure */
    nb_secure(&x);

    text_color(7, 0); /* On remet la couleur de base */
    if (x > *nb)
    {
        puts("C'est moins !"); /* On affiche au joueur que le nombre mystère est inférieur à ce qu'il a entré */
        *essai = *essai + 1; /* On ajoute +1 à la variable essai */
    } else if (x < *nb)
    {
        puts("C'est plus !"); /* On affiche au joueur que le nombre mystère est supérieur à ce qu'il a entré */
        *essai = *essai + 1; /* On ajoute +1 à la variable essai */
    } else // Si c'est ni plus grand ni plus petit c'est forcement egal
    {
        solo_win(nb, essai);
        printf("Veux-tu rejouer ? (O / N) : ");
        scanf(" %c", &reponse_continu);
        if (reponse_continu == 'o' || reponse_continu == 'O')
        {
            *init = 1;
        } else if (reponse_continu == 'n' || reponse_continu == 'N')
        {
            *continuer = 0;
        }
    }
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
    int essai = 0; /* Nombre d'essais que le joueur n°2 a fait avant de trouver le nombre mystère */
    int continuer = 1; /* Valeur booléenne qui permet de controler la boucle du jeu */
    int init = 1;
    /* Un peu d'art, pour plus de fun */
    puts(" /$$      /$$         /$$           /$$                             /$$      /$$               /$$ ");
    puts("| $$$    /$$$        |__/          | $$                            | $$$    /$$$              | $$         ");
    puts("| $$$$  /$$$$ /$$$$$$ /$$ /$$$$$$$/$$$$$$   /$$$$$$  /$$$$$$       | $$$$  /$$$$ /$$$$$$  /$$$$$$$ /$$$$$$ ");
    puts("| $$ $$/$$ $$/$$__  $| $$/$$_____|_  $$_/  /$$__  $$/$$__  $$      | $$ $$/$$ $$/$$__  $$/$$__  $$/$$__  $$");
    puts("| $$  $$$| $| $$$$$$$| $|  $$$$$$  | $$   | $$$$$$$| $$  \\__/      | $$  $$$| $| $$  \\ $| $$  | $| $$$$$$$$");
    puts("| $$\\  $ | $| $$_____| $$\\____  $$ | $$ /$| $$_____| $$            | $$\\  $ | $| $$  | $| $$  | $| $$_____/");
    puts("| $$ \\/  | $|  $$$$$$| $$/$$$$$$$/ |  $$$$|  $$$$$$| $$            | $$ \\/  | $|  $$$$$$|  $$$$$$|  $$$$$$$");
    puts("|__/     |__/\\_______|__|_______/   \\___/  \\_______|__/            |__/     |__/\\______/ \\_______/\\_______/\n\n\n");
    /* Fin de l'art incroyable ! */
    puts("Hey ! J'espere que vous allez bien et que vous etes pret pour vous foutre dessus !\n");
    /* Lancement de la boucle infinie, jusqu'à que le joueur n°2 trouve le nombre mystère */
    while(continuer)
    {
        if (init) /* On initialise le jeu */
        {
            meister_start(&nb, &max, &essai, &init);
        }
        meister_control(&nb, &max, &essai, &init, &continuer);
    }
    puts("C'etait cool cette parti ! N'hesitez pas a revenir quand vous voulez !\n");
}
/*
    Fonction de lancement de la partie
    Demande au joueur 1 le nombre mystère ainsi que le nombre maximum de coups
*/
void meister_start(int * nb, int * max, int * essai, int * init)
{
    *essai = *init = 0;
    text_color(10, 0);
    printf("Joueur 1, choisissez un nombre mystere : ");
    scanf("%d", nb);
    printf("Joueur 1, choisissez le nombre maximum de coups (minimum 1) : ");
    scanf("%d", max);
    /* Contrôle du minimum de coups */
    if (*max < 1)
    {
        *max = 1;
    }
    text_color(12, 0);
    puts("Joueur 2 ! C'est votre tour ! Trouvez le nombre mystere !");
}
/*
    Fonction gagné / perdu
    Notifie le joueur 2 lorsqu'il a gagné ou perdu
*/
void meister_win(int status, int essais, int mystere)
{
    /* On contrôle s'il y a eu plus d'un essais, pour éventuellement le mettre au pluriel */
    int nb_essai = 0;
    char * pluriel[2] = {
        "essai",
        "essais"
    };
    if (essais > 1)
    {
        nb_essai = 1;
    }
    /* Si le joueur a gagné */
    if (status == 1)
    {
        printf("Supercalifragilisticexpialidocious ! C'est le joueur 2 qui l'emporte en %d %s !\n", essais, pluriel[nb_essai]);
    } else
    {
        printf("Le joueur 2 a perdu ! Le nombre mystere etait %d et il fallait le trouver en %d %s !\n", mystere, essais, pluriel[nb_essai]);
    }
}
/*
    Fonction de contrôle mode Meister
*/
void meister_control(int * nb, int * max, int * essai, int * init, int * continuer)
{
    int x;
    char reponse_continu;

    /* On demande au joueur 2 le nombre mystère */
    text_color(12, 0);
    if (*essai >= *max) /* Si le nombre d'essais dépasse le nombre que le joueur 1 a défini, on arrête la boucle et on notifie le joueur qu'il a perdu ! */
    {
        text_color(7, 0);
        meister_win(0, *max, *nb); /* Le joueur a perdu */
        /* On invite les joueurs à rejouer :) */
        puts("Vous voulez rejouer ? (O/N) ");
        scanf(" %c", &reponse_continu);
        if (reponse_continu == 'o' || reponse_continu == 'O')
        {
            /* On réinitialise le jeu */
            *init = 1;
        } else if (reponse_continu == 'n' || reponse_continu == 'N'){
            *continuer = 0;
        }
    } 
    nb_secure(&x);
    if (x > *nb)
    {
        puts("C'est moins !"); /* On affiche au joueur que le nombre mystère est inférieur à ce qu'il a entré */
        *essai = *essai + 1; /* On ajoute +1 à la variable essai */
    } else if (x < *nb)
    {
        puts("C'est plus !"); /* On affiche au joueur que le nombre mystère est supérieur à ce qu'il a entré */
        *essai = *essai + 1; /* On ajoute +1 à la variable essai */
    } else // Si c'est ni plus grand ni plus petit c'est forcement egal
    {
        meister_win(1, *essai, *nb);
        text_color(7, 0);
        puts("Vous voulez rejouer ? (O/N) ");
        scanf(" %c", &reponse_continu);
        if (reponse_continu == 'o' || reponse_continu == 'O')
        {
            /* On réinitialise le jeu */
            *init = 1;
        } else if (reponse_continu == 'n' || reponse_continu == 'N'){
            *continuer = 0;
        }
    }
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
    int init = 1; /* Valeur booléenne qui nous permet de savoir quand il faut initialiser le jeu ou non */
    int continuer = 1; /* Valeur booléenne qui permet de controler la boucle du jeu */
    /* Un peu d'art, pour plus de fun */
    puts(" _______   __    __   _______  __          __  ");
    puts("|       \\ |  |  |  | |   ____||  |        |  | ");
    puts("|  .--.  ||  |  |  | |  |__   |  |        |  | ");
    puts("|  |  |  ||  |  |  | |   __|  |  |        |  | ");
    puts("|  '--'  ||  `--'  | |  |____ |  `----.   |__| ");
    puts("|_______/  \\______/  |_______||_______|   (__) \n\n\n");
    /* Fin de l'art incroyable ! */
    puts("Youhouuuuuu ! C'est l'heure du du-du-du-du-du-duel !\n");
    srand(time(NULL)); /* Initialisation du générateur de nombres aléatoires */
    /* Lancement de la boucle infinie, jusqu'à que le joueur n°2 trouve le nombre mystère */
    while(continuer)
    {
        if (init)
        {
            duel_start(&i, &nb1, &nb2, &start, &essai1, &essai2, &init);
        }
        i++; /* On incrémente i de 1 à chaque tour de la boucle */
        if (start) /* Dans le cas pù c'est le joueur 1 qui doit commencer */
        {
            if (i % 2 == 1) /* Si i est impair, alors c'est le tour du joueur 1 */
            {
                text_color(10, 0);
                duel_control(1, 2, &x, &nb1, &nb2, &essai1, &essai2, &continuer, &init);
            } else if (i % 2 == 0) /* Si i est pair, c'est au tour du joueur 2 */
            {
                text_color(12, 0);
                duel_control(2, 1, &x, &nb2, &nb1, &essai2, &essai1, &continuer, &init);
            }
        } else if (start == 2) /* Sinon, si c'est le joueur 2 qui doit commencer */
        {
            if (i % 2 == 1) /* Si i est impair, c'est le tour du joueur 2 */
            {
                text_color(12, 0);
                duel_control(2, 1, &x, &nb2, &nb1, &essai2, &essai1, &continuer, &init);
            } else if (i % 2 == 0) /* Si i est pair, c'est le tour du joueur 1 */
            {
                text_color(10, 0);
                duel_control(1, 2, &x, &nb1, &nb2, &essai1, &essai2, &continuer, &init);
            }
        }

    }
    text_color(7, 0);
    puts("C'etait cool cette parti ! N'hesitez pas a revenir quand vous voulez !\n");
}
/*
    Fonction de lancement de partie
    Affiche toutes les formules pour demander les nombres mystères, etc...
    Tire au sort le joueur qui commence.
*/
void duel_start(int * i, int * nb1, int * nb2, int * start, int * essai1, int * essai2, int * init)
{
    text_color(7, 0); /* Réinsitalisation de la couleur de l'écriture dans la console. */
    *essai1 = *essai2 = *i = 0; /* Réinitialisation de la variable du nombre d'essais et de I ( le compteur ) */
    /* On réinvite le joueur 1 à définir un nombre mystère et un nombre de coups */
    puts("Joueur 1, choisissez un nombre mystere : ");
    scanf("%d", nb1); /* On place la réponse dans la variable nb1 */
    system("cls"); // evitons la triche
    puts("Joueur 2, choisissez un nombre mystere : ");
    scanf("%d", nb2); /* On place la réponse dans la variable nb2 */
    system("cls"); // evitons la triche
    puts("Tres bien ! Je vais tirer au sort celui qui va commencer !\n");
    puts("...\n");
    puts("...\n");
    *start = (rand() % (2 - 1 + 1)) + 1; /* Génération du nombre aléatoire entre 1 et 2, ce nombre déterminera celui qui va commencer */
    puts("C'est bon ! Celui qui vas commencer sera... ... ");
    if (*start)
    {
        text_color(10, 0);
        puts("le Joueur 1 !\n");
        text_color(7, 0); /* Réinitialisation de l'écriture dans la console */
    } else if (*start == 2)
    {
        text_color(12, 0);
        puts("le Joueur 2 !\n");
        text_color(7, 0); /* Réinitialisation de l'écriture dans la console */
    }
    /* Tout c'est bien déroulé, le jeu est initialisé, on peut mettre init à 0 */
    *init = 0;
}
/*
    Fonction lorsque le joueur gagne le duel
    Arguments :
        winner : le numéro du joueur gagnant
        mystere : le nombre mystere
        essai : nombre d'essais avant de trouver le nombre mystère
*/
void duel_win(int winner, int mystere, int essai, int looser, int essai2, int nb2)
{
    int i; /* Ce qui va nous permettre de nous situer dans notre tableau */
    char * etonnements[4] = { /* Tableau de pointeur de type char, contenant les différentes exclamations */
        "Magistral !",
        "Superbe !",
        "Pas mal !",
        "Mouais..."
    };
    text_color(7, 0); /* Réinitialisation de l'écriture dans la console */
    /*
        On change la formule d'étonnement en fonction du nombre d'essais réalisés pour trouver
        le nombre mystère
    */
    if (essai <= 5)
    {
        i = 0;
    } else if (essai <= 10)
    {
        i = 1;
    } else if (essai <= 15)
    {
        i = 2;
    } else
    {
        i = 3;
    }
    /* On leurs dit quels étaient les chiffres */
    printf("Le nombre mystere du joueur %d etait : %d\n", winner, nb2);
    printf("Le nombre mystere du joueur %d etait : %d\n", looser, mystere);
    /* On affiche aux joueurs le gagnant avec des petites "statistiques" */
    printf("%s C'est le joueur %d qui a gagne ! Il a trouve le nombre mystere en %d coups !\n", etonnements[i], winner, essai);
    printf("Le joueur %d lui, a effectue %d essais mais n'a pas trouve le nombre mystere !\n", looser, essai2);
}
/*
    Fonction de control si le nombre que le joueur entre est le bon
*/
void duel_control(int joueur, int adversaire, int * x, int * nb1, int * nb2, int * essai1, int * essai2, int * continuer, int * init)
{
    char reponse_continu; /* Réponse des joueurs pour continuer ou non */
    printf("Joueur %d, quel est le nombre ? ", joueur);
    scanf("%d", x);
    if (*x > *nb2)
    {
        puts("C'est moins !\n");
        *essai1 = *essai1 + 1; /* On incrémente le nombre d'essais du joueur de 1 à chaque fois qu'il se trompe */
    } else if (*x < *nb2)
    {
        puts("C'est plus !\n");
        *essai1 = *essai1 + 1; /* On incrémente le nombre d'essais du joueur de 1 à chaque fois qu'il se trompe */
    } else if (*x == *nb2)
    {
        duel_win(joueur, *nb2, *essai1+ 1, adversaire, *essai2, *nb1);
        puts("Vous voulez rejouer ? (O/N) ");
        scanf(" %c", &reponse_continu);
        if (reponse_continu == 'o' || reponse_continu == 'O')
        {
            *init = 1; /* On lance l'initialisation du jeu */
        } else if (reponse_continu == 'n' || reponse_continu == 'N'){
            *continuer = 0;
        }
    }
}