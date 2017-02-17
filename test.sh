#!/bin/bash
#42sh

none='\e[0;m'
white='\e[1;37m'
red='\e[1;31m'
green='\e[1;32m'
darkblue='\e[0;34m'
purple='\e[35m'

echo -e "${red}Tests unitaires 42sh${none}"
echo -e ""
echo -e "${white}Change Directory : ${none}"
echo -e ""
echo -e "${green}Test du cd${none}"
echo -e "Repertoire actuel :" && pwd
echo -e "Commande : cd .." && cd ..
echo -e "Repertoire actuel :" && pwd
echo -e ""
echo -e "${green}Test du cd -${none}" && cd - && cd -
echo -e ""
echo -e "${green}Test du cd ~${none}"
echo -e "Commande : cd ~/PSU_2014_42sh" && cd ~/PSU_2014_42sh
echo -e "Repertoire actuel :" && pwd
echo -e ""
echo -e "${green}Test du cd seul${none}"
echo -e "Commande : cd" && cd
echo -e "Repertoire actuel :" && pwd
cd ~/PSU_2014_42sh
echo -e ""
echo -e "${white}Redirections : ${none}"
echo -e ""
echo -e "${green}Test redirection simple droite${none}"
echo -e "Commande : echo first_test > redir_test" && echo "first_test" > redir_test
echo -e ""
echo -e "${green}Test redirection double droite${none}"
echo -e "Commande : echo second_test >> redir_test" && echo "second_test" >> redir_test
echo -e ""
echo -e "${green}Test redirection simple gauche${none}"
echo -e "Commande : cat < redir_test" && cat < redir_test
echo -e ""
echo -e "${white}Echo${none}"
echo -e ""
echo -e "${green}Test du echo simple :${none}"
echo -e "Commande : echo premier test" && echo "premier test"
echo -e ""
echo -e "${green}Test du echo avec une variable d'environnement :${none}"
echo -e "Commande : echo \$PATH" && echo $PATH
echo -e ""
echo -e "${white}Multi commande${none}"
echo -e ""
echo -e "${green}Test 1${none}"
echo -e "Commande : ls ; pwd" && ls ; pwd
echo -e ""
echo -e "${green}Test 2${none}"
echo -e "Commande : ls ; pwd ; cat auteur : " && ls ; pwd ; cat auteur
echo -e ""
echo -e "${green}Test 3${none}"
echo -e "Commande : ls ; pwd ; cat auteur | cat -e : " && ls ; pwd ; cat auteur | cat -e
echo -e ""
echo -e "${green}Test 4 (sans espace)${none}"
echo -e "Commande : ls;pwd ; cat auteur|cat -e : " && ls;pwd ; cat auteur|cat -e
echo -e ""
echo -e "${white}Pipe${none}"
echo -e ""
echo -e "${green}Pipe simple :${none}"
echo -e "Commande : pwd | cat -e" && pwd | cat -e
echo -e ""
echo -e "${green}Pipe multi :${none}"
echo -e "Commande : cat auteur | cat -e | cat -e | cat -e :" && cat auteur | cat -e | cat -e | cat -e
echo -e ""
echo -e "${white}Test aui marchent mais non possibles en scripts :${none}"
echo -e ""
echo -e "${green}Gestion des segfaults d'un programme${none}"
echo -e "${green}Redirection gauche${none}"
echo -e "${green}exit (avec ou sans valeur de retour)${none}"
