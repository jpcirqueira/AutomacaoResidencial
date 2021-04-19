# Projeto 2
Repositório do projeto 2 da disciplina Fundamentos de Sistemas Embarcados, UNB.

Enunciado do projeto disponivel em: https://gitlab.com/fse_fga/projetos_2020_2/projeto-2-2020.2

**Nome**: João Pedro Soares Cirqueira

**Matrícula**: 150132344

## Sistema

![Figura](/imagens/arquitetura.png)

## Executando o projeto

### executando Servidor Distribuido

```sh
$ git clone https://github.com/jpcirqueira/AutomacaoResidencial
$ cd AutomacaoResidencial/servidorDistribuido
$ make
$ cd bin
$ ./run
```
### executando Servidor Central

```sh
$ git clone https://github.com/jpcirqueira/AutomacaoResidencial
$ cd AutomacaoResidencial/servidorCentral
$ make
$ cd bin
$ ./run
```

## Screenshots da execução

![screenshot1](/imagens/screenshot1.jpeg)

![screenshot2](/imagens/screenshot2.jpeg)


## Observações

Os resultados gerados estão sendo gravados em um arquivo .csv disponivel apos a execucao em: ```servidorCentral/data/dados.csv```
https://github.com/jpcirqueira/AutomacaoResidencial/blob/master/servidorCentral/data/dados.csv
