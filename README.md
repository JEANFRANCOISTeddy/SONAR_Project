# Descriptif du projet :

Radar créer à l’aide d’Arduino permettant de détecter ou non la présence d’objet et leur distance par rapport à notre radar dans une zone définie.
Allumage d’une led pour nous avertir qu’un objet est présent.
Mise en place d’algorithme permettant de calculer la distance entre l’objet et le radar.
Le tout affiché sur une application en C avec un sonar en mouvement.

# Fonctionnalités :

-Gestion de fichiers :
Création d’un fichier stockant toutes les signaux captés par le radar, avec l’heure, le jour et la distance.

-Fichier de configuration :
Changer l’angle de recherche (agrandir ou diminuer)

-Détection d’objets :
La carte Arduino va détecter si il y a ou non un objet en face du radar et allume une led

-Affichage d'un objet sur la console :
Suite à la détection de l'objet l’application va afficher sur le graphique sa position.

-Localisation de l’objet :
Une fois détecté nous allons afficher les coordonnées de celui-ci sa distance par rapport au radar ainsi qu’à quelle angle il est situé

-Son :
Emission d’un son lors de la détection d’un objet

-Balayage :
Rotation d’une droite dans l’arc de cercle permettant de détecter sur le graphique où se trouve l’objet

-Récupération des données du port série :
Depuis le port usb nous récupérons les données qui nous sont envoyées par la carte arduino pour ainsi les exploiter dans notre programme et les afficher sur le radar
