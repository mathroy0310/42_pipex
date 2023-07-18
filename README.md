# Pipex

Ce document est le fichier README pour le projet Pipex de l'école 42. Pipex est un projet qui consiste à recréer le fonctionnement de la commande shell `|` en utilisant les redirections de fichiers et les tubes (`pipes`). Le but du projet est de développer un programme appelé `pipex` qui exécute une commande sur un fichier d'entrée, puis redirige la sortie vers une autre commande.

## Introduction

Le projet Pipex vise à recréer le comportement de la commande shell `|` en utilisant les redirections de fichiers et les tubes. Le programme `pipex` prendra en entrée une commande et deux fichiers, et il exécutera cette commande en utilisant le premier fichier comme entrée, puis redirigera la sortie vers le second fichier. Il s'agit d'une simulation du fonctionnement interne de la commande `|` en ligne de commande.

## Installation

Pour utiliser ce projet, suivez les étapes suivantes :

1. Clonez ce dépôt sur votre machine locale.
2. Assurez-vous que vous avez le compilateur C installé sur votre système.
3. Exécutez `make` à la racine du projet pour compiler le programme `pipex`.

## Utilisation

Pour utiliser le programme `pipex`, exécutez la commande suivante :

```
./pipex infile cmd1 cmd2 outfile
```

- `infile` : le chemin vers le fichier d'entrée.
- `cmd1` : la première commande à exécuter.
- `cmd2` : la deuxième commande à exécuter.
- `outfile` : le chemin vers le fichier de sortie.

Par exemple :

```
./pipex file1.txt "grep example" "wc -l" file2.txt
```

Le programme exécutera d'abord la commande `grep example` sur le contenu de `file1.txt`, puis redirigera la sortie vers la commande `wc -l`, en enregistrant le résultat final dans `file2.txt`.

## Exemples

Voici quelques exemples d'utilisation du programme `pipex` :

```bash
$ ./pipex file1.txt "grep example" "wc -l" file2.txt
```

```bash
$ ./pipex input.txt "sort" "uniq" output.txt
```

## Ressources

- [Documentation de l'école 42]([fr.subject.pdf](https://cdn.intra.42.fr/pdf/pdf/93078/fr.subject.pdf))

## Auteur

Ce projet a été développé par Mathieu Roy (maroy) dans le cadre du cursus de l'école 42.
