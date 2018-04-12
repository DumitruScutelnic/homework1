# homework1

# Corso Laboratorio Ciberfisico
- Autore: Dumitru Scutelnic
- Data: 12/04/2018

## Esecuzione file:
Per poter lanciare tutti i nodi in un unico terminale si è implementato un file launch "launch/homework1.launch", eseguibile con 
il comando: 
"roslaunch <nome_packege> homework1.launch"

## Struttura progetto:
- Sono satati implementati tre nodi: talker, listener e controller

### talker.cpp
Il file "talker.cpp" è il nodo che publica un messaggio composto da una stringa con [nome, eta, corso] e manda il messaggio 
al nodo listener tramite il topic "chatter" 

### contoller.cpp
Il file "contoller.cpp" è il nodo che manda il comando tramite il topic "command" composta da un carattere inserito da 
riga di comando, in base al menu stampato a video:

Digita una dei seguenti caratteri per avere informazioni:
‘a’ - Verrà stampato tutto il messaggio
‘n’ - Mostrerà solo il nome
‘e’ - Mostrerà solo l’età
‘c’ - Mostrerà solo il corso di laure
'q' - Exit

### listener.cpp
Il file "listener.cpp" è in nodo che ascolta i topic "chatter" e "command" e filtra il messaggio in base al comando ricevuto 
e pubblica a video la rispetiva parte del messaggio. Nel caso in cui il comando e diverso da quelli del menu scrive "riprova...".

- I messaggi vengono publicati a 1Hz o 1 volta al secondo.

![rosgraph](https://user-images.githubusercontent.com/30594315/38686053-b5879d48-3e73-11e8-8b39-89e505dad305.png)
