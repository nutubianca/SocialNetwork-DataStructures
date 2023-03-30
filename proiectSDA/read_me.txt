Pentru realizarea proiectului am avut de implementat TAD-ul 1 si TAD-ul 4, repsectiv o lista cu
reprezentare pe array si un dictionar su reprezentare inlantuita.
Primul TAD l-am folosit drept container pentru obiectele de tip Friendship si Message, initializand cate o
lista in clasa RepoInMemory pentru fiecare(friendships si conversations). De asemnea am mai utilizat acest TAD
in cateva functionalitati, returnand datele printr-un container de acest tip.
Al doilea TAD l-am folosit drept container pentru obiectele de tip User(in clasa RepoInMemory). De asemenea,
l-am mai utilizat in functionalitatea "Afisare conversatii utilizatori" pentru ca a fost cea mai eficienta metoda,
atat in organizarea codului, cat si pentru eficienta. Pentru un username dat de la tastaura, se vor cauta mesajele cu
ceilalti utilizatori in retea; cand se va gasi un username cu care s-a conversat, atunci in dictionar se va aduga drept key
numele utilizatorului gasit, si ca valoare, conversatia celor doi.