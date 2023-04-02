SocialNetwork este un proiect prin care s-a realizat o aplicatie de socializare in C++ cu afisare
in consola, folosind tipuri de date prin implementare proprie.

Pentru realizarea proiectului am avut de implementat o lista cu
reprezentare pe array si un dictionar cu reprezentare inlantuita.
Primul TAD l-am folosit drept container pentru obiectele de tip Friendship si Message, initializand cate o
lista in clasa RepoInMemory pentru fiecare(friendships si conversations). De asemenea am mai utilizat acest TAD
in cateva functionalitati, returnand datele printr-un container de acest tip.
Al doilea TAD l-am folosit drept container pentru obiectele de tip User(in clasa RepoInMemory). De asemenea,
l-am mai utilizat in functionalitatea "Afisare conversatii utilizatori" pentru ca a fost cea mai eficienta metoda,
atat in organizarea codului, cat si pentru eficienta. Pentru un username dat de la tastaura, se vor cauta mesajele cu
ceilalti utilizatori in retea; cand se va gasi un username cu care s-a conversat, atunci in dictionar se va aduga drept key
numele utilizatorului gasit, si ca valoare, conversatia celor doi.
