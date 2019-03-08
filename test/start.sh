# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    start.sh                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: drestles <drestles@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/06 23:52:30 by pcollio-          #+#    #+#              #
#    Updated: 2019/03/08 19:30:15 by drestles         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PATH_TO_LS="/Users/drestles/Desktop/ft_ls"
CDIR=${PWD}
RESETCOLOR="$(tput sgr0)"
# Couleurs (gras)
ROUGE="$(tput bold ; tput setaf 1)"
VERT="$(tput bold ; tput setaf 2)"
JAUNE="$(tput bold ; tput setaf 3)"
BLEU="$(tput bold ; tput setaf 4)"
CYAN="$(tput bold ; tput setaf 6)"
PRINTDEBUG=1

export PATH_TO_LS
export ROUGE
export VERT
export JAUNE
export BLEU
export CYAN
export RESETCOLOR
export PRINTDEBUG

initdir()
{
	if [ -e testdir ]
	then
		rm -rf testdir
	fi
	mkdir testdir
}

rmout()
{
	rm ft_ls.out
	rm ls.out
}

echo "${VERT}#################################################${RESETCOLOR}"
echo "${VERT}#               ft_ls tester                    #${RESETCOLOR}"
echo "${VERT}#                                               #${RESETCOLOR}"
echo "${VERT}#                                               #${RESETCOLOR}"
echo "${VERT}#                              by : madvil2     #${RESETCOLOR}"
echo "${VERT}#                                               #${RESETCOLOR}"
echo "${VERT}#################################################${RESETCOLOR}"

echo "Compilation >> "
cd ${PATH_TO_LS}
make fclean > /dev/null
make > /dev/null
if [ -e ft_ls ]
then
	echo "${VERT}[OK]${RESETCOLOR} ft_ls found"
else
	echo "${ROUGE}[KO]${RESETCOLOR} ft_ls not found check your makefile"
fi
cd ${CDIR}
initdir
./test.sh
rm -rf testdir
