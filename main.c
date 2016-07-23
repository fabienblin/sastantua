#include <stdio.h>
#include <unistd.h>

int		largeurEtage_i(int i)
{
	if(i == 0)
		return(7);
	return(largeurEtage_i(i - 1) + 2 * (1 + (3 + i) + ((i % 2) + (i / 2))));
}

void	etage(int hauteur, int largeur, int decallage)
{
	int i;
	int j;

	i = 0;
	while(i < hauteur)
	{
		j = -decallage;
		while(j < hauteur - 1 - i)
		{
			write(1, " ", 1);
			j++;
		}
		write(1, "/", 1);
		while(j < largeur - (hauteur + 1 - i))
		{
			write(1, ".", 1);
			j++;
		}
		write(1, "\\", 1);
		write(1, "\n", 1);
		i++;
	}
}

void	sastantua(int size)
{
	int i;
	int hauteur;
	int largeur;
	int decallage;
	int largeurTotale;

	i = 0;
	largeurTotale = largeurEtage_i(size - 1);
	while(i < size)
	{
		hauteur = 3 + i;
		largeur = largeurEtage_i(i);
		decallage = (largeurTotale - largeur) / 2;
		etage(hauteur, largeur, decallage);
		i++;
	}
}

int		main(int argc, char **argv)
{
	sastantua(5);
	return 0;
}
