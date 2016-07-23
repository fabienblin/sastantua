#include <stdio.h>
#include <unistd.h>

void	sastantua(int size);
void	etage(int largeur, int hauteur, int largeurTotale);
int		largeurEtage_i(int i);

int main()
{
	sastantua(4);
	return 0;
}

int		largeurEtage_i(int i)
{
	int	largeur = 1;
	int j = 0;
	
	// largeur = 2*hauteurEtage + 2*(i % 2) + 2*i
}


void	sastantua(int size)
{
	int i;
	int largeur;
	int hauteur;
	int largeurTotale = 1;

	largeur = 1;
	hauteur = 3;
	i = 0;
	while(i < size)
	{
		largeurTotale += 2 * ((i % 2) + hauteur + i);
		i++;
		hauteur++;
	}
	hauteur = 3;
	i = 0;
	printf("largeurTotale = %d\n", largeurTotale);
	while(i < size)
	{
		largeur += 2 * ((i % 2) + hauteur + i);
//		printf("hauteur\t= %d\nlargeur\t= %d\t=\t(mod = %d)\t(angle = %d))\n", hauteur, largeur, (i % 2), (hauteur * 2));
		etage(largeur, hauteur, largeurTotale);
		i++;
		hauteur++;
		
	}
}

void	etage(int largeur, int hauteur, int largeurTotale)
{
	int i;
	int j;
	
	i = 0;
	while(i < hauteur)
	{
		j = 0;
		while(j < (largeurTotale - largeur) / 2)
		{
			write(1, " ", 1);
			j++;
		}
		j = 0;
		while(j < (hauteur - i -1))
		{
			write(1, " ", 1);
			j++;
		}
		j *= 2;
		write(1, "/", 1);
		j+=2;
		while(j < largeur)
		{
			write(1, ".", 1);
			j++;
		}
		write(1, "\\\n", 2);
		i++;
	}
}