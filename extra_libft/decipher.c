#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int	main(void)
{
	char	*str;
	int		i;
	char	*res;
	char	aux;

	str = "Rnpu cebwrpg bs gur 97 Pbzzba Pber pbagnvaf na rapbqrq uvag. Sbe rnpu pvepyr,bayl bar cebwrpg cebivqrf gur pbeerpg uvag arrqrq sbe gur arkg pvepyr. Guvf punyyratr vf vaqvivqhny,gurer vf bayl n cevmr sbe bar fghqrag jvaare cebivqvat nyy qrpbqrq zrffntrf. Nal nqinagntrq crbcyr pna cynl, yvxr pheerag be sbezre fgnss, ohg gur cevmr jvyy erznva flzobyvp. Gur uvag sbe guvf svefg cebwrpg vf: Ynetr pbjf trarebfvgl pbzrf jvgu punegf naq sbhe oybaqr ungf gb qrsl hccre tenivgl ureb";
	i = 0;
	aux = 'a';
	while (str[i] != '\0')
	{
		if ((str[i] >= 'a' && str[i] <= 'm') || (str[i] >= 'A'
				&& str[i] <= 'M'))
			aux = *(str + i) + 13;
		else if ((str[i] >= 'n' && str[i] <= 'z') || (str[i] >= 'N'
				&& str[i] <= 'Z'))
			aux = *(str + i) - 13;
		else if ((str[i] >= '0' && str[i] <= '9'))
			aux = ((str[i] - '0' + 4) % 9) + '0';
		else
			aux = str[i];
		printf("%c", aux);
		i++;
	}
	//printf("%lu", strlen(str));
	return (0);
}
/*Each project of the 42 Common Core contains an encoded hint. For each circle,
only one project provides the correct hint needed for the next circle.
This challenge is individual,
	there is only a prize for one student winner providing all decoded messages.
Any advantaged people can play, like current or former staff,
	but the prize will remain symbolic.
The hint for this first project is:
Large cows generosity comes with charts and four blonde hats to defy upper gravity hero*/