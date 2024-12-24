#include <stdio.h>

int i, m, b, j, a = 0, plaka, kontenjan, topkontenjan = 0, partisayi = 6,
  oySayisi[6], toplamPartiOy[6];

int kopyaOy[6], toplamOy, milletvekili[6][6], toplamMV[6];

int milletvekiliKopya[6][6], max = 0, gecici, gecici2;

char geciciHarf, kopyaParti[100];

float iloysayi[6];

char partiler[6] =
{
  'A', 'B', 'C', 'D', 'E', 'F'
};
int plakalar[5];

int main()
{
  do
  {
    //plaka kodu
    printf("Ilin plaka kodunu giriniz:");
    scanf("%d", &plaka);
    while (plaka < 0 || plaka == 0)
    {
      printf("Plaka kodu 0 veya 0 dan küçük olamaz. Tekrar giriniz : ");
      scanf("%d", &plaka);
    }

    while (i == a)
	{
      if (plakalar[i] == plaka)
      {
        printf("Plaka kodu mevcut. Tekrar giriniz :");
        scanf("%d", &plaka);
      }
      i++;
    }

    plakalar[a] = plaka;

    printf("Ilin milletvekili kontenjanini giriniz:");
    scanf("%d", &kontenjan);
    topkontenjan += kontenjan;
    for (i = 0; i < partisayi; i++)
    {
      printf("%c Partisinin Oyunu Giriniz : ", partiler[i]);
      scanf("%d", &oySayisi[i]);
      toplamPartiOy[i] += oySayisi[i];
      toplamOy += oySayisi[i];
      iloysayi[a] += oySayisi[i];
    }
    for (i = 0; i < partisayi; i++)
      kopyaParti[i] = partiler[i];
    for (i = 0; i < partisayi; i++)
      kopyaOy[i] = oySayisi[i];
    for(i =0;i<partisayi;i++){
    	milletvekiliKopya[a][i]=milletvekili[a][i];
	}
	
    sirala(kopyaOy, kopyaParti);
    sirala(oySayisi, partiler);

    MVHesapla();
    printf(
      "Il Plaka Kodu:%d\nMilletvekili Kontenjani:%d\nGecerli Oy Sayisi:%.0f\n",
      plaka, kontenjan, iloysayi[a]);
    printf("\t\tOy Say  Oy Yuzde  MV Say\n");
    printf("\t\t------  --------  ------\n");
    for (i = 0; i < partisayi; i++)
    {
      printf("%c Partisi\t%d\t%.2f\t   %d\n", partiler[i], oySayisi[i], (
        (oySayisi[i] / iloysayi[a]) *100), milletvekili[a][i]);
    }
    printf("Devam etmek icin bir tusa basiniz ... \n");
    getch();
    sifirla(partiler);
    a++;
  }
  
  while (a < 5);
  MVsirala(partiler);
  sirala(toplamMV,partiler);
  printf("\nTurkiye Geneli\n");
  printf("Milletvekili Kontejani: %d\n", topkontenjan);
  printf("Gecerli Oy Sayisi: %d\n\n", toplamOy);
  printf("\t\t    Oy Say  Oy Yuzde  MV Say  MV Yuzde  \n");
  printf("\t\t    ------  --------  ------  --------  \n");


  //milletvekili oran
  for (i = 0; i < partisayi; i++)
  {
    printf("%c Partisi\t\t%d\t%.2f\t%d\t%.2f\n", partiler[i], toplamPartiOy[i],
      (float)toplamPartiOy[i] *100 / toplamOy, toplamMV[i], (float)toplamMV[i] /
      topkontenjan *100);
  }
	printf("Iktidar partisi %c\nAna Muhalefet Partisi %c",partiler[0],partiler[1]);
  return 0;
}

void MVHesapla()
{
  m = kontenjan;
  while (m > 0)
  {
    for (i = 0; i < partisayi; i++)
    {
      if (kopyaOy[i] > max)
      {
        max = kopyaOy[i];
        b=i;
      }
    }
    kopyaOy[b] = kopyaOy[b] / 2;
    max = kopyaOy[b];
    milletvekili[a][b] += 1;
    milletvekiliKopya[a][b]=1;
    toplamMV[b] += milletvekiliKopya[a][b];
    m--;
  }
}

void MVsirala(char c[]){
	  for (i = 0; i < partisayi - 1; i++)
  {
    for (j = 0; j < partisayi - 1; j++)
    {
      if (toplamPartiOy[j] < toplamPartiOy[j + 1])
      {
        geciciHarf = c[j + 1];
        c[j + 1] = c[j];
        c[j] = geciciHarf;

        gecici2 = toplamPartiOy[j];
        toplamPartiOy[j] = toplamPartiOy[j + 1];
        toplamPartiOy[j + 1] = gecici2;
      }
    }
  }
}
void sirala(int oy[], char c[])
{
  for (i = 0; i < partisayi - 1; i++)
  {
    for (j = 0; j < partisayi - 1; j++)
    {
      if (oy[j] < oy[j + 1])
      {
        gecici = milletvekili[a][j + 1];
        milletvekili[a][j + 1] = milletvekili[a][j];
        milletvekili[a][j] = gecici;

        geciciHarf = c[j + 1];
        c[j + 1] = c[j];
        c[j] = geciciHarf;

        gecici2 = oy[j];
        oy[j] = oy[j + 1];
        oy[j + 1] = gecici2;
      }
    }
  }
}

void sifirla(char partiler[])
{
  char orjPartiler[6] =
  {
    'A', 'B', 'C', 'D', 'E', 'F'
  };
  for (i = 0; i < 6; i++)
  {
    partiler[i] = orjPartiler[i];
  }
}
