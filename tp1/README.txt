Badié Jean
Blois Benjamin

Difficultés rencontrées et solutions trouvées :

- Nous avons tout d'abord rencontré une difficulté pour gérer la fonction getNbOccTotal(). En effet cette fonction étant marquée comme constante il nous était impossible d'accéder à la map avec un iterator simple. Cependant après avoir compris le message d'erreur nous avons compris qu'il fallait utiliser un const_iterator ce qui résolve le problème.

- Second problème, fut rencontré en travaillant sur la fonction possedeDocID(string docID), nous avions inversé la condition booléenne, provoquant des erreurs assez incompréhensibles. Cependant avec de nombreux affichages de débug, nous avons trouvé l'origine du problème et réglé ce dernier en inversant la condition.

- Un problème, fut de créer correctement et de manière optimale le vecteur catégories. En effet il n'existe pas de constructeur permettant de définir directement le contenu du vecteur sans passé par un autre tableau, ce qui serait vide de sens.

- Dans la méthode SegmenteSelonSymbole(string str, string symbole), nous avons rencontré une difficulté : Le parseur prenait en compte les espaces et caractères de fin de ligne ainsi que la dernière ligne du fichier qui est vide. Pour franchir cette difficulté nous avons ajouter une condition sur ces caractères.

Amélioration possibles : 

- De nombreuses données sont dupliquées, le nom du lemme (dans la classe lemme et dans la map contenant les lemmes), le nombre nombre de documents contentant le lemme est aussi répété, il peut être récupérer très facilement en regardant le nombre de champs de la map, docID étant la clé de la map (les clé ne peuvent être dupliquées dans une map).

- Le gestion des erreurs pourrait être plus propre en utilisant des exceptions.

- Ne faisant qu'un seul parcours du fichier, la complexité est déjà acceptable, cependant nous pourrions gagné en espace mémoire en utilisant qu'un seul vector.

Ce qui nous a plu/déplu :

Le parsage d'un gros fichier en C++ était une première pour nous, chose que nous avons trouvé intéressante.

L'aspect étude linguistique était également intéressant.

nous n'avons par contre pas apprécié le corpus : il contient des erreurs (chiffres considérés comme des noms) Ce qui fait que les résultats sont moins propres.


