pour coder un message texte en message audio morse:
ouvrez votre répertoire de travail, et créez y un fichier .txt contenant le message à coder.
dans le fichier texte, seuls les lettres minuscules et les espaces sont des caractères licites. Signalez la fin du message avec un point d'exclamation.
le programme créera un fichier message_morse.wav contenant le message codé.

pour faire marcher le programme, indiquez dans le code source le path de votre répertoire de travail dans la déclaration de la variable directory_path. indiquez le nom de votre fichier à coder dans la déclaration de la variable fichier_texte.

pour décoder un fichier .wav:
pour faire marcher le programme, indiquez dans le code source le path de votre répertoire de travail dans la déclaration de la variable directory_path. indiquez le nom de votre fichier .wav à décoder dans la déclaration de la variable name_wav.
le programme créera un fichier message_decode.txt contenant le message décodé.

MAKEFILE:
dans le terminal, saisissez la commande
$make codage
pour compiler le fichier codage.cpp, puis saisissez
$./codage
pour coder votre message

saisissez la commande
$make decodage
pour compiler le fichier decodage.cpp, puis saisissez
$./decodage
pour décoder le message

la commande
$make clean 
nettoie le répertoire de tous les fichiers inutiles (ie tous les fichiers sauf les codes sources, les executables, le message d'origine et le message audio final) 

la commande 
$make clean_all 
nettoie entièrement le répertoire: supprime tous les fichiers, sauf le code source, les executables et le message d'origine.

