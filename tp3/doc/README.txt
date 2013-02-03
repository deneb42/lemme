Compression & decompression lzw
	Jean BADIE & Benjamin BLOIS

Compilation du programme :
Utiliser la commande "make"

Lancement du programme :
Le programme après compilation est situé dans le dossier bin

Pour le lancer utiliser la commande ./lzw

Compresser un fichier : 
Il est possible de compresser un fichier avec la commande ./lzw c chemindufichier
Par exemple pour compresser le fichier big.txt
./lzw c ../data/big.txt

Decompresser un fichier : 
Il est possible de deccompresser un fichier avec la commande ./lzw d chemindufichier
Par exemple pour compresser le fichier out.lzw (générer par la compression précédente)
./lzw d ../data/out.lzw

Lancer le programme sans arguments : 
En appelant le programme avec la simple commande ./lzw le programme va générer et compresser une fractale de Mandelbrot au format gif.

