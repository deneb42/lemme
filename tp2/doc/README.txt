Modélisation Metro Parisien
BADIÉ Jean & BLOIS Benjamin

Compiler le programme : 
Le programme est fourni avec un Makefile situé dans le dossier src.

Exécuter le programme : 
Il est possible de lancer le programme depuis le fichier source avec la commande "make run".

Notre programme peut prendre des paramètres en arguments, depuis le dossier bin :
./metro GareDeDepart GareDarrivee TypeD'heure Anomalie TypeD'Anomalie
TypeD'heure : {creuse, normale, pointe}
Anomalie : {oui, non}
TypeD'Anomalie : {station, ligne}, que si Anomalie est à oui.

Ces arguments peuvent etre definis dans le makefile (champ PARAMS), afin d'etre passes 
au programme via "make run"


Nettoyer le programme :
Le Makefile propose deux solutions de nettoyage :
make clean permet de supprimer les fichiers en .o
make mrproper supprime l'ensemble des fichiers crées par le Makefile, les .o et l'exécutable.
