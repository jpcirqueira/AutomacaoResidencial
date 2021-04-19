#include <stdio.h>
#include <time.h>

void criaArquivo()
{
  FILE *f = fopen("../data/dados.csv", "w");
  fprintf(f, "Usuario,Alarme,Data,Hora\n");
  fclose(f);
}

void escreveArquivo(char *usuario, char *alarme)
{
  time_t t = time(NULL);
  struct tm tm = *localtime(&t);
  FILE *f = fopen("../data/dados.csv", "a");
  fprintf(f, "%s,%s,%d/%d/%d, %.2d:%.2d:%.2d\n", usuario, alarme, tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
  fclose(f);
}