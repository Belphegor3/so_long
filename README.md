# SO_LONG

So_long est un projet graphique qui utilise la minilibx[^1] pour cree un petit jeu en 2D.
C est un projet pas tres complique qui met un place un vrai premier systeme de parsing[^2].

## Sommaire

1. [Utilisation](#utilisation)
2. [Jeu](#le-jeu)
3. [Fonctionnement](#fonctionnement)
4. [Definitions](#definitions)

## Utilisation

Il suffit d executer la commande `make` puis de renseigner une map a utiliser en parametre, sachant que certaines existent deja dans le dossier **maps**.  
Le nom de l executable est **so_long**.  
Exemple d utilisation:  
```bash
./so_long maps/subject.ber
```

## Le jeu

[Sommaire](#sommaire)

Il s agit de deplacer le joueur, dans la fenetre ouverte grace a la minilibx[^1], avec les touches **W,A,S,D** du clavier pour recuperer les collectibles a l ecran pour ensuite sortir en rejoignant la sortie.  
On ne peut sortir que si on a ramasse tous les collectibles.  

## Fonctionnement

[Sommaire](#sommaire)
[Map valide](#map-valide)
[Affichage](#affichage-du-jeu)
[Deplacement](#deplacement)
[Defaut](#defaut)

### Map valide

On utilise ici un get_next_line qui nous sert a analyser une par une les lignes du fichier passe en parametre pour verifier si la map est bien valide.  
Une map valide contient:
- une unique sortie qui represente le caractere **E**
- un ou plusieurs collectibles qui representent les caracteres **C**
- un unique joueur qui represente le caractere **P**
- des espaces vides qui sont le background et qui representent les caracteres **0**
- des murs qui representent les caracteres **1**

### Affichage du jeu

Chacun de ces caracteres sont en fait une image.  
Il existe 2 possibilites d afficher directement une image via la minilibx[^1] (sans utiliser les pixels), soit on stocke les donnees de nos 5 images puisqu on est a meme de les reutiliser, soit on les affiche directement. Evidemment il parait beaucoup plus pertinent de les stocker mais par soucis de temps, j'ai choisis de ne pas le faire.  

### Deplacement

Quand le parsing est fait et qu on a bien une map correct, ca devient juste un puzzle. Le *deplacement* du joueur est en fait un echange de 2 images. Si le joueur donc **P** veut se deplacer dans un mur **1**, il ne peut pas donc on ne fait rien mais sinon il suffit de changer la map entierement et remplacer le **P** par un **0** si on veut se deplacer.  
En effet, si on se deplace sur un **C**, on le collecte et donc il disparait. Si on sort en allant sur un **E**, si on le peut, on quitte le jeu et sinon la sortie est consideree comme un mur.

### Defaut

Avec une tres grande map, comme on affiche entierement la map qu on change a chaque deplacement, le jeu sera tres lent voir injouable. Pour palier a ce defaut majeur il aurait suffit de reafficher uniquement les 4 cases autour du **P** sur la map avec la case du **P** aussi evidemment.  
Encore mieux, il aurait fallut stocker les donnees de chaque images pour ne pas avoir a les creer/supprimer a chaque fois qu on veut afficher un caractere.

## Definitions

[SOmmaire](#sommaire)

[^1]: **minilibx** : La minilibx est une bibliothèque graphique simple, faites pour les projets 42 pour travailler avec les fenêtres, les images et les événements. On peut y retrouver toutes les infos sur [42docs](https://harm-smits.github.io/42docs/libs/minilibx).
[^2]: **parsing** : Designe l analyse, la verification et la preparation du code source a etre interprete/compile. 